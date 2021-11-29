# MCU name
MCU = atmega328p

# Bootloader selection
BOOTLOADER = usbasploader

BOOTMAGIC_ENABLE = no         # Enable Bootmagic Lite
MOUSEKEY_ENABLE  = no         # Mouse keys
EXTRAKEY_ENABLE  = no         # Audio control and System control
CONSOLE_ENABLE   = no         # Console for debug
COMMAND_ENABLE   = no         # Commands for debug and configuration
NKRO_ENABLE      = no         # USB Nkey Rollover
BACKLIGHT_ENABLE = no         # Enable keyboard backlight functionality
RGBLIGHT_ENABLE  = yes        # Enable keyboard RGB underglow
AUDIO_ENABLE     = no         # Audio output
ENCODER_ENABLE   = no         # Rotary encoder support

SRC += main.c
SRC += analog.c
