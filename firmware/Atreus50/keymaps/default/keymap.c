/* Copyright 2020 David
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _FN1,
    _FN2,
    _FN3,
    _FN4,
    _FN5,
    _FN6
};

// Defines the keycodes used by our macros in process_record_user
enum custom_keycodes {
    QMKBEST = SAFE_RANGE,
    QMKURL
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
        KC_ESC,   KC_Q,    KC_W,    KC_E, KC_R,    KC_T,                            KC_Y,     KC_U,    KC_I,     KC_O,   KC_P,     KC_BSPC,
        MO(_FN2), KC_A,    KC_S,    KC_D, KC_F,    KC_G,                            KC_H,     KC_J,    KC_K,     KC_L,   KC_SCLN,  KC_ENTER,
        KC_LSFT,  KC_Z,    KC_X,    KC_C, KC_V,    KC_B,                            KC_N,     KC_M,    KC_COMMA, KC_DOT, KC_SLASH, KC_RSFT,
        KC_LCTRL, KC_ESC,  KC_LALT, KC_NO,KC_LGUI, MO(_FN1),  MO(_FN3),   MO(_FN4), KC_SPACE, MO(_FN5),KC_VOLD,  KC_VOLU,KC_RALT,  KC_LBRC
    ),
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | ESC |  Q  |  W  |  E  |  R  |  T  |                |  Y  |  U  |  I  |  O  |  P  |BSPC |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | FN2 |  A  |  S  |  D  |  F  |  G  |                |  H  |  J  |  K  |  L  |  Ñ  |ENTER|
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |SHIFT|  Z  |  X  |  C  |  V  |  B  |                |  N  |  M  |  ,  |  .  |  -  |SHIFT|
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
     * |CTRL | ESC | ALT |     |SUPER| FN1 | FN3 |    |     |SPACE| FN5 |VOLD |VOLU |RALT |  ´  |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
    */
    [_FN1] = LAYOUT(
        KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                      KC_NO,   KC_NO,   KC_NO,     KC_NO,   S(KC_QUOT), S(KC_BSLS),    
        KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,                     KC_LEFT, KC_DOWN, KC_UP,     KC_RIGHT,S(KC_8),    S(KC_9),    
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NUBS, S(KC_NUBS),KC_NO,   KC_QUOT,    KC_BSLS,     
        KC_LCTRL,KC_LGUI, KC_LALT, KC_NO,   KC_LGUI, KC_NO,   RESET,    KC_NO,   KC_TAB,  KC_NO,   KC_NO,     KC_NO,   KC_NO,      KC_NO    
    ),
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | F1  | F2  | F3  | F3  | F5  | F6  |                |     |     |     |     |  [  |  ]  |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * | F7  | F8  | F9  | F10 | F11 | F12 |                |LEFT |DOWN | UP  |RIGHT|  (  |  )  |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |SHIFT|     |     |     |     |     |                |     |  <  |  >  |     |  {  |  }  |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
     * |CTRL |SUPER| ALT |     |SUPER| FN  |BOOT |    |     | TAB |     |     |SHIFT| ALT |CTRL |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
    */
    [_FN2] = LAYOUT(
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      RALT(KC_QUOT), KC_7,    KC_8,    KC_9,    KC_PAST, KC_BSPC,    
        KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      S(KC_7),       KC_4,    KC_5,    KC_6,    KC_PPLS, KC_ENTER,    
        KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,         KC_1,    KC_2,    KC_3,    KC_PMNS, KC_NO,    
        KC_LCTRL,KC_LGUI, KC_LALT, KC_NO,   KC_LGUI, KC_NO,   KC_NO,    S(KC_0), KC_0,          KC_DOT,  KC_NO,   KC_NO,   KC_NO,   KC_NO    
    ),
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |  ^  |  7  |  8  |  9  |  *  |BSPC |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |  /  |  4  |  5  |  5  |  +  |ENTER|
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |SHIFT|     |     |     |     |     |                |     |  1  |  2  |  3  |  -  |     |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
     * |CTRL |SUPER| ALT |     |SUPER|     |     |    |  =  |  0  |  .  |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
    */
    [_FN5] = LAYOUT(
        KC_NO,     KC_NO,   KC_NO,   S(KC_3),  RALT(KC_SCLN),KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    
        S(KC_6),   S(KC_4), S(KC_2), S(KC_1),  S(KC_MINS),   KC_GRAVE,                       KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_ENTER,    
        KC_LSFT,   S(KC_5), KC_MINS, S(KC_EQL),KC_EQL,       KC_NO,                          KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,     
        KC_LCTRL,  KC_LGUI, KC_LALT, KC_NO,    S(KC_7),      RALT(KC_Q),  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO    
    ),
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |  #  |  ~  |     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |  &  |  $  |  "  |  !  |  ?  |  |  |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |SHIFT|  %  |  '  |  ¡  |  ¿  |     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
     * |CTRL |SUPER| ALT |     |  /  |  @  |     |    |     |     | FN  |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
    */
     [_FN3] = LAYOUT( 
         KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
         KC_NO,   KC_NO,   KC_BTN3, KC_BTN2, KC_BTN1, KC_NO,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_ENTER,
         KC_LSFT, KC_NO,   KC_NO,   KC_WH_D, KC_WH_U, KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,
         KC_LCTRL,KC_LGUI, KC_LALT, KC_NO,   KC_LGUI, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
     ),
    /*
     * +-------+-------+-------+-------+-------+-------+                +-------+-------+-------+-------+-------+-------+
     * |       |       |       |       |       |       |                |       |       |       |       |       |       |
     * +-------+-------+-------+-------+-------+-------+                +-------+-------+-------+-------+-------+-------+
     * |       |       |MS_BTN3|MS_BTN2|MS_BTN1|       |                | MS_L  | MS_D  | MS_U  | MS_R  |       |       |
     * +-------+-------+-------+-------+-------+-------+                +-------+-------+-------+-------+-------+-------+
     * | SHIFT |       |       |MS_WH_D|MS_WH_U|       |                |       |       |       |       |       |       |
     * +-------+-------+-------+-------+-------+-------+-----+    +-----+-------+-------+-------+-------+-------+-------+
     * | CTRL  | SUPER | ALT   |       |       |       | FN  |    |     |       |       |       |       |       |       |
     * +-------+-------+-------+-------+-------+-------+-----+    +-----+-------+-------+-------+-------+-------+-------+
    */
    [_FN4] = LAYOUT(
        KC_NO,     KC_NO,     KC_BTN4,       KC_F5,   KC_BTN5,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,    
        KC_NO,     C(KC_F4),  C(S(KC_TAB)),  KC_F6,   C(KC_TAB), C(S(KC_T)),                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_ENTER,    
        KC_LSFT,   KC_NO,     KC_NO,         C(KC_T), KC_NO,     KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,     
        KC_LCTRL,  KC_LGUI,   KC_LALT,       KC_3,    KC_LGUI,   KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO    
    )
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |PAST |FRESH|FUTUR|     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |CLOSE|PREV |FOCUS|NEXT |RECOV|                |PREV |VOLD |VOLU |NEXT |     |MUTE |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |SHIFT|     |     |NEW  |     |     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
     * |CTRL |SUPER| ALT |     |     |     |     |    | FN  |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
    */
    /* [_FN2] = LAYOUT( */
    /*     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO, */    
    /*     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_NO,   KC_ENTER, */    
    /*     KC_LSFT, KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_RSFT,  */    
    /*     KC_LCTRL,KC_LGUI, KC_LALT, KC_3,    KC_LGUI, KC_NO,   KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO */    
    /* ) */
    /*
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |     |     |     |     |     |     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+                +-----+-----+-----+-----+-----+-----+
     * |SHIFT|     |     |     |     |     |                |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
     * |CTRL |SUPER| ALT |     |     |     |     |    |     |     |     |     |     |     |     |
     * +-----+-----+-----+-----+-----+-----+-----+    +-----+-----+-----+-----+-----+-----+-----+
    */
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case QMKBEST:
            if (record->event.pressed) {
                // when keycode QMKBEST is pressed
                SEND_STRING("QMK is the best thing ever!");
            } else {
                // when keycode QMKBEST is released
            }
            break;
        case QMKURL:
            if (record->event.pressed) {
                // when keycode QMKURL is pressed
                SEND_STRING("https://qmk.fm/\n");
            } else {
                // when keycode QMKURL is released
            }
            break;
    }
    return true;
}

/*
void matrix_init_user(void) {

}

void matrix_scan_user(void) {

}

bool led_update_user(led_t led_state) {
    return true;
}
*/
