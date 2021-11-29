#include <avr/interrupt.h>

#include "suspend.h"
#include "timer.h"
#include "wait.h"

#include "analog.h"
#include "matrix.h"
#include "keyboard.h"
#include "rgblight.h"

#include "vusb.h"

#include "config.h"

static bool suspended = false;

void platform_setup(void);

static void setup(void) {
    platform_setup();

    keyboard_setup();
}

static void init(void) {
    // Enable interrupt
    sei();

    keyboard_init();

    // Initialize pins
#ifdef UNUSED_PINS
    pin_t unused_pins[] = UNUSED_PINS;
    for (int i = 0; i < sizeof(unused_pins) / sizeof(*unused_pins); ++i) {
        pin_t pin = unused_pins[i];
        if (pin != NO_PIN) {
            setPinOutput(pin);
            writePinLow(pin);
        }
    }
#endif

    // RGB control (PMOS)
    setPinOutput(RGB_CTL_PIN);
    writePinHigh(RGB_CTL_PIN);

    // BAT low control (NMOS)
    setPinOutput(BAT_LOW_PIN);
    writePinLow(BAT_LOW_PIN);

    // BAT volt check control (PMOS)
    setPinOutput(BAT_CHK_PIN);
    writePinHigh(BAT_CHK_PIN);

    // Initialize analog reference mode
    analogReference(ADC_REF_POWER);
}

static void wakeup(void) {
    suspended = false;
    vusb_suspended = false;

    cli();
    wait_ms(25);
    sei();

    suspend_wakeup_init();
}

static void suspend(void) {
    suspended = true;
    vusb_suspended = true;

    suspend_power_down();
}

static void dectect_battery_task(void) {
    static uint16_t last_timestamp = 0;

    if (timer_elapsed(last_timestamp) < 10000) {
        return;
    }

    // Open BAT PMOS switch
    writePinLow(BAT_CHK_PIN);

    last_timestamp = timer_read();

    int16_t adc_value = 0;
    float batt_voltage = 0.f;

    // Read Main BATT voltage
    adc_value = adc_read((_BV(MUX2) | _BV(MUX1))); // ADC6
    batt_voltage = (float)adc_value / 10.24f * 5.f * 2.f;

    if (batt_voltage > 330) {
        writePinLow(BAT_LOW_PIN);
    } else {
        writePinHigh(BAT_LOW_PIN);
    }

#if 0
    // Read LED BATT voltage
    adc_value = adc_read((_BV(MUX2) | _BV(MUX1) | _BV(MUX0))); // ADC7
    batt_voltage = (float)adc_value / 10.24f * 5.f * 2.f;
#endif

    // Close BAT PMOS switch
    writePinHigh(BAT_CHK_PIN);
}

static void rgblight_status_set(bool on)
{
    if (!is_rgblight_initialized)
        return;

    if (on) {
        writePinLow(RGB_CTL_PIN);
        HSV hsv = rgblight_get_hsv();
        rgblight_sethsv_noeeprom(hsv.h, hsv.s, hsv.v);
    } else {
        writePinHigh(RGB_CTL_PIN);
    }
}

static void task(void) {
#ifdef RGBLIGHT_ENABLE
    static bool rgblight_enabled = false;
#endif

    keyboard_task();

#ifdef RGBLIGHT_ENABLE
    if (rgblight_enabled != rgblight_is_enabled()) {
        rgblight_enabled = rgblight_is_enabled();
        rgblight_status_set(rgblight_enabled);
    }
#endif
}

static void loop_task(void) {
    static uint16_t last_timer = 0;

    if (rgblight_is_enabled()) {
        last_timer = timer_read();
    } else {
        if (!suspended
            && timer_elapsed(last_timer) > 3000) {
            suspend();
        }
    }

    if (suspended) {
        suspend();

        if (suspend_wakeup_condition()) {
            wakeup();

            last_timer = timer_read();
        }
    } else {
        task();
    }

    dectect_battery_task();
}

int main(void) {
    setup();

    init();

    /* Main loop */
    while (true) {
        loop_task();
    }
}

// Override bootmagic_lite
void bootmagic_lite(void) {
#if 0
    matrix_scan();
#if defined(DEBOUNCE) && DEBOUNCE > 0
    wait_ms(DEBOUNCE * 2);
#else
    wait_ms(30);
#endif
    matrix_scan();

    // If the configured key (commonly Esc) is held down on power up,
    // reset the EEPROM valid state and jump to bootloader.
    // This isn't very generalized, but we need something that doesn't
    // rely on user's keymaps in firmware or EEPROM.
    uint8_t row = BOOTMAGIC_LITE_ROW;
    uint8_t col = BOOTMAGIC_LITE_COLUMN;

    if (matrix_get_row(row) & (1 << col)) {
        bootmagic_lite_reset_eeprom();

        // Jump to bootloader.
        bootloader_jump();
    }
#endif
}

// Override matrix scans
#ifdef DIRECT_PINS
// Override matrix direct pins
static pin_t direct_pins_[MATRIX_ROWS][MATRIX_COLS] = DIRECT_PINS;

void matrix_init_pins(void) {
    for (int row = 0; row < MATRIX_ROWS; row++) {
        for (int col = 0; col < MATRIX_COLS; col++) {
            pin_t pin = direct_pins_[row][col];
            if (pin != NO_PIN) {
                setPinInputHigh(pin);
            }
        }
    }
}

void matrix_read_cols_on_row(matrix_row_t current_matrix[], uint8_t current_row) {
    // Start with a clear matrix row
    matrix_row_t current_row_value = 0;

    for (uint8_t col_index = 0; col_index < MATRIX_COLS; col_index++) {
        pin_t pin = direct_pins_[current_row][col_index];

        if (suspended
            && pin != WAK_CTL_PIN) {
            continue;
        }

        if (pin != NO_PIN) {
            current_row_value |= readPin(pin) ? 0 : (MATRIX_ROW_SHIFTER << col_index);
        }
    }

    // Update the matrix
    current_matrix[current_row] = current_row_value;
}
#endif
