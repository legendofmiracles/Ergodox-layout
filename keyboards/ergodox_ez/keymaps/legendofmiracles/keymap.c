#include QMK_KEYBOARD_H
#include "version.h"
#include "raw_hid.h"

enum layers {
    BASE, // default layer
    SYMB, // symbols
    MDIA,  // media keys
    QWERTY, // Colemak lol
    GAY, // gaming layer
//    ASTNOP1,
//    ASTNOP2,
//    ASTNOP3,
//    ASTNOP4,
//    ASTNOP5,
//    ASTNOP6,
//    ASTNOP7,
//    ASTNOP8,
//    ASTNOP9
};

enum custom_keycodes {
  RGB_SLD,
//  WPM
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |  PrintS|   1  |   2  |   3  |   4  |   5  | ESCA |           | RIGHT|   6  |   7  |   8  |   9  |   0  |   -    |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |   =/+  |   Q  |   W  |   E  |   R  |   T  |[]/{} |           |CoderL|   Y  |   U  |   I  |   O  |   P  |   \    |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |  -/_   |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |; / L2|' / Cmd |
 * |--------+------+------+------+------+------|CapsLo|           |PlayMa|------+------+------+------+------+--------|
 * | LShift |Z/Ctrl|   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |//Ctrl| RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Grv/L1|  '"  |AltShf| Left | Right|                                       |  Up  | Down |   [  |   ]  | ~L1  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,---------------.
 *                                        | App  |ASTNOP|       |Colmak|Ctrl/Esc|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      |Record|       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------|  Tab   |Enter |
 *                                 |      |ace   |S. Re |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
[BASE] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,         KC_1,        KC_2,          KC_3,    KC_4,    KC_5,    KC_ESC,             TG(SYMB),     KC_6,    KC_7,    KC_8,    KC_9,      KC_0,               KC_MINS,
  KC_EQL,          KC_Q,        KC_W,          KC_F,    KC_P,    KC_G,    KC_LBRC,            KC_CAPS,      KC_J,    KC_L,    KC_U,    KC_Y,      KC_SCLN,            KC_BSLS,
  KC_MINS,         KC_A,        KC_R,          KC_S,    KC_T,    KC_D,                                      KC_H,    KC_N,    KC_E,    KC_I,      LT(MDIA, KC_O),     GUI_T(KC_QUOT),
  KC_LSFT,         CTL_T(KC_Z), KC_X,          KC_C,    KC_V,    KC_B,    LALT_T(KC_RBRC),    KC_ESC,       KC_K,    KC_M,    KC_COMM, KC_DOT,    CTL_T(KC_SLSH),     KC_RSFT,
  KC_TRNS,         KC_TRNS,     KC_DEL,        KC_LEFT, KC_RGHT,                                                     KC_UP,   KC_DOWN, KC_TRNS,   KC_TRNS,            LT(SYMB,KC_GRV),
                                                          ALT_T(KC_APP),  KC_LGUI,            TG(QWERTY), CTL_T(KC_ESC),
                                                                          KC_TRNS,            KC_PGUP,
                                                         KC_SPC, KC_BSPC, TG(GAY),            KC_PGDN, KC_TAB, KC_ENT
),
/* Keymap 1: Symbol Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |         |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |         |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |         |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   | EPRM  |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[SYMB] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_TRNS,     KC_TRNS, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,
  KC_TRNS, KC_EXLM, KC_AT,   KC_LCBR, KC_RCBR, KC_PIPE, KC_TRNS,     KC_TRNS, KC_UP,   KC_7,    KC_8,    KC_9,    KC_ASTR, KC_F12,
  KC_TRNS, KC_HASH, KC_DLR,  KC_LPRN, KC_RPRN, KC_GRV,               KC_DOWN, KC_4,    KC_5,    KC_6,    KC_PLUS, KC_TRNS,
  KC_TRNS, KC_PERC, KC_CIRC, KC_LBRC, KC_RBRC, KC_TILD, KC_TRNS,     KC_TRNS, KC_AMPR, KC_1,    KC_2,    KC_3,    KC_BSLS, KC_TRNS,
  EEP_RST, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,                                         KC_TRNS, KC_DOT,  KC_0,    KC_EQL,  KC_TRNS,
                                               RGB_MOD, KC_TRNS,     RGB_TOG, RGB_SLD,
                                                        KC_TRNS,     KC_TRNS,
                                      RGB_VAD, RGB_VAI, KC_TRNS,     RESET, RGB_HUD, RGB_HUI
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      | MsUp |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsLeft|MsDown|MsRght|      |      |------|           |------|      |      |      |      |      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      | Lclk | Rclk |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
[MDIA] = LAYOUT_ergodox_pretty(
  // left hand
  KC_TRNS,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,    KC_TRNS,          KC_TRNS,    KC_TRNS,    KC_TRNS,   KC_TRNS,   KC_TRNS,     KC_TRNS,  KC_TRNS,
  KC_TRNS,   KC_TRNS, KC_MS_U, KC_TRNS, KC_TRNS, UC(0xF1),     UC(0xED),         UC(0xE9),   UC(0xC3),   UC(0x00F8),UC(0x3B8), UC(0x2211),  KC_TRNS,  KC_TRNS,
  UC(0x223), KC_MS_L, KC_MS_D, KC_MS_R, UC(0x221E),UC(0x3C0),                    UC(0xE1),   UC(0xE4),   UC(0xF6),  UC(0xFC),  KC_TRNS,  KC_MPLY,
  // chess
  UC(0x2654),UC(0x2655), UC(0x2656), UC(0x2657),   UC(0x2658), KC_TRNS,KC_TRNS,  UC(0x265B), UC(0x265C),UC(0x265D),UC(0x265E),  UC(0x265F),KC_TRNS, KC_TRNS,
  KC_TRNS,   KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                                        KC_VOLU,   KC_VOLD,   KC_MUTE,     KC_TRNS, KC_TRNS,

                                                KC_TRNS,KC_TRNS,                 KC_TRNS, KC_TRNS,
                                                        KC_TRNS,                 KC_TRNS,
                                   UC(0x2659), KC_TRNS, KC_TRNS,                 KC_TRNS, KC_WBAK, UC(0x265A)
),
[QWERTY] = LAYOUT_ergodox(
        // left hand
        KC_TRNS,          KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,     KC_TRNS,     KC_TRNS,
        KC_TRNS,          KC_Q,       KC_W,           KC_E,           KC_R,        KC_T,        KC_TRNS,
        KC_TRNS,          KC_A,       KC_S,           KC_D,           KC_F,        KC_G,
        KC_TRNS,          KC_Z,       KC_X,           KC_C,           KC_V,        KC_B,        LALT_T(KC_RBRC),
        LT(SYMB, KC_GRV), KC_TRNS,    KC_TRNS,        KC_TRNS,        KC_TRNS,

                                                                              KC_TRNS, KC_TRNS,
                                                                              KC_TRNS,
                                                                              KC_TRNS, KC_TRNS, KC_TRNS,

        // right hand
        KC_TRNS,         KC_TRNS,        KC_TRNS,  KC_TRNS,  KC_TRNS,       KC_TRNS,              KC_TRNS,
        TG(SYMB),        KC_Y,           KC_U,     KC_I,     KC_O,          KC_P,              KC_TRNS,
                         KC_H,           KC_J,     KC_K,     KC_L,          LT(MDIA, KC_SCLN),       KC_TRNS,
        KC_TRNS,         KC_N,           KC_M,     KC_TRNS,  KC_TRNS,       KC_TRNS,              KC_TRNS,
                                         KC_TRNS,  KC_TRNS,  CTL_T(KC_TRNS),CTL_T(KC_TRNS),       KC_TRNS,

        KC_TRNS, KC_TRNS,
        KC_TRNS,
        KC_TRNS, KC_TRNS, KC_TRNS
),
[GAY] = LAYOUT_ergodox_pretty(
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_UP,   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_LEFT, KC_DOWN, KC_RGHT, KC_TRNS, KC_TRNS,                       // KC_TRNS, KC_TRNS, DE_UDIA, DE_ADIA, DE_ODIA, KC_MPLY,
                                                                              KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MNXT, KC_TRNS, KC_TRNS,
  KC_TRNS, KC_TRNS, KC_TRNS, KC_BTN1, KC_BTN2,                                         KC_VOLU, KC_VOLD, KC_MUTE, KC_TRNS, KC_TRNS,

                                               KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS,
                                                        KC_TRNS,     KC_TRNS,
                                      KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS, KC_TRNS, KC_WBAK
    )


};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
#ifdef CONSOLE_ENABLE
    uprintf("KL: kc: 0x%04X, col: %u, row: %u, pressed: %b, time: %u, interrupt: %b, count: %u\n", keycode, record->event.key.col, record->event.key.row, record->event.pressed, record->event.time, record->tap.interrupted, record->tap.count);
#endif
  if (record->event.pressed) {
    switch (keycode) {
      #ifdef RGBLIGHT_ENABLE
      case RGB_SLD:
        rgblight_mode(1);
        return false;
      #endif

      /*
      case WPM:
        if (record->event.pressed) {
                uint8_t n = get_current_wpm();
                char wpm_counter[4];
                wpm_counter[3] = '\0';
                wpm_counter[2] = '0' + n % 10;
                wpm_counter[1] = (n /= 10) % 10 ? '0' + (n) % 10 : (n / 10) % 10 ? '0' : ' ';
                wpm_counter[0] = n / 10 ? '0' + n / 10 : ' ';
                send_string(wpm_counter);
        } else {

        }*/
    }
  }
  return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
  rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
#ifdef CONSOLE_ENABLE
  // Customise these values to desired behaviour
  debug_enable=true;
  //debug_matrix=true;
  //debug_keyboard=true;
  //debug_mouse=true;
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = get_highest_layer(state);
  switch (layer) {
      case 0:
        #ifdef RGBLIGHT_COLOR_LAYER_0
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        #endif
        break;
      case 1:
        ergodox_right_led_1_on();
        #ifdef RGBLIGHT_COLOR_LAYER_1
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
        #endif
        break;
      case 2:
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_2
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
        #endif
        break;
      case 3:
        //#ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_3
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
        #endif
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        #ifdef RGBLIGHT_COLOR_LAYER_4
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
        #endif
        break;
      case 5:
        ergodox_right_led_1_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_5
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
        #endif
        break;
      case 6:
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_6
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      case 7:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        ergodox_right_led_3_on();
        #ifdef RGBLIGHT_COLOR_LAYER_7
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
        #endif
        break;
      default:
        break;
    }

  return state;
};


void raw_hid_receive(uint8_t *data, uint8_t length) {
    ergodox_blink_all_leds();
    rgb_matrix_set_color(36, 0x00, 0x00, 0x00);
    raw_hid_send(data, length);
}

