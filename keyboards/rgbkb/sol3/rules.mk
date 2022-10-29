# MCU name
MCU = STM32F303

# Bootloader selection
BOOTLOADER = stm32-dfu

# Touch encoder needs
VPATH += keyboards/rgbkb/common
SRC += touch_encoder.c
SRC += common_oled.c
QUANTUM_LIB_SRC += i2c_master.c

# Build Options
BOOTMAGIC_ENABLE = lite     # Enable Bootmagic Lite
NKRO_ENABLE = yes           # Enable N-Key Rollover
AUDIO_ENABLE = yes          # Audio output
AUDIO_DRIVER = dac_additive # Audio output
DIP_SWITCH_ENABLE = yes     # The Sol3 has dip switches, but I'm not 100% if this feature is actually needed.
                            # Leaving it enabled until I know exactly if it's necessary (ie: it will stay enabled forever).

# Features that make me go "neat!", but I probably won't actually end up ever using
MOUSEKEY_ENABLE = no        # Mouse keys
DYNAMIC_MACRO_ENABLE = no	# Create macros ad-hoc

# Features I probably won't ever use
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration


# RGB Lighting
WS2812_DRIVER = pwm
RGBLIGHT_ENABLE = no
RGB_MATRIX_ENABLE = yes
RGB_MATRIX_DRIVER = WS2812

# Display Module
OLED_ENABLE = yes
OLED_DRIVER = SSD1306    # Enable the OLED Driver

# Encoders
ENCODER_ENABLE = no

# Other Features
SPLIT_KEYBOARD = yes
SERIAL_DRIVER = usart
LTO_ENABLE = yes # Link-Time Optimization
OPT = 3

OPT_DEFS += -DOLED_FONT_H=\"keyboards/rgbkb/common/glcdfont.c\"

DEFAULT_FOLDER = rgbkb/sol3/rev1
