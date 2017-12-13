#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"
#include "timer.h"

extern keymap_config_t keymap_config;

//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;


// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _DVORAK 0
#define _QWERTY 1
#define _COLEMAK 2
#define _LOWER 3
#define _RAISE 4
#define _MS_MV 5
#define _MS_WH 6
#define _ARROWS 7
#define _ADJUST 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  COLEMAK,
  LOWER,
  RAISE,
  ADJUST,
  R_GUI_ALFRED,
  RSHIFT_BKSP,

  KWM_FLOAT,
  KWM_FULLSCREEN
};

// Fillers to make layering more clear
#define _______     KC_TRNS
#define XXXXXXX     KC_NO
#define ARROW_O     LT(_ARROWS,KC_O)
#define MSMV_U      LT(_MS_MV,KC_U)
#define MEH_ESC     MT(MOD_MEH, KC_ESC)
#define MO_MS_W     MO(_MS_WH)
#define KC_LOCK     LGUI(LCTL(KC_Q))

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_QWERTY] = KEYMAP( \
  KC_TAB,    KC_Q,      KC_W,      KC_E,     KC_R,      KC_T,      KC_Y,      KC_U,      KC_I,      KC_O,      KC_P,      KC_BSPC, \
  KC_ESC,    KC_A,      KC_S,      KC_D,     KC_F,      KC_G,      KC_H,      KC_J,      KC_K,      KC_L,      KC_SCLN,   KC_QUOT, \
  KC_LSFT,   KC_Z,      KC_X,      KC_C,     KC_V,      KC_B,      KC_N,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_ENT , \
  ADJUST,    KC_LCTL,   KC_LALT,   KC_LGUI,  LOWER,     KC_SPC,    KC_SPC,    RAISE,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT \
),

/* Colemak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |Adjust| Ctrl | Alt  | GUI  |Lower |Space |Space |Raise | Left | Down |  Up  |Right |
 * `-----------------------------------------------------------------------------------'
 */
[_COLEMAK] = KEYMAP( \
  KC_TAB,    KC_Q,      KC_W,      KC_F,      KC_P,      KC_G,      KC_J,      KC_L,      KC_U,      KC_Y,      KC_SCLN,   KC_BSPC, \
  KC_ESC,    KC_A,      KC_R,      KC_S,      KC_T,      KC_D,      KC_H,      KC_N,      KC_E,      KC_I,      KC_O,      KC_QUOT, \
  KC_LSFT,   KC_Z,      KC_X,      KC_C,      KC_V,      KC_B,      KC_K,      KC_M,      KC_COMM,   KC_DOT,    KC_SLSH,   KC_ENT , \
  ADJUST,    KC_LCTL,   KC_LALT,   KC_LGUI,   LOWER,     KC_SPC,    KC_SPC,    RAISE,     KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT \
),

/* Dvorak
 * ,-----------------------------------------------------------------------------------.
 * | Tab  |   "  |   ,  |   .  |   P  |   Y  |   F  |   G  |   C  |   R  |   L  | Bksp |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |HypEsc|   A  |Arow/O|   E  |MsMv/U|   I  |   D  |   H  |   T  |   N  |   S  |  /   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | LSft |   ;  |   Q  |   J  |   K  |   X  |   B  |   M  |   W  |   V  |   Z  |RSftBs|
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * | Ctrl |Adjust| Alt  | GUI  |Lower |Space |Enter |Raise | GUI  | Alt  |Adjust| Ctrl |
 * `-----------------------------------------------------------------------------------'
 */
[_DVORAK] = KEYMAP( \
  KC_TAB,    KC_QUOT,  KC_COMM,   KC_DOT,    KC_P,      KC_Y,      KC_F,      KC_G,      KC_C,      KC_R,      KC_L,      KC_TAB, \
  MEH_ESC,   KC_A,     ARROW_O,   KC_E,      MSMV_U,    KC_I,      KC_D,      KC_H,      KC_T,      KC_N,      KC_S,      KC_SLSH, \
  KC_LSFT,   KC_SCLN,  KC_Q,      KC_J,      KC_K,      KC_X,      KC_B,      KC_M,      KC_W,      KC_V,      KC_Z,      RSHIFT_BKSP, \
  KC_LCTL,   ADJUST,   KC_LALT,   KC_LGUI,   LOWER,     KC_SPC,    KC_ENT,    RAISE,     R_GUI_ALFRED,KC_RALT, ADJUST,    KC_RCTL \
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  |  ~   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = KEYMAP( \
  KC_TILD,   KC_EXLM,   KC_AT,     KC_HASH,   KC_DLR,    KC_PERC,   KC_CIRC,   KC_AMPR,   KC_ASTR,   KC_LPRN,   KC_RPRN,   KC_TILD, \
  KC_DEL,    KC_F1,     KC_F2,     KC_F3,     KC_F4,     KC_F5,     KC_F6,     KC_UNDS,   KC_PLUS,   KC_LCBR,   KC_RCBR,   KC_PIPE, \
  _______,   KC_F7,     KC_F8,     KC_F9,     KC_F10,    KC_F11,    KC_F12,    S(KC_NUHS),S(KC_NUBS),_______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_MNXT,   KC_VOLD,   KC_VOLU,   KC_MPLY \
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * | Del  |   4  |   5  |   6  |      |      |      |   -  |   =  |   [  |   ]  |  \   |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |   7  |   8  |   9  |      |      |      |ISO # |ISO / |      |      |Enter |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |   0  |      |      |      |      |      |      | Next | Vol- | Vol+ | Play |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = KEYMAP( \
  KC_GRV,    KC_1,      KC_2,      KC_3,      KC_4,      KC_5,      KC_6,      KC_7,      KC_8,      KC_9,      KC_0,      KC_GRV, \
  KC_DEL,    KC_4,      KC_5,      KC_6,      _______,   _______,   _______,   KC_MINS,   KC_EQL,    KC_LBRC,   KC_RBRC,   KC_BSLS, \
  _______,   KC_7,      KC_8,      KC_9,      _______,   _______,   _______,   KC_NUHS,   KC_NUBS,   _______,   _______,   _______, \
  _______,   KC_0,      _______,   _______,   _______,   _______,   _______,   _______,   KC_MNXT,   KC_VOLD,   KC_VOLU,   KC_MPLY \
),

/* Mouse Move
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      | Acl0 | Acl1 | MsWh |      |      |      |MouseL|MouseD|MouseU|MouseR|      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      | Btn1 | Btn2 |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_MS_MV] = KEYMAP( \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   KC_ACL0,   KC_ACL1,   MO_MS_W,   _______,   _______,   _______,   KC_MS_L,   KC_MS_D,   KC_MS_U,   KC_MS_R,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   KC_BTN1,   KC_BTN2,   _______,   _______,   _______,   _______,   _______ \
),
 
 /* Mouse Wheel
  * ,-----------------------------------------------------------------------------------.
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+-------------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |WheelR|WheelU|WheelD|WheelL|      |
  * |------+------+------+------+------+------|------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * |------+------+------+------+------+------+------+------+------+------+------+------|
  * |      |      |      |      |      |      |      |      |      |      |      |      |
  * `-----------------------------------------------------------------------------------'
  */
[_MS_WH] = KEYMAP( \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_WH_R,   KC_WH_U,   KC_WH_D,   KC_WH_L,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______ \
),
  
/* Arrows
 * ,-----------------------------------------------------------------------------------.
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ARROWS] = KEYMAP( \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_LEFT,   KC_DOWN,   KC_UP,     KC_RGHT,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______ \
),
 
/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |      |Reset |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+-------------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] = KEYMAP( \
  _______,   RESET,     _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   KC_LOCK,   _______, \
  _______,   KWM_FLOAT,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   KWM_FULLSCREEN,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______ \
),

/*
// Layer Name
// ,-----------------------------------------------------------------------------------.
// |      |      |      |      |      |      |      |      |      |      |      |      |
// |------+------+------+------+------+-------------+------+------+------+------+------|
// |      |      |      |      |      |      |      |      |      |      |      |      |
// |------+------+------+------+------+------|------+------+------+------+------+------|
// |      |      |      |      |      |      |      |      |      |      |      |      |
// |------+------+------+------+------+------+------+------+------+------+------+------|
// |      |      |      |      |      |      |      |      |      |      |      |      |
// `-----------------------------------------------------------------------------------'
[_LAYERNAME] = KEYMAP( \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______, \
  _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______,   _______ \
),
*/

};
 
#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

// define variables for reactive RGB
bool TOG_STATUS = false;
int RGB_current_mode;

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

// Setting ADJUST layer RGB back to default
void update_rgb(void) {
  if (IS_LAYER_ON(_RAISE) && IS_LAYER_ON(_LOWER)) {
    rgblight_setrgb(0xff,0x00,0x00);
  } else if (IS_LAYER_ON(_RAISE)) {
    rgblight_setrgb(0xff,0xff,0x00);
  } else if (IS_LAYER_ON(_LOWER)) {
    rgblight_setrgb(0xff,0x00,0xff);
  } else {
    rgblight_setrgb(0x19,0x46,0x8e);
  }
}

void matrix_init_user(void) {
  rgblight_mode(1);
  rgblight_setrgb(0x19,0x46,0x8e);
};

int8_t bspc_mode = 0;
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
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_qwerty, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      queue = false;
      break;
    case COLEMAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_colemak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_COLEMAK);
      }
      queue = false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_NOTE_ARRAY(tone_dvorak, false, 0);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      queue = false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
      } else {
        layer_off(_LOWER);
      }
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      update_rgb();
      queue = false;
      break;
    case RAISE:
    if (record->event.pressed) {
        layer_on(_RAISE);
      } else {
        layer_off(_RAISE);
      }
      update_tri_layer(_LOWER, _RAISE, _ADJUST);
      update_rgb();
      queue = false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      update_rgb();
      queue = false;
      break;
    //switch off mouse wheel layer (when releasing E after U)
    case KC_E:
      if (record->event.pressed) {
      } else {
        if (layer & (1<<_MS_WH)) {
            layer_off(_MS_WH);
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

  // hid_listen console msgs - use tools/hid_listen_pipe.sh
  if (record->event.pressed) {
    switch (keycode) {
      case KWM_FLOAT:
        uprint("CMD:KWM_FLOAT\n");
        queue = false;
        break;
      case KWM_FULLSCREEN:
        uprint("CMD:KWM_FULLSCREEN\n");
        queue = false;
        break;
    }
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
