// -*- mode: c++ -*-
// Copyright 2016 Keyboardio, inc. <jesse@keyboard.io>
// See "LICENSE" for license details

#ifndef BUILD_INFORMATION
#define BUILD_INFORMATION "locally built"
#endif


/**
 * These #include directives pull in the Kaleidoscope firmware core,
 * as well as the Kaleidoscope plugins we use in the Model 01's firmware
 */


// The Kaleidoscope core
#include "Kaleidoscope.h"

// Support for storing the keymap in EEPROM
#include "Kaleidoscope-EEPROM-Settings.h"
#include "Kaleidoscope-EEPROM-Keymap.h"

// Support for communicating with the host via a simple Serial protocol
#include "Kaleidoscope-FocusSerial.h"

// Support for keys that move the mouse
#include "Kaleidoscope-MouseKeys.h"

// Support for macros
#include "Kaleidoscope-Macros.h"

// Support for controlling the keyboard's LEDs
#include "Kaleidoscope-LEDControl.h"

// Support for "Numpad" mode, which is mostly just the Numpad specific LED mode
#include "Kaleidoscope-NumPad.h"

// Support for the "Boot greeting" effect, which pulses the 'LED' button for 10s
// when the keyboard is connected to a computer (or that computer is powered on)
#include "Kaleidoscope-LEDEffect-BootGreeting.h"

// Support for an LED mode that lets one configure per-layer color maps
#include "Kaleidoscope-Colormap.h"

// // Support for Keyboardio's internal keyboard testing mode
// #include "Kaleidoscope-Model01-TestMode.h"

// Support for host power management (suspend & wakeup)
#include "Kaleidoscope-HostPowerManagement.h"

// Support for magic combos (key chords that trigger an action)
#include "Kaleidoscope-MagicCombo.h"

// Support for USB quirks, like changing the key state report protocol
#include "Kaleidoscope-USB-Quirks.h"

// Non default plugins:
// #include <Kaleidoscope-ModifierLayers.h> # keep this here as a reminder since nicer than shapeshift IMO (but was buggy)
#include <Kaleidoscope-ShapeShifter.h>
#include <Kaleidoscope-Heatmap.h>
// #include <Kaleidoscope-Qukeys.h>

enum {
       MACRO_PD_TILDE,
       MACRO_PD_ONE,
       MACRO_PD_TWO,
       MACRO_PD_THREE,
       MACRO_PD_FOUR,
       MACRO_PD_FIVE,
       MACRO_PD_SIX,
       MACRO_PD_SEVEN,
       MACRO_PD_EIGHT,
       MACRO_PD_NINE,
       MACRO_PD_ZERO,
       MACRO_PD_MINUS,
       MACRO_PD_PLUS,
       MACRO_PD_CLOSE_BRACKET
};

/**
  * Layers are "0-indexed" -- That is the first one is layer 0. The second one is layer 1.
  * The third one is layer 2.
  * This 'enum' lets us use names like QWERTY, FUNCTION, and NUMPAD in place of
  * the numbers 0, 1 and 2.
  *
  */

enum { PDVORAK, NUMPAD, FUNCTION }; // layers

// *INDENT-OFF*
KEYMAPS(
  // No key yet:`
  [PDVORAK] = KEYMAP_STACKED
  (M(MACRO_PD_TILDE), M(MACRO_PD_ONE), M(MACRO_PD_TWO), M(MACRO_PD_THREE), M(MACRO_PD_FOUR), M(MACRO_PD_FIVE),     Key_PrintScreen,
   Key_Delete,      Key_Semicolon,   Key_Comma,               Key_Period,               Key_P,         Key_Y,      M(MACRO_PD_PLUS),
   Key_CapsLock,    Key_A,           Key_O,                   Key_E,                    Key_U,         Key_I,
   Key_Backslash,   Key_Quote,       Key_Q,                   Key_J,                    Key_K,         Key_X,      Key_Escape,
   Key_Backspace,   Key_Tab,         Key_LeftControl, Key_LeftAlt,
   ShiftToLayer(NUMPAD),

   LockLayer(STENO),          M(MACRO_PD_SIX), M(MACRO_PD_SEVEN), M(MACRO_PD_EIGHT), M(MACRO_PD_NINE), M(MACRO_PD_ZERO), M(MACRO_PD_MINUS),
   M(MACRO_PD_CLOSE_BRACKET), Key_F,           Key_G,            Key_C,              Key_R,            Key_L,         Key_Slash,
                              Key_D,           Key_H,            Key_T,              Key_N,            Key_S,         Key_Minus,
   Key_RightAlt,              Key_B,           Key_M,            Key_W,              Key_V,            Key_Z,         Key_LeftAlt,
   LockLayer(FUNCTION)),
   Key_Enter,     Key_Spacebar,  Key_LeftShift, Key_LeftGui,

  [NUMPAD] =  KEYMAP_STACKED
  (Key_LEDEffectNext, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___, ___, ___, ___,
   ___, ___, ___, ___,
   ___,

   ___,  ___, Key_Keypad7, Key_Keypad8,   Key_Keypad9,        Key_KeypadSubtract, ___,
   ___,  ___, Key_Keypad4, Key_Keypad5,   Key_Keypad6,        Key_KeypadAdd,      ___,
         ___, Key_Keypad1, Key_Keypad2,   Key_Keypad3,        Key_Equals,         ___,
   ___,  ___, Key_Keypad0, Key_KeypadDot, Key_KeypadMultiply, Key_KeypadDivide,   Key_Enter,
   ___,  ___, ___, ___,
   ___),

  [FUNCTION] =  KEYMAP_STACKED
  (___,      Key_F1,           Key_F2,      Key_F3,        Key_F4,        Key_F5,           Key_CapsLock,
   ___,      ___,              Key_mouseUp, ___,           Key_mouseBtnR, Key_mouseWarpEnd, Key_mouseWarpNE,
   Key_Home, Key_mouseL,       Key_mouseDn, Key_mouseR,    Key_mouseBtnL, Key_mouseWarpNW,
   Key_End,  Key_PrintScreen,  Key_Insert,  Key_DownArrow, Key_UpArrow,   Key_mouseWarpSW,  Key_mouseWarpSE,
   ___,      ___,              ___,         ___,
   LSHIFT(Key_LeftControl),

   Consumer_ScanPreviousTrack, Key_F6,                 Key_F7,                   Key_F8,                   Key_F9,          Key_F10,          ___,
   Consumer_PlaySlashPause,    Consumer_ScanNextTrack, Key_LeftCurlyBracket,     Key_RightCurlyBracket,    Key_RightArrow, Key_RightArrow, Key_F11,
                               ___,                    Key_LeftArrow,            ___,            ___,     ___,   Key_F12,
   Key_PcApplication,          Consumer_Mute,          Consumer_VolumeDecrement, Consumer_VolumeIncrement, ___,             Key_Backslash,    Key_Pipe,
   ___, ___, Key_Enter, ___,
   ___)

) // KEYMAPS(
// *INDENT-ON*

static const kaleidoscope::ShapeShifter::dictionary_t shape_shift_dictionary[] PROGMEM = {
 {Key_NoKey, Key_NoKey},
};

bool wasShiftActive() {
    return kaleidoscope::hid::wasModifierKeyActive(Key_LeftShift) || kaleidoscope::hid::wasModifierKeyActive(Key_RightShift);
}

#define MACROSHIFT(shifted, unShifted) (\
  wasShiftActive()\
  ? MACRODOWN(T(shifted))\
  : keyToggledOn(keyState) \
      ? Macros.type(PSTR(unShifted)) : MACRO_NONE\
)

#define MACROSHIFT_SYMBOL(shifted, unShifted) (\
  wasShiftActive()\
  ? keyToggledOn(keyState) \
      ? Macros.type(PSTR(shifted)) : MACRO_NONE\
  : keyToggledOn(keyState) \
      ? Macros.type(PSTR(unShifted)) : MACRO_NONE\
)

const macro_t *macroAction(uint8_t macroIndex, uint8_t keyState) {
  switch (macroIndex) {
    case MACRO_PD_TILDE:
      return MACROSHIFT_SYMBOL("$", "~");
    case MACRO_PD_ONE:
      return MACROSHIFT_SYMBOL("&", "%");
    case MACRO_PD_TWO:
      return MACROSHIFT(7, "[");
    case MACRO_PD_THREE:
      return MACROSHIFT(5, "{");
    case MACRO_PD_FOUR:
      return MACROSHIFT(3, "}");
    case MACRO_PD_FIVE:
      return MACROSHIFT(1, "(");
    case MACRO_PD_SIX:
      return MACROSHIFT(9, "=");
    case MACRO_PD_SEVEN:
      return MACROSHIFT(0, "*");
    case MACRO_PD_EIGHT:
      return MACROSHIFT(2, ")");
    case MACRO_PD_NINE:
      return MACROSHIFT(4, "+");
    case MACRO_PD_ZERO:
      return MACROSHIFT(6, "]");
    case MACRO_PD_MINUS:
      return MACROSHIFT(8, "!");
    case MACRO_PD_PLUS:
      return MACROSHIFT_SYMBOL("#", "`");
    case MACRO_PD_CLOSE_BRACKET:
      return MACROSHIFT_SYMBOL("@", "^");
  }

  return MACRO_NONE;
}

/** toggleLedsOnSuspendResume toggles the LEDs off when the host goes to sleep,
 * and turns them back on when it wakes up.
 */
void toggleLedsOnSuspendResume(kaleidoscope::plugin::HostPowerManagement::Event event) {
  switch (event) {
  case kaleidoscope::plugin::HostPowerManagement::Suspend:
    LEDControl.set_all_leds_to({0, 0, 0});
    LEDControl.syncLeds();
    LEDControl.paused = true;
    break;
  case kaleidoscope::plugin::HostPowerManagement::Resume:
    LEDControl.paused = false;
    LEDControl.refreshAll();
    break;
  case kaleidoscope::plugin::HostPowerManagement::Sleep:
    break;
  }
}

/** The config for the heatmak colours
 * 
 */
static const cRGB heat_colors[] PROGMEM = {
  {  0,   0,   0}, // black
  { 25,  25, 255},  // red
  {255,  25,  25}, // blue
  { 25, 255,  25} // green
};

/** hostPowerManagementEventHandler dispatches power management events (suspend,
 * resume, and sleep) to other functions that perform action based on these
 * events.
 */
void hostPowerManagementEventHandler(kaleidoscope::plugin::HostPowerManagement::Event event) {
  toggleLedsOnSuspendResume(event);
}

/** This 'enum' is a list of all the magic combos used by the Model 01's
 * firmware The names aren't particularly important. What is important is that
 * each is unique.
 *
 * These are the names of your magic combos. They will be used by the
 * `USE_MAGIC_COMBOS` call below.
 */
enum {
  // Toggle between Boot (6-key rollover; for BIOSes and early boot) and NKRO
  // mode.
  COMBO_TOGGLE_NKRO_MODE
};

/** A tiny wrapper, to be used by MagicCombo.
 * This simply toggles the keyboard protocol via USBQuirks, and wraps it within
 * a function with an unused argument, to match what MagicCombo expects.
 */
static void toggleKeyboardProtocol(uint8_t combo_index) {
  USBQuirks.toggleKeyboardProtocol();
}

/** Magic combo list, a list of key combo and action pairs the firmware should
 * recognise.
 */
USE_MAGIC_COMBOS({.action = toggleKeyboardProtocol,
                  // Left Fn + Esc + Shift
                  .keys = { R3C6, R2C6, R3C7 }
                 });

// First, tell Kaleidoscope which plugins you want to use.
// The order can be important. For example, LED effects are
// added in the order they're listed here.
KALEIDOSCOPE_INIT_PLUGINS(
  // The EEPROMSettings & EEPROMKeymap plugins make it possible to have an
  // editable keymap in EEPROM.
  EEPROMSettings,
  EEPROMKeymap,
  
  // Qukeys,

  // Focus allows bi-directional communication with the host, and is the
  // interface through which the keymap in EEPROM can be edited.
  Focus,

  // FocusSettingsCommand adds a few Focus commands, intended to aid in
  // changing some settings of the keyboard, such as the default layer (via the
  // `settings.defaultLayer` command)
  FocusSettingsCommand,

  // FocusEEPROMCommand adds a set of Focus commands, which are very helpful in
  // both debugging, and in backing up one's EEPROM contents.
  FocusEEPROMCommand,

  // The boot greeting effect pulses the LED button for 10 seconds after the
  // keyboard is first connected
  BootGreetingEffect,

  // // The hardware test mode, which can be invoked by tapping Prog, LED and the
  // // left Fn button at the same time.
  // TestMode,

  // LEDControl provides support for other LED modes
  LEDControl,

  // Show which keys you use most
  HeatmapEffect,

  // We start with the LED effect that turns off all the LEDs.
  LEDOff,

  // The Colormap effect makes it possible to set up per-layer colormaps
  ColormapEffect,

  // The numpad plugin is responsible for lighting up the 'numpad' mode
  // with a custom LED effect
  NumPad,

  // The macros plugin adds support for macros
  Macros,

  // The MouseKeys plugin lets you add keys to your keymap which move the mouse.
  MouseKeys,

  // The HostPowerManagement plugin allows us to turn LEDs off when then host
  // goes to sleep, and resume them when it wakes up.
  HostPowerManagement,

  // The MagicCombo plugin lets you use key combinations to trigger custom
  // actions - a bit like Macros, but triggered by pressing multiple keys at the
  // same time.
  MagicCombo,

  // The USBQuirks plugin lets you do some things with USB that we aren't
  // comfortable - or able - to do automatically, but can be useful
  // nevertheless. Such as toggling the key report protocol between Boot (used
  // by BIOSes) and Report (NKRO).
  USBQuirks,



  ShapeShifter,
  GeminiPR
);

/** The 'setup' function is one of the two standard Arduino sketch functions.
 * It's called when your keyboard first powers up. This is where you set up
 * Kaleidoscope and any plugins.
 */
void setup() {
  HeatmapEffect.heat_colors = heat_colors;
  HeatmapEffect.heat_colors_length = 4;

  QUKEYS(
    kaleidoscope::Qukey(0, 2, 1, Key_LeftGui),      // A/cmd
    kaleidoscope::Qukey(0, 2, 2, Key_LeftAlt),      // S/alt
    kaleidoscope::Qukey(0, 2, 3, Key_LeftShift),    // F/shift
    kaleidoscope::Qukey(0, 2, 4, Key_LeftControl),  // D/ctrl
    kaleidoscope::Qukey(0, 2, 14, Key_LeftGui),      // A/cmd
    kaleidoscope::Qukey(0, 2, 13, Key_LeftAlt),      // S/alt
    kaleidoscope::Qukey(0, 2, 12, Key_LeftShift),    // F/shift
    kaleidoscope::Qukey(0, 2, 11, Key_LeftControl)  // D/ctrl
  )
  Qukeys.setTimeout(200);
  Qukeys.setReleaseDelay(20);

  Serial.begin(9600);

  // First, call Kaleidoscope's internal setup function~~  Kaleidoscope.setup();

  // While we hope to improve this in the future, the NumPad plugin
  // needs to be explicitly told which keymap layer is your numpad layer
  NumPad.numPadLayer = NUMPAD;

  // We want to make sure that the firmware starts with LED effects off
  // This avoids over-taxing devices that don't have a lot of power to share
  // with USB devices
  // LEDOff.activate();
  HeatmapEffect.activate();

  // To make the keymap editable without flashing new firmware, we store
  // additional layers in EEPROM. For now, we reserve space for five layers. If
  // one wants to use these layers, just set the default layer to one in EEPROM,
  // by using the `settings.defaultLayer` Focus command, or by using the
  // `keymap.onlyCustom` command to use EEPROM layers only.
  EEPROMKeymap.setup(5);

  // We need to tell the Colormap plugin how many layers we want to have custom
  // maps for. To make things simple, we set it to five layers, which is how
  // many editable layers we have (see above).
  ColormapEffect.max_layers(5);



  // Own Libs:

  ShapeShifter.dictionary = shape_shift_dictionary;

}

/** loop is the second of the standard Arduino sketch functions.
  * As you might expect, it runs in a loop, never exiting.
  *
  * For Kaleidoscope-based keyboard firmware, you usually just want to
  * call Kaleidoscope.loop(); and not do anything custom here.
  */

void loop() {
  Kaleidoscope.loop();
}
