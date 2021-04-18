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
    WN_PREV,
    WN_NEXT,
    OS_CYCL,
    OS_PRNT,
    OS_PRNTL,
    J_DBG,
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
[_BL] = LAYOUT_65_ansi(
  KC_GESC,KC_1,   KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_MINS, KC_EQL,   KC_BSPC, KC_ESC, \
  KC_TAB,  KC_Q,   KC_W,   KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,   KC_O,   KC_P,   KC_LBRC, KC_RBRC, KC_BSLS, KC_DEL, \
  KC_LCTL,  KC_A,   KC_S,   KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,   KC_L,   KC_SCLN, KC_QUOT,        KC_ENT,  KC_PENT, \
  KC_LSFT,      KC_Z,   KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,   KC_COMM, KC_DOT, KC_SLSH,     KC_RSFT,KC_UP,  KC_MPLY, \
  KC_LCTL, KC_LGUI,KC_LALT,                     SPCFN,                      KC_RALT,KC_RGUI, KC_NO ,KC_LEFT,KC_DOWN, KC_RGHT),

  /* Keymap _FL: Function Layer
   * ,----------------------------------------------------------------.
   * |Esc|F1 |F2 |F3 |F4 |F5 |F6 |F7 |F8 |F9 |F10|F11|F12|Del    |Prnt|
   * |----------------------------------------------------------------|
   * |     |   |   |   |   |PgU|   |Sp<|Tb<|Tb>|Sp>|Wn<|Wn>|     |Ins |
   * |----------------------------------------------------------------|
   * |      |SA+|SA-|   |   |PgD| < | v | ^ | > |   | ` |        |End |
   * |----------------------------------------------------------------|
   * |        |HUE|MOD|BR-|RGB|BR+|Spc|MUT|VO-|VO+|   |     |Cycl|    |
   * |----------------------------------------------------------------|
   * |RESET|REEP|    |                      |DBG|   |   |Prev|Prt|Next|
   * `----------------------------------------------------------------'
   */
[_FL] = LAYOUT_65_ansi(
  KC_ESC , KC_F1 , KC_F2 , KC_F3 , KC_F4 , KC_F5 , KC_F6 , KC_F7, KC_F8 , KC_F9 , KC_F10 ,KC_F11,KC_F12,   KC_DEL ,OS_PRNT,  \
  _______,_______,_______,_______,_______,_______,KC_PGUP,SP_PREV,TB_PREV,TB_NEXT,SP_NEXT,WN_PREV,WN_NEXT, _______, KC_INS, \
  _______   ,RGB_SAI,RGB_SAD,_______,_______,KC_PGDN,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,_______, KC_GRV,        _______, KC_END, \
  _______     ,RGB_HUI,RGB_MOD,RGB_VAD,RGB_TOG,RGB_VAI, KC_SPC,KC_MUTE,KC_VOLD,KC_VOLU,_______,     _______, OS_CYCL, _______, \
  RESET  ,EEP_RST,_______,                _______                       ,     J_DBG,_______,_______,KC_MPRV,OS_PRNTL, KC_MNXT),

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
[_GAME] = LAYOUT_65_ansi(
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
#define OS_SWITCH_FLASH_DELAY 200

static unsigned char os_layer = 0;
static char os_names[OS_COUNT][OS_LENGTH] = {
    "Linux",
    "Windows",
    "macOS",
};
char rgb_debug_str[24];

typedef union {
    uint32_t raw;
    struct {
        unsigned char current_os :3;
    };
} user_config_t;

user_config_t user_config;

void rgb_matrix_indicators_user(void)
{
    if (IS_LED_ON(host_keyboard_leds(), USB_LED_CAPS_LOCK))
    {
        rgb_matrix_set_color(8, 0xFF, 0xFF, 0xFF);
    }

    if (!g_suspend_state && rgb_matrix_config.enable) {
        switch (biton32(layer_state)) {
            case _BL:
            case _FL:
                switch (os_layer) {
                    case OS_LINUX:
                        rgb_matrix_set_color(35, 3,6,7);
                        break;
                    case OS_WIN:
                        rgb_matrix_set_color(35, 0,5,7);
                        break;
                    case OS_MAC:
                        rgb_matrix_set_color(35, 7,3,7);
                        break;
                    default:
                        // Error
                        rgb_matrix_set_color(35, 10,0,0);
                        break;
                }
                break;
            case _GAME:
                rgb_matrix_set_color(42, 10,0,0);
                rgb_matrix_set_color(65, 10,0,0);
                break;
        }
    }
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
    os_layer = user_config.current_os;
}

void eeconfig_init_user(void) {
    // EEPROM has been reset, set defaults here
    rgb_matrix_enable_noeeprom();
    rgb_matrix_sethsv_noeeprom(136, 96, 52);
    rgb_matrix_sethsv_noeeprom(136, 255, 20);
    rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    user_config.current_os = 0;
}

void flash_backlight(void) {
    uint8_t mode = rgb_matrix_config.mode;
    if (mode == RGB_MATRIX_NONE) {
        rgb_matrix_sethsv_noeeprom(0,0,255);
        rgb_matrix_mode_noeeprom(RGB_MATRIX_SOLID_COLOR);
    } else {
        rgb_matrix_mode_noeeprom(RGB_MATRIX_NONE);
    }
    wait_ms(OS_SWITCH_FLASH_DELAY);
    rgb_matrix_mode_noeeprom(mode);
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
                /* PORTB |= (1<<2); */
            } else {
                layer_move(_GAME);
                /* PORTB &= ~(1<<2); */
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
        case WN_PREV:
            switch (os_layer) {
                case OS_LINUX:
                    SEND_STRING(SS_LGUI(SS_TAP(X_H)));
                    break;
                case OS_WIN:
                    SEND_STRING(SS_LALT(SS_LSFT(SS_TAP(X_TAB))));
                    break;
            }
            break;
        case WN_NEXT:
            switch (os_layer) {
                case OS_LINUX:
                    SEND_STRING(SS_LGUI(SS_TAP(X_L)));
                    break;
                case OS_WIN:
                    SEND_STRING(SS_LALT(SS_TAP(X_TAB)));
                    break;
            }
            break;
        case OS_CYCL:
            if (record->event.pressed) {
                os_layer++;
                if (os_layer >= OS_COUNT) os_layer = 0;
                user_config.current_os = os_layer;
                eeconfig_update_user(user_config.raw);
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
                if (os_layer >= OS_COUNT) {
                    send_string("Error!");
                } else {
                    send_string(os_names[os_layer]);
                }
            }
            return false;
            break;
        case J_DBG:
            if (record->event.pressed) {
                RGB rgb = hsv_to_rgb(rgb_matrix_config.hsv);
                uprintf("{H:%d S:%d V:%d} ",
                        rgb_matrix_config.hsv.h,
                        rgb_matrix_config.hsv.s,
                        rgb_matrix_config.hsv.v);
                uprintf("{R:%d G:%d B:%d} ",
                        rgb.r, rgb.g, rgb.b);
                uprintf("M: %d ", rgb_matrix_config.mode);
                uprintf("OS: %d ", os_layer);
                uprintln();
            }
            return false;
            break;
    }
    return true;
}
