#pragma once

/* Bootmagic Lite key configuration */
#define BOOTMAGIC_LITE_ROW             6
#define BOOTMAGIC_LITE_COLUMN          1

/* VIA related config */
#define DYNAMIC_KEYMAP_LAYER_COUNT     2
#define VIA_EEPROM_LAYOUT_OPTIONS_SIZE 2

/* Underglow - Fix unknown USB device */
#define RGB_DI_PIN                     A0
#define RGBLED_NUM                     10
#define WS2812_PWM_DRIVER              PWMD5
#define WS2812_PWM_CHANNEL             1
#define WS2812_PWM_PAL_MODE            2
#define WS2812_DMA_STREAM              STM32_DMA1_STREAM6
#define WS2812_DMA_CHANNEL             6
