#ifndef RNJ_DEFINES_H
#define RNJ_DEFINES_H

/* ������������ */
#define RNJ_DRAW_ROUND_LENGTH 4096 /* ����� ������� ��������� */
#define RNJ_SPRITE_NUM_POINT -1 /* ����� ������� ��� ����� */
#define RNJ_SPRITE_NUM_LINE -2 /* ����� ������� ��� ����� */
#define RNJ_SPRITE_NUM_RECT -3 /* ����� ������� ��� �������������� */
#define RNJ_SPRITE_NUM_FILLED_RECT -4 /* ����� ������� ��� ����������� �������������� */
#define RNJ_SPRITE_NUM_FILL -5 /* ����� ������� ������� ������ */

/* ����� ������ */
#ifdef LINPUT_ALLEGRO5
	#include "allegro5/allegro.h"
    #define RNJ_KEYS_COUNT ALLEGRO_KEY_MAX
#endif
#ifdef LINPUT_SDL12
	#include "SDL/SDL.h"
	#define RNJ_KEYS_COUNT SDLK_LAST
#endif
#ifdef LINPUT_SDL2
	#include "SDL2/SDL.h"
	#define RNJ_KEYS_COUNT SDL_NUM_SCANCODES
#endif

/* ��������� ��������� ������� */
#define DRAW_FLIP_NONE 0x00000000
#define DRAW_FLIP_HORIZONTAL 0x00000001
#define DRAW_FLIP_VERTICAL 0x00000002
#define DRAW_FLIP_BOTH 0x00000003

/* ���� ��������� ���� */
#define MT_NONE -1 /* �� ��������� ��� */
#define MT_INFO 0 /* ���������� */
#define MT_WARNING 1 /* �������������� */
#define MT_ERROR 2 /* ������ */

/* ���� ���������� ���� */
#define DIALOG_TYPE_ERROR 1 /* ������ */
#define DIALOG_TYPE_WARNING 2 /* �������������� */
#define DIALOG_TYPE_INFO 3 /* ���������� */

/* ������ �������� ������ */
#define FM_WRITE "w" /* ����� ������ � ���� */
#define FM_APPEND "a" /* ����� �������� � ����� ����� */

/* ���� ��������� �� ������� */
#define TTF_INIT_ERROR -1 /* ������ ������������� TTF API */

/* ��������� ��������� */
#ifdef LTIMER_ALLEGRO5
	#define ONE_SECOND 1000.0 /* ���� ������� � ������������ */
#else
	#define ONE_SECOND 1000 /* ���� ������� � ������������ */
#endif

/* ����� ����� �������������� ������ */
#define WRAP_NOWRAP 0 /* ��� �������� */

/* ��������� ��������������� �������� ��������� */
#define ZAXIS_COORD 0 /* ���������� �� ��� z ��� ���� �������� */
#define ZAXIS_LENGTH 32 /* ����� �� ��� z ��� ���� �������� */

/* �������� ��������� */
#define COORD_INIT 0 /* ��������� ���������� */

/* ��������� ����������� ������ */
#define PHYS_SPACE_NONE 0 /* ���������� ������������ */
#define PHYS_JOINT_MAX_SIZE 0 /* ������������ ������ ����������. ������ ������ ���� ����� ���� */
#define PHYS_MAX_CONTACTS 16 /* ������������ ���������� ��������� ��������������� ���� ��� */
#define PHYS_COLLIDE_DATA 0 /* ��������� �� �����-�� �����. ������ 0 */

/* ������ */
#define BASE_DECIMAL 10 /* ��������� ���������� ������� */
#define ASCII_ZERO_CODE 0x30 /* ��� ������� "0" */
#define X32_MAX_INT_DIGITS 10/* ������������ ����� ������ � ���� int �� 32-��������� ��������� */

/* ������� ���� ������� */
#ifdef LS_LUA
    #define SF_MAIN "Main.lua"
#endif
#ifdef LS_SQUIRREL
    #define SF_MAIN "Main.nut"
#endif

/* ��������� ��������� */
#ifdef LSPRITES_SDL2_IMAGE
	#define FLIP_NONE SDL_FLIP_NONE
	#define FLIP_HORIZONTAL SDL_FLIP_HORIZONTAL
	#define FLIP_VERTICAL SDL_FLIP_VERTICAL
	#define FLIP_BOTH (SDL_FLIP_HORIZONTAL | SDL_FLIP_VERTICAL)
#endif

/* ���� ������ */
#if defined(LINPUT_SDL2) || defined(LINPUT_NATIVE)
	#define RNJ_KEY_UNKNOWN 0
	#define RNJ_KEY_A 4
	#define RNJ_KEY_B 5
	#define RNJ_KEY_C 6
	#define RNJ_KEY_D 7
	#define RNJ_KEY_E 8
	#define RNJ_KEY_F 9
	#define RNJ_KEY_G 10
	#define RNJ_KEY_H 11
	#define RNJ_KEY_I 12
	#define RNJ_KEY_J 13
	#define RNJ_KEY_K 14
	#define RNJ_KEY_L 15
	#define RNJ_KEY_M 16
	#define RNJ_KEY_N 17
	#define RNJ_KEY_O 18
	#define RNJ_KEY_P 19
	#define RNJ_KEY_Q 20
	#define RNJ_KEY_R 21
	#define RNJ_KEY_S 22
	#define RNJ_KEY_T 23
	#define RNJ_KEY_U 24
	#define RNJ_KEY_V 25
	#define RNJ_KEY_W 26
	#define RNJ_KEY_X 27
	#define RNJ_KEY_Y 28
	#define RNJ_KEY_Z 29

	#define RNJ_KEY_1 30
	#define RNJ_KEY_2 31
	#define RNJ_KEY_3 32
	#define RNJ_KEY_4 33
	#define RNJ_KEY_5 34
	#define RNJ_KEY_6 35
	#define RNJ_KEY_7 36
	#define RNJ_KEY_8 37
	#define RNJ_KEY_9 38
	#define RNJ_KEY_0 39

	#define RNJ_KEY_RETURN 40
	#define RNJ_KEY_ESCAPE 41
	#define RNJ_KEY_ESC 41
	#define RNJ_KEY_BACKSPACE 42
	#define RNJ_KEY_TAB 43
	#define RNJ_KEY_SPACE 44

	#define RNJ_KEY_MINUS 45
	#define RNJ_KEY_EQUALS 46
	#define RNJ_KEY_LEFTBRACKET 47
	#define RNJ_KEY_RIGHTBRACKET 48
	#define RNJ_KEY_BACKSLASH 49
	#define RNJ_KEY_NONUSHASH 50
	#define RNJ_KEY_SEMICOLON 51
	#define RNJ_KEY_APOSTROPHE 52
	#define RNJ_KEY_GRAVE 53
	#define RNJ_KEY_TILDE 53
	#define RNJ_KEY_COMMA 54
	#define RNJ_KEY_PERIOD 55
	#define RNJ_KEY_SLASH 56

	#define RNJ_KEY_CAPSLOCK 57

	#define RNJ_KEY_F1 58
	#define RNJ_KEY_F2 59
	#define RNJ_KEY_F3 60
	#define RNJ_KEY_F4 61
	#define RNJ_KEY_F5 62
	#define RNJ_KEY_F6 63
	#define RNJ_KEY_F7 64
	#define RNJ_KEY_F8 65
	#define RNJ_KEY_F9 66
	#define RNJ_KEY_F10 67
	#define RNJ_KEY_F11 68
	#define RNJ_KEY_F12 69

	#define RNJ_KEY_PRINTSCREEN 70
	#define RNJ_KEY_SCROLLLOCK 71
	#define RNJ_KEY_PAUSE 72
	#define RNJ_KEY_INSERT 73
	#define RNJ_KEY_HOME 74
	#define RNJ_KEY_PAGEUP 75
	#define RNJ_KEY_DELETE 76
	#define RNJ_KEY_END 77
	#define RNJ_KEY_PAGEDOWN 78

	#define RNJ_KEY_RIGHT 79
	#define RNJ_KEY_LEFT 80
	#define RNJ_KEY_DOWN 81
	#define RNJ_KEY_UP 82

	#define RNJ_KEY_NUMLOCK 83
	#define RNJ_KEY_KP_DIVIDE 84
	#define RNJ_KEY_KP_MULTIPLY 85
	#define RNJ_KEY_KP_MINUS 86
	#define RNJ_KEY_KP_PLUS 87
	#define RNJ_KEY_KP_ENTER 88
	#define RNJ_KEY_KP_1 89
	#define RNJ_KEY_KP_2 90
	#define RNJ_KEY_KP_3 91
	#define RNJ_KEY_KP_4 92
	#define RNJ_KEY_KP_5 93
	#define RNJ_KEY_KP_6 94
	#define RNJ_KEY_KP_7 95
	#define RNJ_KEY_KP_8 96
	#define RNJ_KEY_KP_9 97
	#define RNJ_KEY_KP_0 98
	#define RNJ_KEY_KP_PERIOD 99

	#define RNJ_KEY_APPLICATION 101
	#define RNJ_KEY_CONTEXT 101
	#define RNJ_KEY_LCTRL 224
	#define RNJ_KEY_LSHIFT 225
	#define RNJ_KEY_LALT 226
	#define RNJ_KEY_LGUI 227
	#define RNJ_KEY_LWINDOWS 227
	#define RNJ_KEY_RCTRL 228
	#define RNJ_KEY_RSHIFT 229
	#define RNJ_KEY_RALT 230
	#define RNJ_KEY_RGUI 231
	#define RNJ_KEY_RWINDOWS 231
#endif

#ifdef LINPUT_ALLEGRO42
	#include "allegro42/allegro.h"
#endif

#ifdef LINPUT_ALLEGRO5
	#define RNJ_KEY_UNKNOWN 107
	#define RNJ_KEY_A 1
	#define RNJ_KEY_B 2
	#define RNJ_KEY_C 3
	#define RNJ_KEY_D 4
	#define RNJ_KEY_E 5
	#define RNJ_KEY_F 6
	#define RNJ_KEY_G 7
	#define RNJ_KEY_H 8
	#define RNJ_KEY_I 9
	#define RNJ_KEY_J 10
	#define RNJ_KEY_K 11
	#define RNJ_KEY_L 12
	#define RNJ_KEY_M 13
	#define RNJ_KEY_N 14
	#define RNJ_KEY_O 15
	#define RNJ_KEY_P 16
	#define RNJ_KEY_Q 17
	#define RNJ_KEY_R 18
	#define RNJ_KEY_S 19
	#define RNJ_KEY_T 20
	#define RNJ_KEY_U 21
	#define RNJ_KEY_V 22
	#define RNJ_KEY_W 23
	#define RNJ_KEY_X 24
	#define RNJ_KEY_Y 25
	#define RNJ_KEY_Z 26

	#define RNJ_KEY_1 27
	#define RNJ_KEY_2 28
	#define RNJ_KEY_3 29
	#define RNJ_KEY_4 30
	#define RNJ_KEY_5 31
	#define RNJ_KEY_6 32
	#define RNJ_KEY_7 33
	#define RNJ_KEY_8 34
	#define RNJ_KEY_9 35
	#define RNJ_KEY_0 36

	#define RNJ_KEY_RETURN 91
	#define RNJ_KEY_ESCAPE 59
	#define RNJ_KEY_ESC 59
	#define RNJ_KEY_BACKSPACE 63
	#define RNJ_KEY_TAB 64
	#define RNJ_KEY_SPACE 75

	#define RNJ_KEY_MINUS 61
	#define RNJ_KEY_EQUALS 62
	#define RNJ_KEY_LEFTBRACKET 66
	#define RNJ_KEY_RIGHTBRACKET 67
	#define RNJ_KEY_BACKSLASH 70
	#define RNJ_KEY_NONUSHASH KEY_UNKNOWN
	#define RNJ_KEY_SEMICOLON 68
	#define RNJ_KEY_APOSTROPHE 69
	#define RNJ_KEY_GRAVE 60
	#define RNJ_KEY_TILDE 60
	#define RNJ_KEY_COMMA 72
	#define RNJ_KEY_PERIOD 73
	#define RNJ_KEY_SLASH 74

	#define RNJ_KEY_CAPSLOCK 226

	#define RNJ_KEY_F1 47
	#define RNJ_KEY_F2 48
	#define RNJ_KEY_F3 49
	#define RNJ_KEY_F4 50
	#define RNJ_KEY_F5 51
	#define RNJ_KEY_F6 52
	#define RNJ_KEY_F7 53
	#define RNJ_KEY_F8 54
	#define RNJ_KEY_F9 55
	#define RNJ_KEY_F10 56
	#define RNJ_KEY_F11 57
	#define RNJ_KEY_F12 58

	#define RNJ_KEY_PRINTSCREEN 92
	#define RNJ_KEY_SCROLLLOCK 224
	#define RNJ_KEY_PAUSE 93
	#define RNJ_KEY_INSERT 76
	#define RNJ_KEY_HOME 78
	#define RNJ_KEY_PAGEUP 80
	#define RNJ_KEY_DELETE 77
	#define RNJ_KEY_END 79
	#define RNJ_KEY_PAGEDOWN 81

	#define RNJ_KEY_RIGHT 83
	#define RNJ_KEY_LEFT 82
	#define RNJ_KEY_DOWN 85
	#define RNJ_KEY_UP 84

	#define RNJ_KEY_NUMLOCK 225
	#define RNJ_KEY_KP_DIVIDE 86
	#define RNJ_KEY_KP_MULTIPLY 87
	#define RNJ_KEY_KP_MINUS 88
	#define RNJ_KEY_KP_PLUS 89
	#define RNJ_KEY_KP_ENTER 91
	#define RNJ_KEY_KP_1 37
	#define RNJ_KEY_KP_2 38
	#define RNJ_KEY_KP_3 39
	#define RNJ_KEY_KP_4 40
	#define RNJ_KEY_KP_5 41
	#define RNJ_KEY_KP_6 42
	#define RNJ_KEY_KP_7 43
	#define RNJ_KEY_KP_8 44
	#define RNJ_KEY_KP_9 45
	#define RNJ_KEY_KP_0 46
	#define RNJ_KEY_KP_PERIOD 90

	#define RNJ_KEY_APPLICATION KEY_UNKNOWN
	#define RNJ_KEY_CONTEXT KEY_UNKNOWN
	#define RNJ_KEY_LCTRL 217
	#define RNJ_KEY_LSHIFT 215
	#define RNJ_KEY_LALT 219
	#define RNJ_KEY_LGUI KEY_UNKNOWN
	#define RNJ_KEY_LWINDOWS KEY_UNKNOWN
	#define RNJ_KEY_RCTRL 218
	#define RNJ_KEY_RSHIFT 216
	#define RNJ_KEY_RALT 220
	#define RNJ_KEY_RGUI KEY_UNKNOWN
	#define RNJ_KEY_RWINDOWS KEY_UNKNOWN
#endif

#if defined(LINPUT_SDL12)
	#define RNJ_KEY_UNKNOWN SDLK_UNKNOWN
	#define RNJ_KEY_A SDLK_a
	#define RNJ_KEY_B SDLK_b
	#define RNJ_KEY_C SDLK_c
	#define RNJ_KEY_D SDLK_d
	#define RNJ_KEY_E SDLK_e
	#define RNJ_KEY_F SDLK_f
	#define RNJ_KEY_G SDLK_g
	#define RNJ_KEY_H SDLK_h
	#define RNJ_KEY_I SDLK_i
	#define RNJ_KEY_J SDLK_j
	#define RNJ_KEY_K SDLK_k
	#define RNJ_KEY_L SDLK_l
	#define RNJ_KEY_M SDLK_m
	#define RNJ_KEY_N SDLK_n
	#define RNJ_KEY_O SDLK_o
	#define RNJ_KEY_P SDLK_p
	#define RNJ_KEY_Q SDLK_q
	#define RNJ_KEY_R SDLK_r
	#define RNJ_KEY_S SDLK_s
	#define RNJ_KEY_T SDLK_t
	#define RNJ_KEY_U SDLK_u
	#define RNJ_KEY_V SDLK_v
	#define RNJ_KEY_W SDLK_w
	#define RNJ_KEY_X SDLK_x
	#define RNJ_KEY_Y SDLK_y
	#define RNJ_KEY_Z SDLK_z

	#define RNJ_KEY_1 SDLK_1
	#define RNJ_KEY_2 SDLK_2
	#define RNJ_KEY_3 SDLK_3
	#define RNJ_KEY_4 SDLK_4
	#define RNJ_KEY_5 SDLK_5
	#define RNJ_KEY_6 SDLK_6
	#define RNJ_KEY_7 SDLK_7
	#define RNJ_KEY_8 SDLK_8
	#define RNJ_KEY_9 SDLK_9
	#define RNJ_KEY_0 SDLK_0

	#define RNJ_KEY_RETURN SDLK_RETURN
	#define RNJ_KEY_ESCAPE SDLK_ESCAPE
	#define RNJ_KEY_ESC SDLK_ESCAPE
	#define RNJ_KEY_BACKSPACE SDLK_BACKSPACE
	#define RNJ_KEY_TAB SDLK_TAB
	#define RNJ_KEY_SPACE SDLK_SPACE

	#define RNJ_KEY_MINUS SDLK_MINUS
	#define RNJ_KEY_EQUALS SDLK_PLUS
	#define RNJ_KEY_LEFTBRACKET SDLK_LEFTBRACKET
	#define RNJ_KEY_RIGHTBRACKET SDLK_RIGHTBRACKET
	#define RNJ_KEY_BACKSLASH SDLK_BACKSLASH
	#define RNJ_KEY_NONUSHASH SDLK_BACKSLASH
	#define RNJ_KEY_SEMICOLON SDLK_SEMICOLON
	#define RNJ_KEY_APOSTROPHE SDLK_QUOTE
	#define RNJ_KEY_GRAVE SDLK_BACKQUOTE
	#define RNJ_KEY_TILDE SDLK_BACKQUOTE
	#define RNJ_KEY_COMMA SDLK_COMMA
	#define RNJ_KEY_PERIOD SDLK_PERIOD
	#define RNJ_KEY_SLASH SDLK_SLASH

	#define RNJ_KEY_CAPSLOCK SDLK_CAPSLOCK

	#define RNJ_KEY_F1 SDLK_F1
	#define RNJ_KEY_F2 SDLK_F2
	#define RNJ_KEY_F3 SDLK_F3
	#define RNJ_KEY_F4 SDLK_F4
	#define RNJ_KEY_F5 SDLK_F5
	#define RNJ_KEY_F6 SDLK_F6
	#define RNJ_KEY_F7 SDLK_F7
	#define RNJ_KEY_F8 SDLK_F8
	#define RNJ_KEY_F9 SDLK_F9
	#define RNJ_KEY_F10 SDLK_F10
	#define RNJ_KEY_F11 SDLK_F11
	#define RNJ_KEY_F12 SDLK_F12

	#define RNJ_KEY_PRINTSCREEN SDLK_SYSREQ
	#define RNJ_KEY_SCROLLLOCK SDLK_SCROLLOCK
	#define RNJ_KEY_PAUSE SDLK_BREAK
	#define RNJ_KEY_INSERT SDLK_INSERT
	#define RNJ_KEY_HOME SDLK_HOME
	#define RNJ_KEY_PAGEUP SDLK_PAGEUP
	#define RNJ_KEY_DELETE SDLK_DELETE
	#define RNJ_KEY_END SDLK_END
	#define RNJ_KEY_PAGEDOWN SDLK_PAGEDOWN

	#define RNJ_KEY_RIGHT SDLK_RIGHT
	#define RNJ_KEY_LEFT SDLK_LEFT
	#define RNJ_KEY_DOWN SDLK_DOWN
	#define RNJ_KEY_UP SDLK_UP

	#define RNJ_KEY_NUMLOCK SDLK_NUMLOCK
	#define RNJ_KEY_KP_DIVIDE SDLK_KP_DIVIDE
	#define RNJ_KEY_KP_MULTIPLY SDLK_KP_MULTIPLY
	#define RNJ_KEY_KP_MINUS SDLK_KP_MINUS
	#define RNJ_KEY_KP_PLUS SDLK_KP_PLUS
	#define RNJ_KEY_KP_ENTER SDLK_KP_ENTER
	#define RNJ_KEY_KP_1 SDLK_KP1
	#define RNJ_KEY_KP_2 SDLK_KP2
	#define RNJ_KEY_KP_3 SDLK_KP3
	#define RNJ_KEY_KP_4 SDLK_KP4
	#define RNJ_KEY_KP_5 SDLK_KP5
	#define RNJ_KEY_KP_6 SDLK_KP6
	#define RNJ_KEY_KP_7 SDLK_KP7
	#define RNJ_KEY_KP_8 SDLK_KP8
	#define RNJ_KEY_KP_9 SDLK_KP9
	#define RNJ_KEY_KP_0 SDLK_KP0
	#define RNJ_KEY_KP_PERIOD SDLK_KP_PERIOD

	#define RNJ_KEY_APPLICATION SDLK_COMPOSE
	#define RNJ_KEY_CONTEXT SDLK_COMPOSE
	#define RNJ_KEY_LCTRL SDLK_LCTRL
	#define RNJ_KEY_LSHIFT SDLK_LSHIFT
	#define RNJ_KEY_LALT SDLK_LALT
	#define RNJ_KEY_LGUI SDLK_LSUPER
	#define RNJ_KEY_LWINDOWS SDLK_LSUPER
	#define RNJ_KEY_RCTRL SDLK_RCTRL
	#define RNJ_KEY_RSHIFT SDLK_RSHIFT
	#define RNJ_KEY_RALT SDLK_RALT
	#define RNJ_KEY_RGUI SDLK_RSUPER
	#define RNJ_KEY_RWINDOWS SDLK_RSUPER
#endif

#ifdef LINPUT_DUMMY
	#define RNJ_KEY_UNKNOWN 0x0000
	#define RNJ_KEY_A 0x0041
	#define RNJ_KEY_B 0x0042
	#define RNJ_KEY_C 0x0043
	#define RNJ_KEY_D 0x0044
	#define RNJ_KEY_E 0x0045
	#define RNJ_KEY_F 0x0046
	#define RNJ_KEY_G 0x0047
	#define RNJ_KEY_H 0x0048
	#define RNJ_KEY_I 0x0049
	#define RNJ_KEY_J 0x004A
	#define RNJ_KEY_K 0x004B
	#define RNJ_KEY_L 0x004C
	#define RNJ_KEY_M 0x004D
	#define RNJ_KEY_N 0x004E
	#define RNJ_KEY_O 0x005F
	#define RNJ_KEY_P 0x0050
	#define RNJ_KEY_Q 0x0051
	#define RNJ_KEY_R 0x0052
	#define RNJ_KEY_S 0x0053
	#define RNJ_KEY_T 0x0054
	#define RNJ_KEY_U 0x0055
	#define RNJ_KEY_V 0x0056
	#define RNJ_KEY_W 0x0057
	#define RNJ_KEY_X 0x0058
	#define RNJ_KEY_Y 0x0059
	#define RNJ_KEY_Z 0x005A

	#define RNJ_KEY_1 0x0031
	#define RNJ_KEY_2 0x0032
	#define RNJ_KEY_3 0x0033
	#define RNJ_KEY_4 0x0034
	#define RNJ_KEY_5 0x0035
	#define RNJ_KEY_6 0x0036
	#define RNJ_KEY_7 0x0037
	#define RNJ_KEY_8 0x0038
	#define RNJ_KEY_9 0x0039
	#define RNJ_KEY_0 0x0030

	#define RNJ_KEY_RETURN 0x000D
	#define RNJ_KEY_ESCAPE 0x001B
	#define RNJ_KEY_ESC 0x001B
	#define RNJ_KEY_BACKSPACE 0x0008
	#define RNJ_KEY_TAB 0x0009
	#define RNJ_KEY_SPACE 0x0020

	#define RNJ_KEY_MINUS 61
	#define RNJ_KEY_EQUALS 62
	#define RNJ_KEY_LEFTBRACKET 66
	#define RNJ_KEY_RIGHTBRACKET 67
	#define RNJ_KEY_BACKSLASH 70
	#define RNJ_KEY_NONUSHASH RNJ_KEY_UNKNOWN
	#define RNJ_KEY_SEMICOLON 68
	#define RNJ_KEY_APOSTROPHE 69
	#define RNJ_KEY_GRAVE 60
	#define RNJ_KEY_TILDE 60
	#define RNJ_KEY_COMMA 72
	#define RNJ_KEY_PERIOD 73
	#define RNJ_KEY_SLASH 74

	#define RNJ_KEY_CAPSLOCK 226

	#define RNJ_KEY_F1 47
	#define RNJ_KEY_F2 48
	#define RNJ_KEY_F3 49
	#define RNJ_KEY_F4 50
	#define RNJ_KEY_F5 51
	#define RNJ_KEY_F6 52
	#define RNJ_KEY_F7 53
	#define RNJ_KEY_F8 54
	#define RNJ_KEY_F9 55
	#define RNJ_KEY_F10 56
	#define RNJ_KEY_F11 57
	#define RNJ_KEY_F12 58

	#define RNJ_KEY_PRINTSCREEN 92
	#define RNJ_KEY_SCROLLLOCK 224
	#define RNJ_KEY_PAUSE 93
	#define RNJ_KEY_INSERT 76
	#define RNJ_KEY_HOME 78
	#define RNJ_KEY_PAGEUP 80
	#define RNJ_KEY_DELETE 77
	#define RNJ_KEY_END 79
	#define RNJ_KEY_PAGEDOWN 81

	#define RNJ_KEY_RIGHT 83
	#define RNJ_KEY_LEFT 82
	#define RNJ_KEY_DOWN 85
	#define RNJ_KEY_UP 84

	#define RNJ_KEY_NUMLOCK 225
	#define RNJ_KEY_KP_DIVIDE 86
	#define RNJ_KEY_KP_MULTIPLY 87
	#define RNJ_KEY_KP_MINUS 88
	#define RNJ_KEY_KP_PLUS 89
	#define RNJ_KEY_KP_ENTER 91
	#define RNJ_KEY_KP_1 37
	#define RNJ_KEY_KP_2 38
	#define RNJ_KEY_KP_3 39
	#define RNJ_KEY_KP_4 40
	#define RNJ_KEY_KP_5 41
	#define RNJ_KEY_KP_6 42
	#define RNJ_KEY_KP_7 43
	#define RNJ_KEY_KP_8 44
	#define RNJ_KEY_KP_9 45
	#define RNJ_KEY_KP_0 46
	#define RNJ_KEY_KP_PERIOD 90

	#define RNJ_KEY_APPLICATION RNJ_KEY_UNKNOWN
	#define RNJ_KEY_CONTEXT RNJ_KEY_UNKNOWN
	#define RNJ_KEY_LCTRL 217
	#define RNJ_KEY_LSHIFT 215
	#define RNJ_KEY_LALT 219
	#define RNJ_KEY_LGUI RNJ_KEY_UNKNOWN
	#define RNJ_KEY_LWINDOWS RNJ_KEY_UNKNOWN
	#define RNJ_KEY_RCTRL 218
	#define RNJ_KEY_RSHIFT 216
	#define RNJ_KEY_RALT 220
	#define RNJ_KEY_RGUI RNJ_KEY_UNKNOWN
	#define RNJ_KEY_RWINDOWS RNJ_KEY_UNKNOWN
#endif

#endif
