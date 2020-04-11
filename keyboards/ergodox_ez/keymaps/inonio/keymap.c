#include QMK_KEYBOARD_H
#include "debug.h"
#include "action_layer.h"
#include "timer.h"

#define BASE 0 // default layer
#define SYMB 1 // symbols
#define MDIA 2 // media keys
#define _MOUSEKEYS 3
#define _MOUSESCROLL 4

enum custom_keycodes {
  R_GUI_ALFRED = SAFE_RANGE,
  RSHIFT_BKSP
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   =    |   1  |   2  |   3  |   4  |   5  |   `  |           |  L2  |   6  |   7  |   8  |   9  |   0  |  Esc   |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   '  |   ,  |   .  |   P  |   Y  |  L1  |           |  =   |   F  |   G  |   C  |   R  |   L  |  Tab   |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * | Caps   |   A  | O/L2 |   E  | U/L3 |   I  |------|           |------|   D  |   H  |   T  |   N  |   S  |  l1    |
 * |--------+------+------+------+------+------|  l1  |           |  -   |------+------+------+------+------+--------|
 * | LShift |   :  |   Q  |   J  |   K  |   X  |      |           |      |   B  |   M  |   W  |   V  |   Z  | RShift |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |   \  |   /  | LCtrl| LAlt | LGui |                                       | Rgui | RAlt | RCtrl|   [  |  ]   |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |  Up  | Down |       | Left | Right|
 *                                 ,------|------|------|       |------+--------+------.
 *                                 |      |      | Home |       | PgUp |        |      |
 *                                 | Space|Backsp|------|       |------| Bkspc  |Enter |
 *                                 |      |ace   | End  |       | PgDn |        |      |
 *                                 `--------------------'       `----------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_EQL,         KC_1,           KC_2,           KC_3,           KC_4,           KC_5,           KC_GRV,
        KC_TAB,         KC_QUOT,        KC_COMM,        KC_DOT,         KC_P,           KC_Y,           TG(1),
        MT(MOD_MEH,KC_ESC), KC_A,       LT(2, KC_O),    KC_E,           LT(3, KC_U),    KC_I,
        KC_LSFT,        KC_SCLN,        KC_Q,           KC_J,           KC_K,           KC_X,           MO(1),
        KC_BSLS,        KC_SLSH,        KC_LCTRL,       KC_LALT,        KC_LGUI,
                                                                                        KC_UP,          KC_DOWN,
                                                                                                        KC_HOME,
                                                                        KC_SPACE,       KC_BSPC,        KC_END,

        // right hand
        TG(2),          KC_6,           KC_7,           KC_8,           KC_9,           KC_0,           KC_CAPS,
        KC_EQL,         KC_F,           KC_G,           KC_C,           KC_R,           KC_L,           KC_TAB,
                        KC_D,           KC_H,           KC_T,           KC_N,           KC_S,           MO(1),
        KC_MINS,        KC_B,           KC_M,           KC_W,           KC_V,           KC_Z,           RSHIFT_BKSP,
                                        R_GUI_ALFRED,   KC_RALT,        KC_RCTRL,       KC_LBRC,        KC_RBRC,
        KC_LEFT,          KC_RIGHT,
        KC_PGUP,
        KC_PGDN,        KC_BSPC,        KC_ENT
    ),
/* Keymap 1: Symbol Layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * | RESET  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |   !  |   @  |   {  |   }  |   |  |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   #  |   $  |   (  |   )  |   `  |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |   %  |   ^  |   [  |   ]  |   ~  |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |   0  |    . |   =  |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// SYMBOLS
[SYMB] = LAYOUT_ergodox(
       // left hand
       RESET  ,KC_F1,  KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_TRNS,
       KC_TRNS,KC_EXLM,KC_AT,  KC_LCBR,KC_RCBR,KC_PIPE,KC_TRNS,
       KC_MS_R,KC_HASH,KC_DLR, KC_LPRN,KC_RPRN,KC_GRV,
       KC_MS_L,KC_PERC,KC_CIRC,KC_LBRC,KC_RBRC,KC_TILD,KC_TRNS,
       KC_WH_L,KC_WH_D,KC_WH_U,KC_WH_R,KC_ACL1,
                                       KC_TRNS,KC_TRNS,
                                               KC_TRNS,
                               KC_TRNS,KC_TRNS,KC_TRNS,
       // right hand
       RGB_TOG, KC_F6,   KC_F7,  KC_F8,   KC_F9,   KC_F10,  KC_F11,
       KC_TRNS, KC_UP,   KC_7,   KC_8,    KC_9,    KC_ASTR, KC_F12,
                KC_DOWN, KC_4,   KC_5,    KC_6,    KC_PLUS, KC_TRNS,
       KC_TRNS, KC_AMPR, KC_1,   KC_2,    KC_3,    KC_BSLS, KC_TRNS,
                         KC_TRNS,KC_0,   KC_DOT,   KC_EQL,  KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 2: Media and movement keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      | Play | Prev | Next | Mute |VolDn | VolUp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      | Left | Down |  Up  |Right |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_MPLY, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT,KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
/* Keymap 3: mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      | Play | Prev | Next | Mute |VolDn | VolUp  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |MsAcl1|MsAcl1|  l4  |      |      |------|           |------|      |MsLeft|MsDown| MsUp |MsRght|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 | Lclk |      |------|       |------|      | Rclk |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_MOUSEKEYS] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_ACL0, KC_ACL1, MO(4),   KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_BTN1, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_MPLY, KC_MPRV, KC_MNXT, KC_MUTE, KC_VOLD, KC_VOLU,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_WH_L, KC_WH_U, KC_WH_D, KC_WH_R, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_BTN2
),
/* Keymap 4: mouse wheel
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|      |WlLeft|WlDown| WlUp |WlRght|        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |      |      |      |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |      |
 *                                 |      |      |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[_MOUSESCROLL] = LAYOUT_ergodox(
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_ACL0, KC_ACL1, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                           KC_TRNS, KC_TRNS,
                                                    KC_TRNS,
                                  KC_TRNS, KC_TRNS, KC_TRNS,
    // right hand
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                 KC_TRNS, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, KC_TRNS,
       KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
       KC_TRNS, KC_TRNS,
       KC_TRNS,
       KC_TRNS, KC_TRNS, KC_TRNS
),
};

const uint16_t PROGMEM fn_actions[] = {
    [0] = ACTION_MODS_TAP_KEY(MOD_RSFT, KC_BSPC)
};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
  // MACRODOWN only works in this function
      switch(id) {
        case 0:
        if (record->event.pressed) {
          register_code(KC_RSFT);
        } else {
          unregister_code(KC_RSFT);
        }
        break;
      }
    return MACRO_NONE;
};

// Runs just one time when the keyboard initializes.
void matrix_init_user(void) {
  rgblight_sethsv_noeeprom_green();
};

uint8_t bspc_mode = 0;
uint16_t gui_timer = 0;
uint16_t bksp_timer = 0;
uint16_t bksp_timer2 = 0;
bool otherkeypressed = false;

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool queue = true;
  if (record->event.pressed) {
    otherkeypressed = true;
  }

  uint8_t layer = layer_state;

  if (record->event.pressed && bspc_mode == 1 && keycode != RSHIFT_BKSP) {
    register_code (KC_RSFT);
    bspc_mode = 0;
    bksp_timer2 = 0;
  }

  switch (keycode) {

    //switch off mouse wheel layer (when releasing E after U)
    case KC_E:
      if (record->event.pressed) {
      } else {
        if (layer & (1<<_MOUSESCROLL)) {
            layer_off(_MOUSESCROLL);
        }
      }
      break;

    // command when held / pressed as modifier. SFT+CTRL+GUI+Y when tapped.
    case R_GUI_ALFRED:
      if (record->event.pressed) {
        otherkeypressed = false;
        gui_timer = timer_read();
        register_code (KC_RGUI);
      } else {
        if ((timer_elapsed (gui_timer) < TAPPING_TERM) && (otherkeypressed == false)) {
          register_code (KC_RSFT);
          register_code (KC_RCTRL);
          register_code (KC_Y);
          unregister_code (KC_Y);
          unregister_code (KC_RCTRL);
          unregister_code (KC_RSFT);
        }
        unregister_code (KC_RGUI);
      }
      queue = false;
      break;

    // shift when held / pressed as modifier. BSPC when tapped.
    case RSHIFT_BKSP:
      if (record->event.pressed) {
        flatten_lt_keys = true;
        otherkeypressed = false;
        if ((bksp_timer2 > 0) && (timer_elapsed(bksp_timer2) < TAPPING_TERM)) {
          bspc_mode = 1;
          bksp_timer2 = timer_read();
        }
        bksp_timer = timer_read();
        register_code (KC_RSFT);
      } else {
        flatten_lt_keys = false;
        if (bspc_mode == 2) {
          bspc_mode = 0;
          unregister_code (KC_BSPC);
        } else {
          if ((timer_elapsed (bksp_timer) < 150) && (otherkeypressed == false)) {
            unregister_code (KC_RSFT);
            register_code (KC_BSPC);
            unregister_code (KC_BSPC);
            bspc_mode = 0;
            bksp_timer2 = timer_read();
          } else {
            unregister_code (KC_RSFT);
          }
          bksp_timer = 0;
        }
      }
      queue = false;
      break;
  }
  return queue;
}


// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    if ((bspc_mode == 1) && (bksp_timer2 > 0) && (timer_elapsed(bksp_timer2) > 100)) {
      bspc_mode = 2;
      bksp_timer2 = 0;
      unregister_code (KC_RSFT);
      register_code (KC_BSPC);
    }

};

uint32_t layer_state_set_user(uint32_t state) {
  ergodox_board_led_off();
  ergodox_right_led_1_off();
  ergodox_right_led_2_off();
  ergodox_right_led_3_off();

  uint8_t layer = biton32(state);
  switch (layer) {
      case 0:
        // #ifdef RGBLIGHT_COLOR_LAYER_0
        //   rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
        // #else
        rgblight_sethsv_noeeprom_green();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_STATIC_LIGHT);
        // if no color desired on layer 0, call rgblight_init() instead
        break;
      case 1:
        ergodox_right_led_1_on();
        rgblight_sethsv_noeeprom_red();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_BREATHING + 3);
        break;
      case 2:
        ergodox_right_led_2_on();
        rgblight_sethsv_noeeprom_blue();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 2);
        break;
      case 3:
        ergodox_right_led_3_on();
        rgblight_sethsv_noeeprom_chartreuse();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 2);
        break;
      case 4:
        ergodox_right_led_1_on();
        ergodox_right_led_2_on();
        rgblight_sethsv_noeeprom_orange();
        rgblight_mode_noeeprom(RGBLIGHT_MODE_KNIGHT + 2);
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
          rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
        #endif
        break;
      default:
        break;
    }

  return state;
};
