/* Copyright 2022 Wyeth Greenlaw Rollins (@wyethGR)
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

enum custom_layers {
    _QWERTY,
    _LOWER,
    _RAISE,
    _ADJUST,
    _GAME,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define GAME  TG(_GAME)

#define _ESC MT(MOD_LGUI, KC_ESC) // escape on tap, gui on hold
#define _SFT MT(MOD_LSFT, KC_ENT) // enter on tap, shift on hold
#define _SPC MT(MOD_LCTL, KC_SPC) // space on tap, ctrl on hold

const uint16_t PROGMEM df_tab[] = {KC_D, KC_F, COMBO_END};
const uint16_t PROGMEM jk_alt[] = {KC_J, KC_K, COMBO_END};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * .-----------------------------------------------------------------------------------.
 * |   Q  |   W  |   E  |   R  |   T  |      |      |   Y  |   U  |   I  |   O  |   P  |
 * +------+------+------+------+-------------+------+------+------+------+------+------+
 * |   A  |   S  |   D  |   F  |   G  |      |      |   H  |   J  |   K  |   L  | :  ; |
 * +------+------+------+------+------|------+------+------+------+------+------+------+
 * |   Z  |   X  |   C  |   V  |   B  |      |      |   N  |   M  | <  , | >  . | ?  / |
 * +------+------+------+------+------+------+------+------+------+------+------+------+
 * |      |      | Esc  |Enter |Raise |      |      |Lower |Space |Delete|      |      |
 * .-----------------------------------------------------------------------------------.
 * esc   on tap, gui   on hold
 * enter on tap, shift on hold
 * space on tap, ctl   on hold
 */
[_QWERTY] = LAYOUT_ortho_4x12(
  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,   XXXXXXX, XXXXXXX, KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,
  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,   XXXXXXX, XXXXXXX, KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,
  KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   XXXXXXX, XXXXXXX, KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,
  XXXXXXX, XXXXXXX, _ESC,    _SFT,    RAISE,  XXXXXXX, XXXXXXX, LOWER,   _SPC,    KC_BSPC, XXXXXXX, XXXXXXX
),

/* Lower
 * ,-----------------------------------------------------------------------------------.
 * |   `  |   !  |   @  |   #  |   $  |      |      |   %  |   ^  |   &  |   *  |  \   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   ~  |   |  |   [  |   ]  |   {  |      |      |   }  |   (  |   )  |   "  |  '   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Shift |   +  |   =  |   -  |  _   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |RAISE |      |      |      |      |      |      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_LOWER] = LAYOUT_ortho_4x12(
  KC_GRV,  KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  XXXXXXX, XXXXXXX, KC_PERC, KC_CIRC, KC_AMPR, KC_ASTR, KC_BSLS,
  KC_TILD, KC_PIPE, KC_LBRC, KC_RBRC, KC_LCBR, XXXXXXX, XXXXXXX, KC_RCBR, KC_LPRN, KC_RPRN, KC_DQUO, KC_QUOT,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_LSFT, KC_PLUS, KC_EQL,  KC_MINS, KC_UNDS,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, RAISE,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
),

/* Raise
 * ,-----------------------------------------------------------------------------------.
 * |   1  |   2  |   3  |   4  |   5  |      |      |   6  |   7  |   8  |   9  |   0  |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   F1 |   F2 |   F3 |   F4 |   F5 |      |      |      |  GUI |  SFT |  CTL |  ALT |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |   F6 |   F7 |   F8 |   F9 |  F10 |      |      |  F11 |  F12 |  ,   |  .   |  /   |
 * |------+------+------+------+------+------+------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |Lower |Space |Delete|      |      |
 * `-----------------------------------------------------------------------------------'
 */
[_RAISE] = LAYOUT_ortho_4x12(
  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    XXXXXXX, XXXXXXX, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,
  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   XXXXXXX, XXXXXXX, XXXXXXX, KC_LGUI, KC_LSFT, KC_LCTL, KC_LALT,
  KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  XXXXXXX, XXXXXXX, KC_F11,  KC_F12,  KC_COMM, KC_DOT,  KC_SLSH,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, LOWER,   _SPC,    KC_BSPC, XXXXXXX, XXXXXXX
),

/* Adjust (Lower + Raise)
 * ,-----------------------------------------------------------------------------------.
 * |PntSrn|      |      | PgUp |BrtUp |      |      | Mute |VolDw |VolUp |Ply/Ps|RESET |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      | PgDw |BrtDw |      |      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      | Sft  | Ctl  |      |      |      |      | Prev | Next |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * |      |      |      |      |      |      |      |      |      |      |      | GAME |
 * `-----------------------------------------------------------------------------------'
 */
[_ADJUST] =  LAYOUT_ortho_4x12(
  KC_PSCR, XXXXXXX, XXXXXXX, KC_PGUP, KC_BRIU, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_MPLY, RESET,
  XXXXXXX, XXXXXXX, XXXXXXX, KC_PGDN, KC_BRID, XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, XXXXXXX,
  XXXXXXX, XXXXXXX, KC_LSFT, KC_LCTL, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPRV, KC_MNXT, XXXXXXX, XXXXXXX,
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME
),

/* GAME
 * ,-----------------------------------------------------------------------------------.
 * | ESC  |  1   |  2   |  3   |  4   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | TAB  |  q   |  w   |  e   |  r   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | SFT  |  a   |  s   |  d   |  f   |      |      |      |      |      |      |      |
 * |------+------+------+------+------+------|------+------+------+------+------+------|
 * | CTL  |  z   |  x   |  ALT | SPC  |      |      |      |      |      |      | GAME |
 * `-----------------------------------------------------------------------------------'
 */
[_GAME] =  LAYOUT_ortho_4x12(
  KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
  KC_LCTL, KC_Z,    KC_X,    KC_LALT, KC_SPC,  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, GAME
)
};

combo_t key_combos[COMBO_COUNT] = {
  COMBO(df_tab, KC_TAB),
  COMBO(jk_alt, KC_LALT),
};

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}        

uint16_t get_tapping_term(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case _SFT:
      return TAPPING_TERM - 100;
    default:
      return TAPPING_TERM;
  }
}
