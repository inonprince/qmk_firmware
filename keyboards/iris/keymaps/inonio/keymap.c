#include "iris.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

#define _DVORAK 0
#define _QWERTY 1
#define _LOWER 3
#define _RAISE 4
#define _MS_MV 5
#define _MS_WH 6
#define _ARROWS 7
#define _ADJUST 16

enum custom_keycodes {
  DVORAK = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  R_GUI_ALFRED,
  RSFT_BKSP
};

#define KC_         KC_TRNS
#define _______     KC_TRNS
#define XXXXXXX     KC_NO
#define ARW_O     LT(_ARROWS,KC_O)
#define MSMV_U     LT(_MS_MV,KC_U)
#define MEH_TAB     MT(MOD_MEH, KC_TAB)
#define MO_MS_W     MO(_MS_WH)
#define KC_LOCK     LGUI(LCTL(KC_Q))
#define KC_LOWR     LOWER
#define KC_RASE     RAISE
#define KC_RST      RESET
#define KC_BL_S     BL_STEP

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  [_DVORAK] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      KC_ESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                            KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      MEH_TAB, KC_QUOT, KC_COMM, KC_DOT , KC_P   , KC_Y   ,                            KC_F   , KC_G   , KC_C   , KC_R   , KC_L   , KC_TAB ,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RAISE  , KC_A   , ARW_O  , KC_E   , MSMV_U , KC_I   ,                            KC_D   , KC_H   , KC_T   , KC_N   , KC_S   , KC_SLSH,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      KC_LSFT, KC_SCLN, KC_Q   , KC_J   , KC_K   , KC_X   , KC_SPC ,          KC_ENT , KC_B   , KC_M   , KC_W   , KC_V   , KC_Z   ,RSFT_BKSP,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      KC_LCTL, LOWER  , KC_SPC ,                  KC_ENT ,R_GUI_ALFRED,KC_LALT
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),

  [_QWERTY] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     ESC , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     TAB , Q  , W  , E  , R  , T  ,                Y  , U  , I  , O  , P  ,DEL ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RASE, A  , S  , D  , F  , G  ,                H  , J  , K  , L  ,SCLN,QUOT,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     LSFT, Z  , X  , C  , V  , B  ,SPC ,     ENT , N  , M  ,COMM,DOT ,SLSH,RGHT,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                       LCTL,LOWR,SPC ,         ENT ,LGUI,LALT
  //                  `----+----+----'        `----+----+----'
  ),

  [_LOWER] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     TILD,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,BSPC,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
     RST , 1  , 2  , 3  , 4  , 5  ,                6  , 7  , 8  , 9  , 0  ,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,    ,LEFT,RGHT, UP ,LBRC,               RBRC, P4 , P5 , P6 ,PLUS,PIPE,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     BL_S,    ,    ,    ,DOWN,LCBR,LPRN,     RPRN,RCBR, P1 , P2 , P3 ,MINS,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,DEL ,         DEL ,    , P0
  //                  `----+----+----'        `----+----+----'
  ),

  [_RAISE] = KC_KEYMAP(
  //,----+----+----+----+----+----.              ,----+----+----+----+----+----.
     F12 , F1 , F2 , F3 , F4 , F5 ,                F6 , F7 , F8 , F9 ,F10 ,F11 ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,EXLM, AT ,HASH,DLR ,PERC,               CIRC,AMPR,ASTR,LPRN,RPRN,    ,
  //|----+----+----+----+----+----|              |----+----+----+----+----+----|
         ,MPRV,MNXT,VOLU,PGUP,UNDS,               EQL ,HOME,    ,    ,    ,BSLS,
  //|----+----+----+----+----+----+----.    ,----|----+----+----+----+----+----|
     MUTE,MSTP,MPLY,VOLD,PGDN,MINS,    ,         ,PLUS,END ,    ,    ,    ,    ,
  //`----+----+----+--+-+----+----+----/    \----+----+----+----+----+----+----'
                           ,    ,    ,             ,    ,
  //                  `----+----+----'        `----+----+----'
  ),

  [_MS_MV] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, KC_ACL0, KC_ACL1, MO_MS_W, _______, _______,                            _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, KC_BTN1,          KC_BTN2, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, KC_BTN1,                  KC_BTN2, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),

  [_MS_WH] = KEYMAP(
    //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
    //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______,                            _______, KC_WH_R, KC_WH_U, KC_WH_D, KC_WH_L, _______,
    //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
        _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
    //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                        _______, _______, _______,                  _______, _______, _______
    //                                `--------+--------+--------'                `--------+--------+--------'
  ),

  [_ARROWS] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______,                            _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  ),

  [_ADJUST] = KEYMAP(
  //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
      _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      RGB_TOG, RGB_MOD, RGB_HUI, RGB_SAI, RGB_VAI, _______,                            _______, _______, _______, _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
      _______, DEBUG  , RGB_HUD, RGB_SAD, RGB_VAD, _______,                            _______, DVORAK, QWERTY  , _______, _______, _______,
  //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
      BL_STEP, RESET  , _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
                                      _______, _______, _______,                  _______, _______, _______
  //                                `--------+--------+--------'                `--------+--------+--------'
  )

  // [_NAME] = KEYMAP(
  // //,--------+--------+--------+--------+--------+--------.                          ,--------+--------+--------+--------+--------+--------.
  //     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  // //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
  //     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  // //|--------+--------+--------+--------+--------+--------|                          |--------+--------+--------+--------+--------+--------|
  //     _______, _______, _______, _______, _______, _______,                            _______, _______, _______, _______, _______, _______,
  // //|--------+--------+--------+--------+--------+--------+--------.        ,--------|--------+--------+--------+--------+--------+--------|
  //     _______, _______, _______, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______,
  // //`--------+--------+--------+----+---+--------+--------+--------/        \--------+--------+--------+---+----+--------+--------+--------'
  //                                     _______, _______, _______,                  _______, _______, _______
  // //                                `--------+--------+--------'                `--------+--------+--------'
  // )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
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

  if (record->event.pressed && bspc_mode == 1 && keycode != RSFT_BKSP) {
    register_code (KC_RSFT);
    bspc_mode = 0;
    bksp_timer2 = 0;
  }

  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      queue = false;
      break;
    case DVORAK:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_dvorak);
        #endif
        persistent_default_layer_set(1UL<<_DVORAK);
      }
      queue = false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      update_rgb();
      queue = false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
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
    case RSFT_BKSP:
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

  // // hid_listen console msgs - use tools/hid_listen_pipe.sh
  // if (record->event.pressed) {
  //   switch (keycode) {
  //     case KWM_FLOAT:
  //       uprint("CMD:KWM_FLOAT\n");
  //       queue = false;
  //       break;
  //     case KWM_FULLSCREEN:
  //       uprint("CMD:KWM_FULLSCREEN\n");
  //       queue = false;
  //       break;
  //   }
  // }

  return queue;
}
