/* Copyright 2023 Andrew Hess <handrew@duck.com> */

#include QMK_KEYBOARD_H
#include "keymap_steno.h"

// Layer IDs.
#define LAYER_STENO         0
#define LAYER_SWITCH        1
#define LAYER_GAMING        2
#define LAYER_MOUSE         3
#define LAYER_MEDIA         4
#define LAYER_TEST          5
#define LAYER_ALPHA_1       6
#define LAYER_ALPHA_2       7
#define LAYER_SYMBOLS       8

// Layer aliases.
#define STN LAYER_STENO
#define SWC LAYER_SWITCH
#define GMG LAYER_GAMING
#define MSE LAYER_MOUSE
#define MED LAYER_MEDIA
#define AL1 LAYER_ALPHA_1
#define AL2 LAYER_ALPHA_2
#define SYM LAYER_SYMBOLS

// Create the actual layers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_STENO] = LAYOUT(
        XXXXXXX, STN_S1,  STN_TL,  STN_PL,  STN_HL,                    STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        TO(SWC), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_NUM, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                            STN_A,   STN_O,   STN_E,   STN_U
    ),
    [LAYER_SWITCH] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        TO(LAYER_TEST), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(AL1), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            TO(GMG), TO(MSE), TO(MED), TO(STN)
    ),
    [LAYER_GAMING] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, KC_W,    XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        TO(SWC), KC_LSFT, KC_A,    KC_S,    KC_D,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        TO(SWC), XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,
                                            KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX
    ),
    [LAYER_MEDIA] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_SLEP,
        TO(SWC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RIGHT, KC_LEFT, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX
    ),
    [LAYER_TEST] = LAYOUT(
        KC_A, KC_B,  KC_C,  KC_D,  KC_E,                    KC_F,  KC_G,  KC_H,  KC_I,  KC_J,
        TO(SWC), KC_K,  KC_L,  KC_M,  KC_N,  KC_O, KC_P, KC_Q,  KC_R,  KC_S,  KC_T,  KC_U,
                                            KC_V,   KC_W,   KC_X,   KC_Y
    ),
    [LAYER_ALPHA_1] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_L,    KC_R,    KC_M,                      KC_U,    KC_F,    KC_D,    XXXXXXX, XXXXXXX,
        TO(SWC), KC_O,    KC_S,    KC_N,    KC_T, OSM(MOD_LGUI), OSM(MOD_RSFT), KC_E,    KC_A,    KC_H,    KC_I,    XXXXXXX,
                                            KC_SPACE, KC_C,   KC_W,    OSL(AL2)
    ),
    [LAYER_ALPHA_2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, KC_J,                      KC_Q,    KC_DOT,  KC_COMM, XXXXXXX, XXXXXXX,
        TO(SWC), KC_X,    KC_P,    KC_V,    KC_G,    XXXXXXX, XXXXXXX, KC_Y,    KC_K,    KC_B,    KC_Z,    XXXXXXX,
                                            KC_BACKSPACE, KC_TAB, KC_ESC, KC_ENTER
    ),
    [LAYER_SYMBOLS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        TO(SWC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    // A blank layer commented out, just to make adding new layers a little easier.
    // [] = LAYOUT(
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //     TO(SWC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    // ),
};
