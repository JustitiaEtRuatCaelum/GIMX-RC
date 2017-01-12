/*
 Copyright (c) 2011 Mathieu Laurendeau <mat.lau@laposte.net>
 License: GPLv3
 */

#include "../events.h"

/*
 * This table gives a correspondence between a char string and a button code.
 */
const char* butnames[GE_MOUSE_BUTTONS_MAX] =
{
    "UNDEFINED",
    "BUTTON_LEFT",
    "BUTTON_MIDDLE",
    "BUTTON_RIGHT",
    "BUTTON_X1",
    "BUTTON_X2",
    "BUTTON_WHEELUP",
    "BUTTON_WHEELDOWN",
    "BUTTON_X3",
    "BUTTON_X4",
    "BUTTON_X5",
    "BUTTON_X6",
};

/*
 * This table gives a correspondence between a SDL scancode and a key code.
 */
static const unsigned char keycodes[] =
{
    [SDL_SCANCODE_UNKNOWN] = KEY_UNKNOWN,
    [SDL_SCANCODE_A] = KEY_A,
    [SDL_SCANCODE_B] = KEY_B,
    [SDL_SCANCODE_C] = KEY_C,
    [SDL_SCANCODE_D] = KEY_D,
    [SDL_SCANCODE_E] = KEY_E,
    [SDL_SCANCODE_F] = KEY_F,
    [SDL_SCANCODE_G] = KEY_G,
    [SDL_SCANCODE_H] = KEY_H,
    [SDL_SCANCODE_I] = KEY_I,
    [SDL_SCANCODE_J] = KEY_J,
    [SDL_SCANCODE_K] = KEY_K,
    [SDL_SCANCODE_L] = KEY_L,
    [SDL_SCANCODE_M] = KEY_M,
    [SDL_SCANCODE_N] = KEY_N,
    [SDL_SCANCODE_O] = KEY_O,
    [SDL_SCANCODE_P] = KEY_P,
    [SDL_SCANCODE_Q] = KEY_Q,
    [SDL_SCANCODE_R] = KEY_R,
    [SDL_SCANCODE_S] = KEY_S,
    [SDL_SCANCODE_T] = KEY_T,
    [SDL_SCANCODE_U] = KEY_U,
    [SDL_SCANCODE_V] = KEY_V,
    [SDL_SCANCODE_W] = KEY_W,
    [SDL_SCANCODE_X] = KEY_X,
    [SDL_SCANCODE_Y] = KEY_Y,
    [SDL_SCANCODE_Z] = KEY_Z,
    [SDL_SCANCODE_1] = KEY_1,
    [SDL_SCANCODE_2] = KEY_2,
    [SDL_SCANCODE_3] = KEY_3,
    [SDL_SCANCODE_4] = KEY_4,
    [SDL_SCANCODE_5] = KEY_5,
    [SDL_SCANCODE_6] = KEY_6,
    [SDL_SCANCODE_7] = KEY_7,
    [SDL_SCANCODE_8] = KEY_8,
    [SDL_SCANCODE_9] = KEY_9,
    [SDL_SCANCODE_0] = KEY_0,
    [SDL_SCANCODE_RETURN] = KEY_ENTER,
    [SDL_SCANCODE_ESCAPE] = KEY_ESC,
    [SDL_SCANCODE_BACKSPACE] = KEY_BACKSPACE,
    [SDL_SCANCODE_TAB] = KEY_TAB,
    [SDL_SCANCODE_SPACE] = KEY_SPACE,
    [SDL_SCANCODE_MINUS] = KEY_MINUS,
    [SDL_SCANCODE_EQUALS] = KEY_EQUAL,
    [SDL_SCANCODE_LEFTBRACKET] = KEY_LEFTBRACE,
    [SDL_SCANCODE_RIGHTBRACKET] = KEY_RIGHTBRACE,
    [SDL_SCANCODE_BACKSLASH] = KEY_BACKSLASH,
    [SDL_SCANCODE_NONUSHASH] = KEY_BACKSLASH,
    [SDL_SCANCODE_SEMICOLON] = KEY_SEMICOLON,
    [SDL_SCANCODE_APOSTROPHE] = KEY_APOSTROPHE,
    [SDL_SCANCODE_GRAVE] = KEY_GRAVE,
    [SDL_SCANCODE_COMMA] = KEY_COMMA,
    [SDL_SCANCODE_PERIOD] = KEY_DOT,
    [SDL_SCANCODE_SLASH] = KEY_SLASH,
    [SDL_SCANCODE_CAPSLOCK] = KEY_CAPSLOCK,
    [SDL_SCANCODE_F1] = KEY_F1,
    [SDL_SCANCODE_F2] = KEY_F2,
    [SDL_SCANCODE_F3] = KEY_F3,
    [SDL_SCANCODE_F4] = KEY_F4,
    [SDL_SCANCODE_F5] = KEY_F5,
    [SDL_SCANCODE_F6] = KEY_F6,
    [SDL_SCANCODE_F7] = KEY_F7,
    [SDL_SCANCODE_F8] = KEY_F8,
    [SDL_SCANCODE_F9] = KEY_F9,
    [SDL_SCANCODE_F10] = KEY_F10,
    [SDL_SCANCODE_F11] = KEY_F11,
    [SDL_SCANCODE_F12] = KEY_F12,
    [SDL_SCANCODE_PRINTSCREEN] = KEY_PRINT,
    [SDL_SCANCODE_SCROLLLOCK] = KEY_SCROLLLOCK,
    [SDL_SCANCODE_PAUSE] = KEY_PAUSE,
    [SDL_SCANCODE_INSERT] = KEY_INSERT,
    [SDL_SCANCODE_HOME] = KEY_HOME,
    [SDL_SCANCODE_PAGEUP] = KEY_PAGEUP,
    [SDL_SCANCODE_DELETE] = KEY_DELETE,
    [SDL_SCANCODE_END] = KEY_END,
    [SDL_SCANCODE_PAGEDOWN] = KEY_PAGEDOWN,
    [SDL_SCANCODE_RIGHT] = KEY_RIGHT,
    [SDL_SCANCODE_LEFT] = KEY_LEFT,
    [SDL_SCANCODE_DOWN] = KEY_DOWN,
    [SDL_SCANCODE_UP] = KEY_UP,
    [SDL_SCANCODE_NUMLOCKCLEAR] = KEY_NUMLOCK,
    [SDL_SCANCODE_KP_DIVIDE] = KEY_KPSLASH,
    [SDL_SCANCODE_KP_MULTIPLY] = KEY_KPASTERISK,
    [SDL_SCANCODE_KP_MINUS] = KEY_KPMINUS,
    [SDL_SCANCODE_KP_PLUS] = KEY_KPPLUS,
    [SDL_SCANCODE_KP_ENTER] = KEY_KPENTER,
    [SDL_SCANCODE_KP_1] = KEY_KP1,
    [SDL_SCANCODE_KP_2] = KEY_KP2,
    [SDL_SCANCODE_KP_3] = KEY_KP3,
    [SDL_SCANCODE_KP_4] = KEY_KP4,
    [SDL_SCANCODE_KP_5] = KEY_KP5,
    [SDL_SCANCODE_KP_6] = KEY_KP6,
    [SDL_SCANCODE_KP_7] = KEY_KP7,
    [SDL_SCANCODE_KP_8] = KEY_KP8,
    [SDL_SCANCODE_KP_9] = KEY_KP9,
    [SDL_SCANCODE_KP_0] = KEY_KP0,
    [SDL_SCANCODE_KP_PERIOD] = KEY_KPDOT,
    [SDL_SCANCODE_NONUSBACKSLASH] = KEY_102ND,
    [SDL_SCANCODE_APPLICATION] = KEY_LEFTMETA,
    [SDL_SCANCODE_POWER] = KEY_POWER,
    [SDL_SCANCODE_KP_EQUALS] = KEY_KPEQUAL,
    [SDL_SCANCODE_F13] = KEY_F13,
    [SDL_SCANCODE_F14] = KEY_F14,
    [SDL_SCANCODE_F15] = KEY_F15,
    [SDL_SCANCODE_F16] = KEY_F16,
    [SDL_SCANCODE_F17] = KEY_F17,
    [SDL_SCANCODE_F18] = KEY_F18,
    [SDL_SCANCODE_F19] = KEY_F19,
    [SDL_SCANCODE_F20] = KEY_F20,
    [SDL_SCANCODE_F21] = KEY_F21,
    [SDL_SCANCODE_F22] = KEY_F22,
    [SDL_SCANCODE_F23] = KEY_F23,
    [SDL_SCANCODE_F24] = KEY_F24,
    //[SDL_SCANCODE_EXECUTE] = KEY_EXECUTE,
    [SDL_SCANCODE_HELP] = KEY_HELP,
    [SDL_SCANCODE_MENU] = KEY_MENU,
    //[SDL_SCANCODE_SELECT] = KEY_SELECT,
    [SDL_SCANCODE_STOP] = KEY_STOP,
    [SDL_SCANCODE_AGAIN] = KEY_AGAIN,
    [SDL_SCANCODE_UNDO] = KEY_UNDO,
    [SDL_SCANCODE_CUT] = KEY_CUT,
    [SDL_SCANCODE_COPY] = KEY_COPY,
    [SDL_SCANCODE_PASTE] = KEY_PASTE,
    [SDL_SCANCODE_FIND] = KEY_FIND,
    [SDL_SCANCODE_MUTE] = KEY_MUTE,
    [SDL_SCANCODE_VOLUMEUP] = KEY_VOLUMEUP,
    [SDL_SCANCODE_VOLUMEDOWN] = KEY_VOLUMEDOWN,
    [SDL_SCANCODE_KP_COMMA] = KEY_KPCOMMA,
    [SDL_SCANCODE_ALTERASE] = KEY_ALTERASE,
    [SDL_SCANCODE_SYSREQ] = KEY_SYSRQ,
    [SDL_SCANCODE_CANCEL] = KEY_CANCEL,

    [SDL_SCANCODE_KP_LEFTPAREN] = KEY_KPLEFTPAREN,
    [SDL_SCANCODE_KP_RIGHTPAREN] = KEY_KPRIGHTPAREN,

    [SDL_SCANCODE_LCTRL] = KEY_LEFTCTRL,
    [SDL_SCANCODE_LSHIFT] = KEY_LEFTSHIFT,
    [SDL_SCANCODE_LALT] = KEY_LEFTALT,
    [SDL_SCANCODE_LGUI] = KEY_LEFTMETA,
    [SDL_SCANCODE_RCTRL] = KEY_RIGHTCTRL,
    [SDL_SCANCODE_RSHIFT] = KEY_RIGHTSHIFT,
    [SDL_SCANCODE_RALT] = KEY_RIGHTALT,
    [SDL_SCANCODE_RGUI] = KEY_RIGHTMETA,
    //[SDL_SCANCODE_MODE] = KEY_MODE,
    [SDL_SCANCODE_AUDIONEXT] = KEY_NEXTSONG,
    [SDL_SCANCODE_AUDIOPREV] = KEY_PREVIOUSSONG,
    [SDL_SCANCODE_AUDIOSTOP] = KEY_STOP,
    [SDL_SCANCODE_AUDIOPLAY] = KEY_PLAYPAUSE,
    [SDL_SCANCODE_AUDIOMUTE] = KEY_MUTE,
    //[SDL_SCANCODE_MEDIASELECT] = KEY_MEDIASELECT,
    [SDL_SCANCODE_WWW] = KEY_WWW,
    [SDL_SCANCODE_MAIL] = KEY_MAIL,
    [SDL_SCANCODE_CALCULATOR] = KEY_CALC,
    [SDL_SCANCODE_COMPUTER] = KEY_COMPUTER,
    [SDL_SCANCODE_AC_SEARCH] = KEY_SEARCH,
    [SDL_SCANCODE_AC_HOME] = KEY_HOMEPAGE,
    [SDL_SCANCODE_AC_BACK] = KEY_BACK,
    [SDL_SCANCODE_AC_FORWARD] = KEY_FORWARD,
    [SDL_SCANCODE_AC_STOP] = KEY_STOP,
    [SDL_SCANCODE_AC_REFRESH] = KEY_REFRESH,
    [SDL_SCANCODE_AC_BOOKMARKS] = KEY_BOOKMARKS,
    [SDL_SCANCODE_BRIGHTNESSDOWN] = KEY_BRIGHTNESSDOWN,
    [SDL_SCANCODE_BRIGHTNESSUP] = KEY_BRIGHTNESSUP,
    [SDL_SCANCODE_DISPLAYSWITCH] = KEY_SWITCHVIDEOMODE,
    [SDL_SCANCODE_KBDILLUMTOGGLE] = KEY_KBDILLUMTOGGLE,
    [SDL_SCANCODE_KBDILLUMDOWN] = KEY_KBDILLUMDOWN,
    [SDL_SCANCODE_KBDILLUMUP] = KEY_KBDILLUMUP,
    [SDL_SCANCODE_EJECT] = KEY_EJECTCD,
    [SDL_SCANCODE_SLEEP] = KEY_SLEEP,
};

unsigned char get_keycode_from_scancode(unsigned short scancode)
{
  if(scancode < sizeof(keycodes)/sizeof(*keycodes))
  {
    return keycodes[scancode];
  }

  return keycodes[0];
}