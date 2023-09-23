/* Copyright 2023 Andrew Hess <handrew@duck.com> */

#include QMK_KEYBOARD_H
#include "keymap_steno.h"

#include "users/dlip/custom_keycodes.h"
// #include "users/dlip/taipo.h"  // Not needed because I copy-pasted the code from taipo.c a bit lower

#define DEBUG 0 // 1 for debug mode, 0 otherwise.

// Layer IDs.
#define LAYER_STENO         14
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
#define LAYER_TAIPO         0


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
    [LAYER_STENO] = LAYOUT(
        TO(ARW), STN_S1,  STN_TL,  STN_PL,  STN_HL,                    STN_FR,  STN_PR,  STN_LR,  STN_TR,  STN_DR,
        TO(SWC), STN_S2,  STN_KL,  STN_WL,  STN_RL,  STN_NUM, STN_ST4, STN_RR,  STN_BR,  STN_GR,  STN_SR,  STN_ZR,
                                            STN_A,   STN_O,   STN_E,   STN_U
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
    [LAYER_TAIPO] = LAYOUT(
        XXXXXXX, TP_TLP,  TP_TLR,  TP_TLM,  TP_TLI,                    TP_TRI,  TP_TRM,  TP_TRR,  TP_TRP,  XXXXXXX,
        XXXXXXX, TP_BLP,  TP_BLR,  TP_BLM,  TP_BLI,  XXXXXXX, XXXXXXX, TP_BRI,  TP_BRM,  TP_BRR,  TP_BRP,  TO(SWC),
                                            TP_LIT,  TP_LOT,  TP_ROT,  TP_RIT
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

// Right hand top row, left to right: i n s r
// Right hand bot row, left to right: e t o a

#define r 1 << 0
#define s 1 << 1
#define n 1 << 2
#define i 1 << 3
#define a 1 << 4
#define o 1 << 5
#define t 1 << 6
#define e 1 << 7
#define it 1 << 8
#define ot 1 << 9

static uint16_t determine_key(uint16_t val) {
    switch (val) {
        // Zero fingers.
        case it:
            return KC_BSPC;
        case ot:
            return KC_SPC;

        // One finger.
        case i:
            return KC_E;
        case i | ot:
            return S(KC_E);
        case i | it:
            return KC_DOT;

        case n:
            return KC_W;
        case n | ot:
            return S(KC_W);
        case n | it:
            return KC_UP;

        case s:
            return KC_V;
        case s | ot:
            return S(KC_V);
        case s | it:
            return KC_COMMA;

        case e:
            return KC_D;
        case e | ot:
            return S(KC_D);
        case e | it:
            return KC_RIGHT;

        case t:
            return KC_S;
        case t | ot:
            return S(KC_S);
        case t | it:
            return KC_DOWN;

        case o:
            return KC_A;
        case o | ot:
            return S(KC_A);
        case o | it:
            return KC_LEFT;

        case a:
            return KC_Z;
        case a | ot:
            return S(KC_Z);
        case a | it:
            return KC_TAB;
        case a | it | ot:
            return S(KC_TAB);


        // Two fingers.
        case i | n:
            return KC_T;
        case i | n | ot:
                return S(KC_T);
        case i | n | it:
            return KC_LEFT_PAREN;
        case i | n | it | ot:
            return KC_RIGHT_PAREN;

        case i | s:
            return KC_N;
        case i | s | ot:
            return S(KC_N);
        case i | s | it:
            return KC_EQUAL;
        case i | s | it | ot:
            return KC_UNDERSCORE;

        // case i | e:
        //     return KC_NO;

        case i | t:
            return KC_H;
        case i | t | ot:
            return S(KC_H);
        case i | t | it:
            return KC_BACKSLASH;

        case i | o:
            return KC_R;
        case i | o | ot:
            return S(KC_R);
        case i | o | it:
            return KC_PIPE;
        case i | o | it | ot:
            return KC_AMPERSAND;

        case i | a:
            return KC_L;
        case i | a | ot:
            return S(KC_L);
        case i | a | it:
            return KC_AT;
        case i | a | it | ot:
            return KC_HASH;


        case n | s:
            return KC_O;
        case n | s | ot:
            return S(KC_O);
        case n | s | it:
            return KC_LEFT_CURLY_BRACE;
        case n | s | it | ot:
            return KC_RIGHT_CURLY_BRACE;

        case n | e:
            return KC_C;
        case n | e | ot:
            return S(KC_C);
        case n | e | it:
            return KC_SLASH;
        case n | e | it | ot:
            return KC_ASTERISK;

        // case n | t:
        //     return KC_NO

        case n | o:
            return KC_U;
        case n | o | ot:
            return S(KC_U);
        case n | o | it:
            return KC_MINUS;
        case n | o | it | ot:
            return KC_PLUS;

        case n | a:
            return KC_M;
        case n | a | ot:
            return S(KC_M);
        case n | a | it:
            return KC_DOLLAR;


        case s | e:
            return KC_K;
        case s | e | ot:
            return S(KC_K);

        // case s | t:
        //     return KC_NO
        // case s | o:
        //     return KC_NO
        // case s | a:
        //     return KC_NO

        case e | t:
            return KC_F;
        case e | t | ot:
            return S(KC_F);
        case e | t | it:
            return KC_LEFT_BRACKET;
        case e | t | it | ot:
            return KC_RIGHT_BRACKET;

        case e | o:
            return KC_G;
        case e | o | ot:
            return S(KC_G);
        case e | o | it:
            return KC_QUOTE;
        case e | e | it | ot:
            return KC_DOUBLE_QUOTE;

        case e | a:
            return KC_Y;
        case e | a | ot:
            return S(KC_Y);
        case e | a | it:
            return KC_SEMICOLON;
        case e | a | it | ot:
            return KC_COLON;


        case t | o:
            return KC_I;
        case t | o | ot:
            return S(KC_I);
        case t | o | it:
            return KC_LEFT_ANGLE_BRACKET;
        case t | o | it | ot:
            return KC_RIGHT_ANGLE_BRACKET;

        case t | a:
            return KC_Q;
        case t | a | ot:
            return S(KC_Q);
        case t | a | it:
            return KC_QUESTION;
        case t | a | it | ot:
            return KC_EXCLAIM;

        // case o | a:
        //     return KC_NO

        // Three fingers
        case i | n | s:
            return KC_B;
        case  i | n | s| ot:
            return S(KC_B);
        case  i | n | s| it:
            return KC_GRAVE;

        case e | t | o:
            return KC_ENTER;
        case  e | t | o | it:
                return S(KC_ESC);

        case e | n | s:
            return KC_P;
        case  e | n | s| ot:
            return S(KC_P);
        case  e | n | s| it:
            return KC_TILDE;

        case i | t | o:
            return KC_X;
        case  i | t | o| ot:
            return S(KC_X);
        case  i | t | o| it:
            return KC_PERCENT;

        case e | n | o:
            return KC_J;
        case  e | n | o| ot:
            return S(KC_J);
        case  e | n | o| it:
            return KC_CIRCUMFLEX; // The ^ symbol.


    }
    return KC_NO;
}

// static void handle_key(keypress* key) {
//     uint8_t mods = 0;
//     switch (key->keycode) {
//         case KC_MOD_GA:
//             mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT);
//             break;
//         case KC_MOD_GC:
//             mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL);
//             break;
//         case KC_MOD_GS:
//             mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LSFT);
//             break;
//         case KC_MOD_AC:
//             mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL);
//             break;
//         case KC_MOD_AS:
//             mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT);
//             break;
//         case KC_MOD_CS:
//             mods = MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
//             break;
//         case KC_MOD_GAC:
//             mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL);
//             break;
//         case KC_MOD_GAS:
//             mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LSFT);
//             break;
//         case KC_MOD_GCS:
//             mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
//             break;
//         case KC_MOD_ACS:
//             mods = MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
//             break;
//         case KC_MOD_GACS:
//             mods = MOD_BIT(KC_LGUI) | MOD_BIT(KC_LALT) | MOD_BIT(KC_LCTL) | MOD_BIT(KC_LSFT);
//             break;
//         case KC_LGUI:
//         case KC_LALT:
//         case KC_RALT:
//         case KC_LCTL:
//         case KC_LSFT:
//             mods = MOD_BIT(key->keycode);
//             break;
//         // case KC_LAYER0:
//         //     layer_move(0);
//         //     clear_all_state();
//         //     break;
//         // case KC_LAYER1:
//         //     layer_move(1);
//         //     clear_all_state();
//         //     break;
//         // case KC_LAYER2:
//         //     layer_move(2);
//         //     clear_all_state();
//         //     break;
//         // case KC_LAYER3:
//         //     layer_move(3);
//         //     clear_all_state();
//         //     break;
//         default:
//             if (key->hold_handled) {
//                 unregister_code16(key->keycode);
//             } else if (key->hold) {
//                 register_code16(key->keycode);
//                 key->hold_handled = true;
//             } else {
//                 tap_code16(key->keycode);
//             }
//     }
//     if (mods) {
//         if (key->hold_handled) {
//             del_mods(mods);
//             send_keyboard_report();
//         } else if (key->hold) {
//             add_mods(mods);
//             send_keyboard_report();
//             key->hold_handled = true;
//         } else {
//             add_oneshot_mods(mods);
//         }
//     }
// }

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
}

/////////////////////
// From instructions at https://github.com/dlip/qmk_firmware/blob/chouchou/users/dlip/taipo.md
/////////////////////

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (IS_LAYER_ON(LAYER_TAIPO)) {
        return taipo_process_record_user(keycode, record);
    }  else {
        return true;
    }
};

void matrix_scan_user(void) {
    taipo_matrix_scan_user();
}