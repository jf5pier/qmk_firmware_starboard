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
#define ONESHOT_TIMEOUT 500
