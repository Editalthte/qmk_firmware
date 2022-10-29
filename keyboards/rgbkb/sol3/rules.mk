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
#   change yes to no to disable
#
BOOTMAGIC_ENABLE = lite      # Enable Bootmagic Lite
MOUSEKEY_ENABLE = no        # Mouse keys
EXTRAKEY_ENABLE = no        # Audio control and System control
CONSOLE_ENABLE = no         # Console for debug
COMMAND_ENABLE = no         # Commands for debug and configuration
NKRO_ENABLE = yes           # Enable N-Key Rollover
AUDIO_ENABLE = yes          # Audio output
AUDIO_DRIVER = dac_additive # Audio output

DYNAMIC_MACRO_ENABLE = yes
DIP_SWITCH_ENABLE = yes

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
