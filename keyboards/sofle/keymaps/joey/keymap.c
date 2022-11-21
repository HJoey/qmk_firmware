#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30
#define BRIGHT_BRIGHTNESS 100

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, HSV_OVERRIDE_HELP(hsv, 100)}, \
    {36+1, 6,HSV_OVERRIDE_HELP(hsv,100)}
#define SET_NUMPAD(hsv)     \
	{36+18, 3, hsv},\
	  {36+23, 3, hsv},\
	  {36+28, 3, hsv}
#define SET_NUMROW(hsv) \
	{11, 2, hsv}, \
		{21, 2, hsv}, \
		{31, 2, hsv}, \
	  {36+ 11, 2, hsv}, \
	  {36+ 21, 2, hsv}, \
	  {36+ 31, 2, hsv}
#define SET_ARROW(hsv) \
	{36+8, 1, hsv}, \
		{36+14, 2, hsv}, \
		{36+18, 1, hsv} \

#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {36+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
	{1, 6, HSV_OVERRIDE_HELP(hsv,BRIGHT_BRIGHTNESS)}, \
    {36+1, 6, HSV_OVERRIDE_HELP(hsv,BRIGHT_BRIGHTNESS)}


enum sofle_layers {
    _DEFAULTS = 0,
    _MAC = 0,
    _WIN,
    _LOWER,
    _RAISE,
    _ADJUST,
    _NUMPAD,
    _SWITCH
};

enum custom_keycodes {
    KC_MAC = SAFE_RANGE,
    KC_WIN,
    KC_LOWER,
    KC_RAISE,
    KC_ADJUST,
    MY_SCROLLU,
    MY_SCROLLD,
    KC_D_MUTE,
    MC_ViW,
    MC_ViQ,
    MC_ViNewTab,
    MC_Vigt,
    MC_VigT,
    MC_TMN,
    MC_TMP,
    MC_TMC,
    MC_TMW
};

const uint16_t PROGMEM combo_eql[] = {KC_J, KC_K, COMBO_END};
const uint16_t PROGMEM combo_min[] = {KC_M, KC_COMM, COMBO_END};
combo_t key_combos[COMBO_COUNT] = {
    COMBO(combo_eql, KC_EQL),
    COMBO(combo_min, KC_MINS)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * MAC
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ShTab |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|DISCORD|    | MUTE  |------+------+------+------+------+------|
 * |CtrCap|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Grv  | OPT  |CMD   | LOW  | /Space  /       \Enter \  |RISE  |CMD   | OPT  | RCtrl|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_MAC] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,             LT(_SWITCH,KC_6), KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  LT(_NUMPAD,KC_TAB),KC_Q,KC_W,KC_E,  KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
MT(MOD_LSFT,KC_TAB),KC_A,KC_S, KC_D,  KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
MT(MOD_LCTL,KC_CAPS),KC_Z,KC_X, KC_C,  KC_V  ,  KC_B, KC_D_MUTE,  KC_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_GRV  , KC_LOPT, KC_LGUI  , KC_LOWER, KC_SPC  , KC_ENT, KC_RAISE ,KC_RGUI, KC_ROPT, KC_RCTL
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/*
 * WIN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |ShTab |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|DISCORD|    | MUTE  |------+------+------+------+------+------|
 * |CtrCap|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Grv  | WIN  | ALT  | LOW  | /Space  /       \Enter \  |RISE  |ALT   | WIN  | RCtrl|
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_WIN] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  QK_GESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,             LT(_SWITCH,KC_6), KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  LT(_NUMPAD,KC_TAB),KC_Q,KC_W,KC_E,  KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_BSPC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
MT(MOD_LSFT,KC_TAB),KC_A,KC_S,KC_D,  KC_F,    KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_SCLN, KC_QUOT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
MT(MOD_LCTL,KC_CAPS),KC_Z,KC_X, KC_C,  KC_V  ,  KC_B, KC_D_MUTE,  KC_MUTE,KC_N,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 KC_GRV  , KC_LGUI, KC_LALT, KC_LOWER, KC_SPC   , KC_ENT, KC_RAISE , KC_RALT, KC_RGUI,  KC_RALT
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),


/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | F12  |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   [  |   ]  |   \  |  =   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |MSLClk| WhDn |-------.    ,-------| left | down |  up  | right| bspc |  del |
 * |------+------+------+------+------+------|       |    |  MUTE |------+------+------+------+------+------|
 * | trans|      |      |      |MSRClk| WhUp |-------|    |-------| msL  | msD  | msU  | msR  |      | trans|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | trans| /Space  /       \Enter \  |SPACE |RAISE | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_LOWER] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
   KC_F12,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_GRV,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_LBRC,  KC_RBRC, KC_BSLS, KC_EQL,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_NO,  KC_NO,   KC_NO,   KC_BTN1,MY_SCROLLU,                 KC_LEFT, KC_DOWN, KC_UP,  KC_RGHT, KC_BSPC,   KC_DEL,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  KC_NO,  KC_NO,   KC_NO,   KC_BTN2,MY_SCROLLD,_______, _______,KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,    _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* RAISE 
 * ,----------------------------------------.                     ,-----------------------------------------.
 * |      |   !  |   @  |   #  |   $  |   %  |                    |   ^  |   &  |   *  |  (   |   )  |  _   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Grv |  ViQ | ViW  | ViRDn| CtrR |ViNTab|                    | ViRUp| CtrU | CtrI | CtrO | Ctrlt| Ctr] |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  Esc |      | TMW  | CtrD | Vi_gT|Vi_gt |-------.    ,-------| Left | Down | Up   | Right| BSPC | DEL  |
 * |------+------+------+------+------+------|       |    |  MUTE |------+------+------+------+------+------|
 * | Ctrl |      |      | TMC  | TMP  | TMN  |-------|    |-------| Home | End  | PgUp | PgDn |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_RAISE] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, S(KC_1) , S(KC_2), S(KC_3), S(KC_4),S(KC_5),                   S(KC_6), S(KC_7), S(KC_8), S(KC_9), S(KC_0),S(KC_MINS),
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    KC_GRV ,MC_ViQ , MC_ViW , C(KC_E), C(KC_R),MC_ViNewTab,                 C(KC_Y) ,C(KC_U), C(KC_I), C(KC_O),C(KC_T),C(KC_RBRC),
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    KC_ESC , KC_NO , MC_TMW, C(KC_D) , MC_VigT,MC_Vigt,                    KC_LEFT ,KC_DOWN, KC_UP , KC_RGHT , KC_BSPC, KC_DEL , 
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  KC_NO  , KC_NO  , MC_TMC, MC_TMP, MC_TMN ,_______,    _______,KC_HOME, KC_END ,KC_PGUP, KC_PGDN, KC_NO  ,_______ ,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* ADJUST (layer4)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | QK_BOOT|      |      |      |      |      |                  |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG|hue^ |sat ^ | bri ^|      | MAC  |-------.    ,-------|desk <| CtrDn| CtrUp|desk >|  up  |      |
 * |------+------+------+------+------+------|       |    |  MUTE |------+------+------+------+------+------|
 * | mode | hue dn|sat d|bri dn|      | WIN  |-------|    |-------|  PREV | PLAY | NEXT | left| down | right|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  QK_BOOT, XXXXXXX,XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RGB_TOG, RGB_HUI,RGB_SAI, RGB_VAI, _______ , KC_MAC ,                C(KC_LEFT),C(KC_DOWN),C(KC_UP),C(KC_RGHT),KC_UP,XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  RGB_MOD, RGB_HUD,RGB_SAD, RGB_VAD, XXXXXXX, KC_WIN ,XXXXXXX,    XXXXXXX, KC_MPRV,KC_MPLY, KC_MNXT,KC_LEFT , KC_DOWN, KC_RGHT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                   _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* NUMPAD
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |NumLck|      |      |   /  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |      |   7  |   8  |   9  |   *  | BSPC |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |   4  |   5  |   6  |   -  |   |  |
 * |------+------+------+------+------+------|       |    | MUTE  |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |   1  |   2  |   3  |   +  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |LOWER | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMPAD] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   _______, KC_NLCK, XXXXXXX, XXXXXXX,KC_PSLS, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P7,  KC_P8,   KC_P9,   KC_ASTR, KC_BSPC ,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, KC_P4,  KC_P5,   KC_P6,   KC_PMNS,  KC_PIPE,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,_______,   _______,XXXXXXX, KC_P1,  KC_P2,   KC_P3,   KC_PPLS, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
              _______, OSM(MOD_MEH), _______, _______, _______,   _______, _______,  KC_P0,   KC_PDOT, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | mac  | low  | rise | adj  |numpad|  sw  |                    |      |      |      |      |      |QK_BOOT|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | win  |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EEP_RST|
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            |      |      |      |      | /       /       \      \  |      |      |      |      |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[_SWITCH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  TO(0),   TO(2),   TO(3),   TO(4),   TO(5),   TO(6),                      KC_NO ,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   QK_BOOT,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  TO(1),   KC_NO, KC_BRIU,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EEP_RST,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_SYSTEM_SLEEP,KC_NO,KC_NO,KC_NO,  KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/

	),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[72];
// Now define the array of layers. Later layers take precedence

// MAC,
const rgblight_segment_t PROGMEM layer_mac_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  //SET_LAYER_ID(HSV_WHITE)
    SET_INDICATORS(HSV_WHITE)
);

// WIN,
const rgblight_segment_t PROGMEM layer_win_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_BLUE)
);

// _LOW,
const rgblight_segment_t PROGMEM layer_low_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)
);

// _RISE,
const rgblight_segment_t PROGMEM layer_rise_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GREEN)
);

//_NUMPAD
const rgblight_segment_t PROGMEM layer_numpad_lights[] = RGBLIGHT_LAYER_SEGMENTS(
    SET_LAYER_ID(HSV_ORANGE),
	SET_NUMPAD(HSV_BLUE)
    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GOLD),
	//SET_NUMROW(HSV_GREEN),
    SET_ARROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    layer_mac_lights,
    layer_win_lights,
	layer_low_lights,
	layer_rise_lights,
	layer_numpad_lights,
	layer_switcher_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_MAC));
	rgblight_set_layer_state(1, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_WIN));
	rgblight_set_layer_state(2, layer_state_cmp(state, _LOWER));
	rgblight_set_layer_state(3, layer_state_cmp(state, _RAISE));
	rgblight_set_layer_state(4, layer_state_cmp(state, _NUMPAD));
	rgblight_set_layer_state(5, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(6, layer_state_cmp(state, _SWITCH));
    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	//rgblight_mode(20);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Joey"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)

    switch (get_highest_layer(default_layer_state)) {
        case _MAC:
            oled_write_ln_P(PSTR("MAC"), false);
            break;
        case _WIN:
            oled_write_ln_P(PSTR("WIN"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }

    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _MAC:
        case _WIN:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _NUMPAD:
            oled_write_P(PSTR("Nump\n"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MAC:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_MAC);
            }
            return false;
        case KC_WIN:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_WIN);
            }
            return false;
        case KC_LOWER:
            if (record->event.pressed) {
                layer_on(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_LOWER);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_RAISE:
            if (record->event.pressed) {
                layer_on(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            } else {
                layer_off(_RAISE);
                update_tri_layer(_LOWER, _RAISE, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
            break;
        case MY_SCROLLU:
            if (record->event.pressed) {
                if (layer_state_cmp(default_layer_state,_MAC)) {
                    register_code(KC_WH_D);
                } else {
                    register_code(KC_WH_U);
                }
            } else {
                if (layer_state_cmp(default_layer_state,_MAC)) {
                    unregister_code(KC_WH_D);
                } else {
                    unregister_code(KC_WH_U);
                }
            }
            break;
        case MY_SCROLLD:
            if (record->event.pressed) {
                if (layer_state_cmp(default_layer_state,_MAC)) {
                    register_code(KC_WH_U);
                } else {
                    register_code(KC_WH_D);
                }
            } else {
                if (layer_state_cmp(default_layer_state,_MAC)) {
                    unregister_code(KC_WH_U);
                } else {
                    unregister_code(KC_WH_D);
                }
            }
            break;
        case MC_ViW:
            if (record->event.pressed) {
                SEND_STRING(":w\n");
            } else {
            }
            return false;
        case MC_ViQ:
            if (record->event.pressed) {
                SEND_STRING(":q\n");
            } else {
            }
            return false;
        case MC_ViNewTab:
            if (record->event.pressed) {
                SEND_STRING(":tabnew ");
            } else {
            }
            return false;
        case MC_Vigt:
            if (record->event.pressed) {
                SEND_STRING("gt");
            } else {
            }
            return false;
        case MC_VigT:
            if (record->event.pressed) {
                SEND_STRING("gT");
            } else {
            }
            return false;
        case MC_TMN:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")"n");
            } else {
            }
            return false;
        case MC_TMP:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")"p");
            } else {
            }
            return false;
        case MC_TMC:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")"c");
            } else {
            }
            return false;
        case MC_TMW:
            if (record->event.pressed) {
                SEND_STRING(SS_LCTL("b")"w");
            } else {
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_BRIU);
        } else {
            tap_code(KC_BRID);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    }
    return true;
}

#endif
