/*
 * ----------------------------------------------------------------------------
 * "THE BEER-WARE LICENSE" (Revision 42):
 * <https://github.com/Legonut> wrote this file.  As long as you retain this
 * notice you can do whatever you want with this stuff. If we meet some day, and
 * you think this stuff is worth it, you can buy me a beer in return. David Rauseo
 * ----------------------------------------------------------------------------
 */

#pragma once

#define STM32_ONBOARD_EEPROM_SIZE 2048

// == RGB Configurations == //

// No need for the single versions when multi performance isn't a problem =D
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#undef ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#undef ENABLE_RGB_MATRIX_SPLASH
#undef ENABLE_RGB_MATRIX_SOLID_SPLASH

// RGB Timeout
// 20m timeout (20m * 60s * 1000mil)
// const int ONE_MILLISECOND = 1;
// const int ONE_SECOND = ONE_MILLISECOND * 1000;
// const int ONE_MINUTE = ONE_SECOND * 60;
// const int TWENTY_MINUTES = ONE_MINUTE * 20;
// const int TIMEOUT = TWENTY_MINUTES;
// #define RGB_DISABLE_TIMEOUT TIMEOUT

#define RGB_DISABLE_WHEN_USB_SUSPENDED


// RGB Default behavior/values
// #define RGB_MATRIX_STARTUP_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT  // Sets the default mode, if none has been set
// #define RGB_MATRIX_STARTUP_HUE 0                             // Sets the default hue value, if none has been set
// #define RGB_MATRIX_STARTUP_SAT 255                           // Sets the default saturation value, if none has been set
// #define RGB_MATRIX_STARTUP_VAL RGB_MATRIX_MAXIMUM_BRIGHTNESS // Sets the default brightness value, if none has been set
// #define RGB_MATRIX_STARTUP_SPD 127                           // Sets the default animation speed, if none has been set
// #define RGB_MATRIX_SPLIT { X, Y } 	                        // (Optional) For split keyboards, the number of LEDs connected on each half. X = left, Y = Right.
                              		                            // If RGB_MATRIX_KEYPRESSES or RGB_MATRIX_KEYRELEASES is enabled, you also will want to enable SPLIT_TRANSPORT_MIRROR