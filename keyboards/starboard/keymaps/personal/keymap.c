/* Copyright 2023 Andrew Hess <handrew@duck.com> */

#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#include "users/dlip/custom_keycodes.h"

#define DEBUG 0 // 1 for debug mode, 0 otherwise.

// Layer IDs.
#define LAYER_ALPHA_1       0
#define LAYER_ALPHA_2       1
#define LAYER_PUNCTUATION   2
#define LAYER_SYMBOLS       3
#define LAYER_COMMANDS      4
#define LAYER_ARROWS        5
#define LAYER_NUMBERS       6
#define LAYER_FKEYS         7
#define LAYER_TAIPO         8
#define LAYER_STENO         9

#define LAYER_SWITCH        10


// Layer aliases.
#define TPO LAYER_TAIPO
#define STN LAYER_STENO
#define AL1 LAYER_ALPHA_1
#define AL2 LAYER_ALPHA_2
#define PNC LAYER_PUNCTUATION
#define NUM LAYER_NUMBERS
#define ARW LAYER_ARROWS
#define SYM LAYER_SYMBOLS
#define FKY LAYER_FKEYS
#define CMD LAYER_COMMANDS
#define SWC LAYER_SWITCH

enum extra_keycodes {
    EK_QU = SAFE_RANGE + 100, // Don't overwrite the taipo custom keycodes.
    EK_EXPAND,
};

enum combos {
  CB_EXPAND,
};

const uint16_t PROGMEM dt_combo[] = {KC_D, KC_T, COMBO_END};

combo_t key_combos[] = {
  [CB_EXPAND] = COMBO(dt_combo, EK_EXPAND),
};

// Create the actual layers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [LAYER_ALPHA_1] = LAYOUT(
        TO(SWC),       C(KC_B),   KC_C,    KC_H,    KC_D,                      KC_U,    KC_I,    KC_L,    KC_TAB,  OSM(MOD_LALT),
        OSM(MOD_LCTL), KC_M,      KC_R,    KC_N,    KC_T,    KC_W,    KC_F,    KC_E,    KC_A,    KC_O,    KC_S,    OSM(MOD_LGUI),
                                            OSL(CMD), OSL(AL2), KC_SPC, OSM(MOD_LSFT)
    ),
    [LAYER_ALPHA_2] = LAYOUT(
        TO(SWC), XXXXXXX, XXXXXXX, KC_Y,    KC_B,                      KC_Z,    EK_QU,   KC_Q,    XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_G,    KC_J,    KC_P,    XXXXXXX, XXXXXXX, KC_K,    KC_V,    KC_X,    XXXXXXX, XXXXXXX,
                                            MO(ARW), XXXXXXX, MO(PNC), MO(SYM)
    ),
    [LAYER_PUNCTUATION] = LAYOUT(
        TO(SWC), KC_LABK, KC_LBRC, KC_LCBR, KC_LPRN,                   KC_RPRN, KC_RCBR, KC_RBRC, KC_RABK, XXXXXXX,
        KC_BSPC, KC_EXLM, KC_SCLN, KC_QUOT, KC_COMM,  KC_ESC, KC_ENTER, KC_DOT, KC_DQUO, KC_COLN, KC_QUES, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_SYMBOLS] = LAYOUT(
        TO(SWC), KC_PERC, KC_DLR,  KC_AT,   KC_AMPR,                   KC_PIPE, KC_HASH, KC_CIRC, KC_TILD, XXXXXXX,
        XXXXXXX, KC_UNDS, KC_ASTR, KC_EQL,  KC_SLSH, XXXXXXX, XXXXXXX, KC_BSLS, KC_EXLM, KC_PLUS, KC_MINS, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_COMMANDS] = LAYOUT(
        TO(SWC), G(KC_A), G(KC_W), G(KC_S), G(KC_F),                   G(KC_R), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, G(KC_Z), G(KC_X), G(KC_C), G(KC_V), G(KC_SPC), XXXXXXX, G(KC_N), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, MO(ARW), MO(NUM)
    ),
    [LAYER_ARROWS] = LAYOUT(
        TO(SWC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   KC_TAB,  S(KC_TAB), KC_Q,  XXXXXXX, XXXXXXX,
        XXXXXXX, KC_LCTL, KC_LSFT, KC_LALT, KC_LGUI, XXXXXXX, KC_BSPC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_NUMBERS] = LAYOUT(
        TO(SWC), XXXXXXX, KC_6,    KC_5,    KC_4,                          XXXXXXX,       XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, KC_3,    KC_2,    KC_1,    LGUI_T(KC_0), XXXXXXX, XXXXXXX, RGUI_T(KC_7), KC_8,    KC_9,    KC_GRV, XXXXXXX,
                                            XXXXXXX,      XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_FKEYS] = LAYOUT(
        TO(SWC), XXXXXXX, KC_F6,   KC_F5,   KC_F4,                     KC_F10,  KC_F11,  KC_F12,  XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, KC_F3,   KC_F2,   KC_F1,   XXXXXXX, XXXXXXX, KC_F7,   KC_F8,   KC_F9,   XXXXXXX, XXXXXXX,
                                            XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
    ),
    [LAYER_TAIPO] = LAYOUT(
        TO(SWC), TP_TLP,  TP_TLR,  TP_TLM,  TP_TLI,                    TP_TRI,  TP_TRM,  TP_TRR,  TP_TRP,  XXXXXXX,
        XXXXXXX, TP_BLP,  TP_BLR,  TP_BLM,  TP_BLI,  XXXXXXX, XXXXXXX, TP_BRI,  TP_BRM,  TP_BRR,  TP_BRP,  TO(SWC),
                                            TP_LIT,  TP_LOT,  TP_ROT,  TP_RIT
     ),
    [LAYER_STENO] = LAYOUT(
        TO(SWC), STN_S1,  STN_TL,  STN_PL,  STN_HL,                    STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        TO(ARW), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_NUM, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                            STN_A,   STN_O,   STN_E,   STN_U
    ),

    [LAYER_SWITCH] = LAYOUT(
        TO(SWC), XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
        XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                            TO(TPO), TO(STN), TO(AL1), XXXXXXX
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

void process_combo_event(uint16_t combo_index, bool pressed) {
  send_string("doing combo");
  switch(combo_index) {
    case CB_EXPAND:
      if (pressed) {
        SEND_STRING("john.doe@example.com");
      }
      break;
  }
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

#define EXPAND_MAX_KEYS 100
struct expand_state {
    char keys_pressed[EXPAND_MAX_KEYS];
    uint16_t keys_pressed_index;
    uint16_t last_key_press_time;
} expand_state;

// Make an array of strings where the key are the keys that were pressed and the values are the strings to expand to.
typedef struct key_value {
    char* key;
    char* value;
} key_value;

key_value expansions[] = {
    {"hw", "Hello, world!"},
    {"wo", "without"},
};

void process_expand(void) {
    // Iterate all the expansions.
    // TODO: make this more efficient.
    size_t expansions_size = sizeof(expansions) / sizeof(expansions[0]);
    for (int i = 0; i < expansions_size; i++) {
        if (strlen(expansions[i].key) != expand_state.keys_pressed_index) {
            continue;
        }

        // Iterate all the keys pressed.
        bool match = true;
        for (int k = 0; k < expand_state.keys_pressed_index; k++) {
            if (expansions[i].key[k] != expand_state.keys_pressed[k]) {
                match = false;
                break;
            }
        }

        if (match) {
            // Erase the keys pressed, then send the expansion.
            for (int k = 0; k < expand_state.keys_pressed_index; k++) {
                tap_code(KC_BACKSPACE);
            }
            send_string(expansions[i].value);
            break;
        }
    }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(LAYER_TAIPO)) {
        if (keycode == TO(SWC)) {
            return true;
        }

        return taipo_process_record_user(keycode, record);
    }

    switch (keycode) {
    case EK_QU:
        if (record->event.pressed) {
            send_string("qu");
        }
    case EK_EXPAND:
        if (record->event.pressed) {
            process_expand();
        }
    }

    // Clear the expand state when the spacebar is pressed.
    if (keycode == KC_SPACE || keycode == EK_EXPAND) {
        expand_state.keys_pressed_index = 0;
    } else {
        // Add the keycode to the expand state, if it's a letter.
        if (keycode >= KC_A && keycode <= KC_Z && record->event.pressed) {
            char ch = keycode - KC_A + 'a';

            // Wrap around if we've reached the end of the array.
            if (expand_state.keys_pressed_index >= EXPAND_MAX_KEYS) {
                expand_state.keys_pressed_index = 0;
            }

            expand_state.keys_pressed[expand_state.keys_pressed_index] = ch;
            expand_state.keys_pressed_index++;
            expand_state.last_key_press_time = timer_read();
        }
    }

    return true;
};

void matrix_scan_user(void) {
    if (IS_LAYER_ON(LAYER_TAIPO)) {
        taipo_matrix_scan_user();
    }

    // If the expand timer is up, reset the expand state.
    if (timer_read() - expand_state.last_key_press_time > 3000) { // In milliseconds
        expand_state.keys_pressed_index = 0;
    }
}

// Set LED per layer.
layer_state_t layer_state_set_user(layer_state_t state) {
    switch (get_highest_layer(state)) {
        case LAYER_TAIPO:
            rgblight_sethsv(10, 255, 50);
            break;
        case LAYER_STENO:
            rgblight_sethsv(20, 255, 50);
            break;
        case LAYER_ALPHA_1:
            rgblight_sethsv(160, 180, 50);
            break;
        case LAYER_ALPHA_2:
            rgblight_sethsv(160, 180, 50);
            break;
        case LAYER_PUNCTUATION:
            rgblight_sethsv(50, 255, 50);
            break;
        case LAYER_NUMBERS:
            rgblight_sethsv(60, 255, 50);
            break;
        case LAYER_ARROWS:
            rgblight_sethsv(95, 235, 50);
            break;
        case LAYER_SYMBOLS:
            rgblight_sethsv(80, 255, 50);
            break;
        case LAYER_FKEYS:
            rgblight_sethsv(90, 255, 50);
            break;
        case LAYER_COMMANDS:
            rgblight_sethsv(100, 255, 50);
            break;
        case LAYER_SWITCH:
            rgblight_sethsv(110, 225, 50);
        default:
            rgblight_sethsv(0, 255, 30);
            break;
    }

    return state;
}

// Set LED color to the color for the default layer on startup.
void keyboard_post_init_user(void) {
    rgblight_enable();
    rgblight_sethsv(160, 180, 50);

}
