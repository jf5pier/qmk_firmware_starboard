// Copyright 2023 Andrew Hess (@Andrew Hess)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT


// Setup taipo following instructions at https://github.com/dlip/qmk_firmware/blob/chouchou/users/dlip/taipo.md
#define TAIPO_TAP_TIMEOUT 50
#define ONESHOT_TIMEOUT 1500

// Setup the LED on the microcontroller.
#define WS2812_PIO_USE_PIO1 // Force the usage of PIO1 peripheral, by default the WS2812 implementation uses the PIO0 peripheral
#define WS2812_BYTE_ORDER WS2812_BYTE_ORDER_GRB
// #define RGB_MATRIX_DEFAULT_VAL 32
#define WS2812_DI_PIN GP23 // The pin connected to the data pin of the LEDs
#define RGBLED_NUM 1

#define RGBLIGHT_SLEEP
