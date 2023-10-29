/* Copyright 2023 Andrew Hess <handrew@duck.com> */

#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#include "users/dlip/custom_keycodes.h"
// #include "users/dlip/taipo.h"  // Not needed because I copy-pasted the code from taipo.c a bit lower

#define DEBUG 0 // 1 for debug mode, 0 otherwise.

// Layer IDs.
#define LAYER_TAIPO         0
#define LAYER_SWITCH        1
#define LAYER_GAMING_1      2
#define LAYER_GAMING_2      3
#define LAYER_GAMING_3      4
#define LAYER_MOUSE         5
#define LAYER_MEDIA         6
#define LAYER_TEST          7
#define LAYER_ALPHA_1       8
#define LAYER_ALPHA_2       9
#define LAYER_SYMBOLS       10
#define LAYER_QWERTY_1      11
#define LAYER_QWERTY_2      12
#define LAYER_ARROWS        13
#define LAYER_STENO         14


// Layer aliases.
#define STN LAYER_STENO
#define SWC LAYER_SWITCH
#define GM1 LAYER_GAMING_1
#define GM2 LAYER_GAMING_2
#define GM3 LAYER_GAMING_3
#define MSE LAYER_MOUSE
#define MED LAYER_MEDIA
#define TST LAYER_TEST
#define AL1 LAYER_ALPHA_1
#define AL2 LAYER_ALPHA_2
#define SYM LAYER_SYMBOLS
#define QW1 LAYER_QWERTY_1
#define QW2 LAYER_QWERTY_2
#define ARW LAYER_ARROWS
#define TPO LAYER_TAIPO

// Create the actual layers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_TAIPO] = LAYOUT(
        XXXXXXX, TP_TLP,  TP_TLR,  TP_TLM,  TP_TLI,                    TP_TRI,  TP_TRM,  TP_TRR,  TP_TRP,  XXXXXXX,
        XXXXXXX, TP_BLP,  TP_BLR,  TP_BLM,  TP_BLI,  XXXXXXX, XXXXXXX, TP_BRI,  TP_BRM,  TP_BRR,  TP_BRP,  TO(SWC),
                                            TP_LIT,  TP_LOT,  TP_ROT,  TP_RIT
     ),
    [LAYER_SWITCH] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        TO(TST), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(AL1), TO(QW1), TO(TPO), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            TO(GM1), TO(MSE), TO(MED), TO(STN)
    ),
    [LAYER_GAMING_1] = LAYOUT(
        KC_O,    KC_F,    KC_LCTL, KC_W,    KC_LSFT,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_TAB,  KC_SPC,  KC_A,    KC_S,    KC_D,     KC_ENT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(SWC),
                                            OSL(GM2), OSL(GM3), XXXXXXX, XXXXXXX
    ),
    [LAYER_GAMING_2] = LAYOUT(
        KC_P,    KC_Z,    KC_X,    KC_C,    KC_V,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        KC_L,    KC_Q,    KC_M,    KC_E,    KC_R,    KC_T,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(SWC),
                                            KC_ESC,  KC_LGUI, XXXXXXX, XXXXXXX
    ),
    [LAYER_GAMING_3] = LAYOUT(
        KC_9,    KC_8,    KC_7,    KC_6,    KC_5,                      XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_4,    KC_3,    KC_2,    KC_1,    KC_0,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, TO(SWC),
                                            KC_LSFT, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_MOUSE] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_WH_U, KC_MS_U, KC_WH_D,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_MS_L, KC_MS_D, KC_MS_R, XXXXXXX, XXXXXXX, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, TO(SWC),
                                            KC_BTN1, KC_BTN2, XXXXXXX, XXXXXXX
    ),
    [LAYER_MEDIA] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, KC_SLEP,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_RIGHT, KC_LEFT, XXXXXXX, XXXXXXX, TO(SWC),
                                            XXXXXXX, XXXXXXX, KC_MPLY, XXXXXXX
    ),
    [LAYER_TEST] = LAYOUT(
        KC_A,    KC_B,    KC_C,    KC_D,    KC_E,                      KC_F,    KC_G,    KC_H,    KC_I,    KC_J,
        TO(SWC), KC_K,    KC_L,    KC_M,    KC_N,    KC_O,    KC_P,    KC_Q,    KC_R,    KC_S,    KC_T,    KC_U,
                                            KC_V,    KC_W,    KC_X,    KC_Y
    ),
    [LAYER_ALPHA_1] = LAYOUT(
        XXXXXXX, XXXXXXX, KC_L,    KC_R,    KC_M,                      KC_U,    KC_F,    KC_D,    XXXXXXX, XXXXXXX,
        XXXXXXX, KC_O,    KC_S,    KC_N,    KC_T, OSM(MOD_LGUI), OSM(MOD_RSFT), KC_E,    KC_A,    KC_H,    KC_I,    TO(SWC),
                                            KC_SPACE, KC_C,   KC_W,    OSL(AL2)
    ),
    [LAYER_ALPHA_2] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, KC_QUOT, KC_J,                      KC_Q,    KC_DOT,  KC_COMM, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_X,    KC_P,    KC_V,    KC_G,    XXXXXXX, XXXXXXX, KC_Y,    KC_K,    KC_B,    KC_Z,    XXXXXXX,
                                            KC_BACKSPACE, KC_TAB, KC_ESC, KC_ENTER
    ),
    [LAYER_SYMBOLS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_QWERTY_1] = LAYOUT(
        OSM(MOD_LGUI), KC_Q,    KC_W,    KC_E,    KC_R,                      KC_U,    KC_I,    KC_O,    KC_P,    XXXXXXX,
        OSM(MOD_LSFT), KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, TO(SWC),
                                            KC_SPACE, OSL(QW2), OSM(MOD_LCTL), KC_ENTER
    ),
    [LAYER_QWERTY_2] = LAYOUT(
        _______, XXXXXXX, XXXXXXX, XXXXXXX, KC_T,                      KC_Y,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        _______, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, XXXXXXX,
                                            KC_BACKSPACE, KC_TAB, KC_ESC, KC_ENTER
    ),
    [LAYER_ARROWS] = LAYOUT(
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LALT, KC_LSFT, KC_LGUI, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_RIGHT, XXXXXXX, TO(SWC),
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_STENO] = LAYOUT(
        TO(ARW), STN_S1,  STN_TL,  STN_PL,  STN_HL,                    STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        TO(SWC), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_NUM, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                            STN_A,   STN_O,   STN_E,   STN_U
    ),

    // A blank layer commented out, just to make adding new layers a little easier.
    // [] = LAYOUT(
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    //                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    // ),
};

void custom_debug(char *str) {
    if (DEBUG) {
        send_string(str);
    }
}

void custom_warn(char *str) {
    send_string("WARN ");
    send_string(str);
}


/////////////////////
// Copied from taipo.c
/////////////////////

#ifndef TAIPO_TAP_TIMEOUT
#define TAIPO_TAP_TIMEOUT 150
#endif

#define pu 1 << 0
#define ru 1 << 1
#define mu 1 << 2
#define iu 1 << 3
#define pd 1 << 4
#define rd 1 << 5
#define md 1 << 6
#define id 1 << 7
#define it 1 << 8
#define ot 1 << 9

static uint16_t determine_key(uint16_t val) {
    switch (val) {
        // Zero fingers.
        case it:
            return A(KC_BACKSPACE);
        case ot:
            return KC_SPC;

        // One finger.
        case iu:
            return KC_E;
        case iu | it:
            return KC_T;
        case iu | ot:
            return KC_H;
        case iu | it | ot:
            return KC_R;

        case mu:
            return KC_W;
        case mu | it:
            return KC_I;
        case mu | ot:
            return KC_L;
        case mu | it | ot:
            return KC_F;

        case ru:
            return KC_Y;
        case ru | it:
            return KC_Q;
        // case ru | ot:
            // return KC_;
        // case ru | it | ot:
            // return KC_;

        case pu:
            return KC_BACKSPACE;
        case pu | it:
            return G(KC_BACKSPACE);
        // case pu | ot:
        //     return KC_;
        // case pu | it | ot:
        //     return KC_;

        case id:
            return KC_D;
        case id | it:
            return KC_O;
        case id | ot:
            return KC_N;
        case id | it | ot:
            return KC_M;

        case md:
            return KC_S;
        case md | it:
            return KC_U;
        case md | ot:
            return KC_C;
        case md | it | ot:
            return KC_G;

        case rd:
            return KC_A;
        case rd | it:
            return KC_P;
        case rd | ot:
            return KC_B;
        case rd | it | ot:
            return KC_K;

        case pd:
            return KC_Z;
        case pd | it:
            return KC_V;
        case pd | ot:
            return KC_X;
        case pd | it | ot:
            return KC_J;

        // Two fingers.
        case iu | mu:
            return KC_LEFT_PAREN;
        case iu | mu | it:
            return KC_LEFT_CURLY_BRACE;
        case iu | mu | ot:
            return KC_LEFT_BRACKET;
        case iu | mu | it | ot:
            return KC_LEFT_ANGLE_BRACKET;

        case id | md:
            return KC_RIGHT_PAREN;
        case id | md | it:
            return KC_RIGHT_CURLY_BRACE;
        case id | md | ot:
            return KC_RIGHT_BRACKET;
        case id | md | it | ot:
            return KC_RIGHT_ANGLE_BRACKET;

        case mu | ru:
            return KC_DOT;
        case mu | ru | it:
            return KC_COMMA;
        case mu | ru | ot:
            return KC_EXCLAIM;
        case mu | ru | it | ot:
            return KC_QUESTION;

        case md | rd:
            return KC_QUOTE;
        case md | rd | it:
            return KC_DOUBLE_QUOTE;
        case md | rd | ot:
            return KC_SEMICOLON;
        case md | rd | it | ot:
            return KC_COLON;

        // Three fingers.
        case id | md | rd:
            return KC_ENTER;
        case id | md | rd | it:
            return KC_ESCAPE;

        // One modifier.
        case iu | id:
            return KC_LGUI;
        case mu | md:
            return KC_LCTL;
        case ru | rd:
            return KC_LSFT;
        case pu | pd:
            return KC_LALT;

        // Two modifiers.
        case iu | id | mu | md:
            return KC_MOD_GC;
        case iu | id | ru | rd:
            return KC_MOD_GS;
        case iu | id | pu | pd:
            return KC_MOD_GA;

        case mu | md | ru | rd:
            return KC_MOD_CS;
        case mu | md | pu | pd:
            return KC_MOD_AC;

        case ru | rd | pu | pd:
            return KC_MOD_AS;

        // Three modifiers.
        case iu | id | mu | md | ru | rd:
            return KC_MOD_GCS;
        case iu | id | mu | md | pu | pd:
            return KC_MOD_GAC;
        case iu | id | ru | rd | pu | pd:
            return KC_MOD_GCS;
        case mu | md | ru | rd | pu | pd:
            return KC_MOD_ACS;

        // Four modifiers.
        case iu | id | mu | md | ru | rd | pu | pd:
            return KC_MOD_GACS;
    }
    return KC_NO;
}

static uint8_t get_mods_from_keycode(uint16_t keycode) {
    uint8_t mods = 0;
    switch (keycode) {
        case KC_MOD_GA:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT);
            break;
        case KC_MOD_GC:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL);
            break;
        case KC_MOD_GS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_AC:
            mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL);
            break;
        case KC_MOD_AS:
            mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_CS:
            mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_GAC:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL);
            break;
        case KC_MOD_GAS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_GCS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_ACS:
            mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_MOD_GACS:
            mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
            break;
        case KC_LGUI:
        case KC_LALT:
        case KC_RALT:
        case KC_LCTL:
        case KC_LSFT:
            mods = MOD_BIT(keycode);
            break;
        default:
            return 0;
    }

    return mods;
    // if (mods) {
    //     if (key->hold_handled) {
    //         del_mods(mods);
    //         send_keyboard_report();
    //     } else if (key->hold) {
    //         add_mods(mods);
    //         send_keyboard_report();
    //         key->hold_handled = true;
    //     } else {
    //         add_oneshot_mods(mods);
    //     }
    // }
}

/////////////////////
// Custom code
/////////////////////

struct combo {
    uint16_t combo; // Bitwise OR of the keys pressed. Each key is `keycode - TP_TLP`.
    uint16_t keycode; // The actual keycode this combo sends.
};

#define MAX_HELD_COMBOS 5 // This MUST be at least 2 to avoid null reference errors.

struct combo_node {
    struct combo combo;
    struct combo_node* prev;
    struct combo_node* next;
};

struct combo_node_pool {
    struct combo_node combo_nodes[MAX_HELD_COMBOS];
    bool in_use[MAX_HELD_COMBOS];
};

struct held_combos {
    struct combo_node* root;
    struct combo_node* head;
};

struct state {
    struct held_combos held_combos;
    struct combo_node_pool combo_node_pool;
    uint16_t timer;
    uint16_t in_progress_combo;
};

static struct state left_state;
static struct state right_state;
static uint16_t modifiers_set_time;

void remove_all_mods(void) {
    // Clear any modifiers.
    if (get_mods() != 0) {
        clear_mods();
        send_keyboard_report();
        rgblight_sethsv(10, 255, 50);
    }
}

// Note: if no more elements are available, this deactivates the longest-held
// combo and recycles it (by returning it).
struct combo_node* get_combo_node_from_pool(struct state* state) {
    for (int k = 0; k < MAX_HELD_COMBOS; k++) {
        if (!state->combo_node_pool.in_use[k]) {
            state->combo_node_pool.in_use[k] = true;
            return &state->combo_node_pool.combo_nodes[k];
        }
    }

    // All elements are in use. So deactivate the longest-held combo and return
    // that element.
    struct combo_node* node = state->held_combos.root;
    state->held_combos.root = node->next;
    state->held_combos.root->prev = NULL;
    unregister_code16(node->combo.keycode);
    node->prev = NULL;
    node->next = NULL;

    return node;
}

void add_held_combo(struct state* state, uint16_t combo, uint16_t keycode) {
    uint8_t mods = get_mods_from_keycode(keycode);
    if (mods != 0) {
        add_mods(mods);
        send_keyboard_report();
        rgblight_sethsv(10, 100, 50);
        modifiers_set_time = timer_read();
        return;
    }

    struct combo_node* node = get_combo_node_from_pool(state);
    node->combo.combo = combo;
    node->combo.keycode = keycode;

    if (state->held_combos.root == NULL) {
        state->held_combos.root = node;
        node->prev = NULL;
    }
    if (state->held_combos.head != NULL) {
        state->held_combos.head->next = node;
    }

    node->prev = state->held_combos.head;
    node->next = NULL;
    state->held_combos.head = node;

    register_code16(keycode);
    remove_all_mods();
}

// combo_bit is a one-hot number.
void remove_held_combo(struct state* state, uint16_t combo_bit) {
    struct combo_node* cur = state->held_combos.root;
    if (cur == NULL) {
        custom_debug("cur is null");
    }

    while (cur != NULL) {
        if (cur->combo.combo & combo_bit) {
            // Release this combo.
            custom_debug("released");
            unregister_code16(cur->combo.keycode);

            // Remove this combo from the list.
            // TODO: mutex the following code down to the return.
            if (state->held_combos.root == cur) {
                state->held_combos.root = cur->next;
            }
            if (state->held_combos.head == cur) {
                state->held_combos.head = cur->prev;
            }
            if (cur->next != NULL) {
                cur->next->prev = cur->prev;
            }
            if (cur->prev != NULL) {
                cur->prev->next = cur->next;
            }

            // TODO: use address arithmetic to remove this loop.
            for (int k = 0; k < MAX_HELD_COMBOS; k++) {
                if (&state->combo_node_pool.combo_nodes[k] == cur) {
                    state->combo_node_pool.in_use[k] = false;
                    return;
                }
            }

            // We shouldn't get here.
            custom_warn("did not find node");
        }

        cur = cur->next;
    }

    custom_debug("already released");

    // The combo for this key was already released, so don't do anything.
    return;
}


bool taipo_process_record_user(uint16_t keycode, keyrecord_t* record) {
    uint16_t key = keycode - TP_TLP;
    uint16_t combo_bit = (1 << (key % 10));
    struct state* state = (key / 10) ? &right_state : &left_state;

    if (record->event.pressed) {
        if (state->in_progress_combo == 0) {
            // Start the timer; once the timer ends, this combo will be processed
            // and cannot be added to.
            state->timer = (record->event.time + TAIPO_TAP_TIMEOUT) | 1;
        }

        state->in_progress_combo |= combo_bit;
    } else {
        custom_debug("key up");
        remove_held_combo(state, combo_bit);
    }

    return false;
}

void process_state(struct state* state) {
    if (state->timer > 0 && timer_expired(timer_read(), state->timer)) {
        // Activate the in-progress combo, if it's valid.
        uint16_t keycode = determine_key(state->in_progress_combo);
        if (keycode != KC_NO) {
            custom_debug("calling add_held_combo");
            add_held_combo(state, state->in_progress_combo, keycode);
        }

        // Reset the in-progress combo.
        state->timer = 0;
        state->in_progress_combo = 0;
    }
}

void taipo_matrix_scan_user(void) {
    process_state(&left_state);
    process_state(&right_state);

    if (timer_read() - modifiers_set_time > 1000) { // In milliseconds
        remove_all_mods();
    }
}

/////////////////////
// From instructions at https://github.com/dlip/qmk_firmware/blob/chouchou/users/dlip/taipo.md
/////////////////////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(LAYER_TAIPO)) {
        if (keycode == TO(SWC)) {
            return true;
        }

        return taipo_process_record_user(keycode, record);
    }  else {
        return true;
    }
};

void matrix_scan_user(void) {
    taipo_matrix_scan_user();
}

// Set LED per layer.
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case LAYER_TAIPO:
            rgblight_sethsv(10, 255, 50);
            break;
        default:
            rgblight_sethsv(96, 255, 30);
            break;
    }

    return state;
}

// Set LED color to the color for the default layer on startup.
void keyboard_post_init_user(void) {
    rgblight_enable();
    rgblight_sethsv(10, 255, 50);
}
