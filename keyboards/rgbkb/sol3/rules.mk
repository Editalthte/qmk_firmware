# Documentation: https://github.com/qmk/qmk_firmware/tree/master/docs

# MCU name (ie: the actual microcontroller hardware name/make/model)
MCU = STM32F303

# Bootloader selection
BOOTLOADER = stm32-dfu # https://qmk.fm/changes/2017-11-17-qmk-dfu-bootloader-generation

# Touch encoder needs -- Not currently using any touch encoder on this keyboard, however.
VPATH += keyboards/rgbkb/common
SRC += touch_encoder.c
SRC += common_oled.c
QUANTUM_LIB_SRC += i2c_master.c

# Build Options
SPLIT_KEYBOARD = yes        # https://github.com/qmk/qmk_firmware/blob/master/docs/feature_split_keyboard.md
SERIAL_DRIVER = usart       # Drives the Split Keyboard: https://github.com/qmk/qmk_firmware/blob/master/docs/serial_driver.md
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite: https://qmk.github.io/qmk_mkdocs/master/en/feature_bootmagic/
NKRO_ENABLE = yes           # Enable N-Key Rollover: https://github.com/qmk/qmk_firmware/blob/master/docs/usb_nkro.txt
AUDIO_ENABLE = yes          # Audio output
AUDIO_DRIVER = dac_additive # Audio output
DIP_SWITCH_ENABLE = yes     # The Sol3 has dip switches, but I'm not 100% if this feature is actually needed.
                            # Leaving it enabled until I know exactly if it's necessary (ie: it will stay enabled forever).

# Features that make me go "neat!", but I probably won't actually end up ever using
MOUSEKEY_ENABLE = no        # Mouse keys
DYNAMIC_MACRO_ENABLE = no	# Create macros ad-hoc
ENCODER_ENABLE = no

# Features I probably won't ever use
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration


# RGB Lighting
WS2812_DRIVER = pwm
RGBLIGHT_ENABLE = no        # RGBLIGHT is disabled as we don't use that subsystem directly.
RGB_MATRIX_ENABLE = yes     # Instead we have to use RGB_MATRIX, as an external driver is handling the RGB already.
RGB_MATRIX_DRIVER = WS2812  # The external driver being used.

# Display Module
OLED_ENABLE = yes
OLED_DRIVER = SSD1306

# Other Configurations
LTO_ENABLE = yes            # Link-Time Optimization
OPT = 3                     # ?????
OPT_DEFS += -DOLED_FONT_H=\"keyboards/rgbkb/common/glcdfont.c\"
DEFAULT_FOLDER = rgbkb/sol3/rev1