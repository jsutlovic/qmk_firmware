#include QMK_KEYBOARD_H

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _BL 0
#define _FL 1
#define _GAME 2

#define SPCFN LT(_FL, KC_SPC)

// Macro defns
enum {
    TB_PREV = SAFE_RANGE,
    TB_NEXT,
    SP_PREV,
    SP_NEXT,
    OS_CYCL,
    OS_PRNT,
    OS_PRNTL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Keymap _BL: (Base Layer) Default Layer
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Ent |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|Play|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |       SpaceFn         |Alt|Win|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_BL] = LAYOUT_ansi(
  KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,   KC_BSPC, KC_ESC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  KC_LCTL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,        KC_ENT,  KC_PENT, \
  KC_LSFT,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,     KC_RSFT,KC_UP,  KC_MPLY, \
  KC_LCTL, KC_LGUI,KC_LALT,                     SPCFN,                      KC_RALT,KC_RGUI, KC_NO ,KC_LEFT,KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |Esc|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Prnt|
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |PgU|   |Sp<|Tb<|Tb>|Sp>|   |   |     |Ins |
   * |----------------------------------------------------------------|
   * |      |   |   |   |   |PgD| < | v | ^ | > |   |   |        |End |
   * |----------------------------------------------------------------|
   * |        |   |   |Bl-|BL |BL+|Spc|MUT|VO-|VO+|   |     |Cycl|    |
   * |----------------------------------------------------------------|
   * |     |    |    |                      |   |   |   |Prev|Prt|Next|
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_ansi(
  KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7, KC_F8 , KC_F9 , KC_F10 ,KC_F11,KC_F12,   KC_DEL ,OS_PRNT,  \
  _______,_______,_______,_______,_______,KC_PGUP,_______,SP_PREV,TB_PREV,TB_NEXT,SP_NEXT,_______,_______, _______, KC_INS, \
  _______   ,_______,_______,_______,_______,KC_PGDN,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______,_______,        _______, KC_END, \
  _______     ,_______,_______,BL_DEC,BL_TOGG,BL_INC, KC_SPC,KC_MUTE,KC_VOLD,KC_VOLU,_______,     _______, OS_CYCL, _______, \
  _______,_______,_______,                _______                       , _______,_______,_______,KC_MPRV,OS_PRNTL, KC_MNXT),

  /* Keymap _GAME: (Base Layer) Game Layer - no SpaceFn
   * ,----------------------------------------------------------------.
   * |~ ` | 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|Backsp |Esc |
   * |----------------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|  \  |Del |
   * |----------------------------------------------------------------|
   * |Ctrl   |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |Ent |
   * |----------------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | Up|Play|
   * |----------------------------------------------------------------|
   * |Ctrl|Win |Alt |        Space          |Alt|Win|Ctrl|Lef|Dow|Rig |
   * `----------------------------------------------------------------'
   */
[_GAME] = LAYOUT_ansi(
  KC_GRV, KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,   KC_BSPC, KC_ESC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  KC_LCTL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,        KC_ENT,  KC_PENT, \
  KC_LSFT,         KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM,KC_DOT,KC_SLSH,    KC_RSFT,KC_UP,  KC_MPLY, \
  KC_LCTL, KC_LGUI,KC_LALT,                      KC_SPC,                    KC_RALT,KC_RGUI,KC_RCTRL,KC_LEFT,KC_DOWN, KC_RGHT),

};


#define OS_COUNT 3
#define OS_LENGTH 10
#define OS_LINUX 0
#define OS_WIN 1
#define OS_MAC 2
#define OS_SWITCH_FLASH_DELAY 100

static unsigned char os_layer = 0;
static char os_names[OS_COUNT][OS_LENGTH] = {
    "Linux",
    "Windows",
    "macOS",
};

typedef union {
    uint32_t raw;
    struct {
        unsigned char current_os :3;
    };
} user_config_t;

user_config_t user_config;

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    os_layer = user_config.current_os;
}

void eeconfig_init_user(void) {
    // EEPROM has been reset, set defaults here
}

void flash_backlight(void) {
    if (is_backlight_enabled()) {
        backlight_toggle();
    } else {
        backlight_level(BACKLIGHT_LEVELS);
    }
    wait_ms(OS_SWITCH_FLASH_DELAY);
    backlight_toggle();
}

// Combos
enum combo_events {
    BL_SWITCH,
};

const uint16_t PROGMEM switch_combo[] = {KC_LGUI, KC_RGUI, COMBO_END};

combo_t key_combos[COMBO_COUNT] = {
    [BL_SWITCH] = COMBO_ACTION(switch_combo),
};

void process_combo_event(uint8_t combo_index, bool pressed) {
    if (!pressed) return;
    switch(combo_index) {
        case BL_SWITCH:
            if (layer_state_is(_GAME)) {
                layer_clear();
                PORTB |= (1<<2);
            } else {
                layer_move(_GAME);
                PORTB &= ~(1<<2);
            }
            flash_backlight();
            break;
    }
}


bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (!record->event.pressed) return true;
    switch (keycode) {
        case SP_PREV:
            switch (os_layer) {
                case OS_LINUX:
                    SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_H))));
                    break;
                case OS_MAC:
                    SEND_STRING(SS_LCTRL(SS_TAP(X_LEFT)));
                    break;
                case OS_WIN:
                    SEND_STRING(SS_LGUI(SS_LCTRL(SS_TAP(X_LEFT))));
                    break;
            }
            break;
        case SP_NEXT:
            switch (os_layer) {
                case OS_LINUX:
                    SEND_STRING(SS_LGUI(SS_LALT(SS_TAP(X_L))));
                    break;
                case OS_MAC:
                    SEND_STRING(SS_LCTRL(SS_TAP(X_RIGHT)));
                    break;
                case OS_WIN:
                    SEND_STRING(SS_LGUI(SS_LCTRL(SS_TAP(X_RIGHT))));
                    break;
            }
            break;
        case TB_PREV:
            switch (os_layer) {
                case OS_LINUX:
                case OS_WIN:
                    SEND_STRING(SS_LCTRL(SS_TAP(X_PGUP)));
                    break;
                case OS_MAC:
                    SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_LBRACKET))));
                    break;
            }
            break;
        case TB_NEXT:
            switch (os_layer) {
                case OS_LINUX:
                case OS_WIN:
                    SEND_STRING(SS_LCTRL(SS_TAP(X_PGDOWN)));
                    break;
                case OS_MAC:
                    SEND_STRING(SS_LGUI(SS_LSFT(SS_TAP(X_RBRACKET))));
                    break;
            }
            break;
        case OS_CYCL:
            if (record->event.pressed) {
                os_layer++;
                if (os_layer >= OS_COUNT) os_layer = 0;
                user_config.current_os = os_layer;
                flash_backlight();
            }
            return false;
            break;
        case OS_PRNT:
            if (record->event.pressed) {
                send_string((char[]) {'1' + os_layer, '\0'});
            }
            return false;
            break;
        case OS_PRNTL:
            if (record->event.pressed) {
                send_string(os_names[os_layer]);
            }
            return false;
            break;
    }
    return true;
}
