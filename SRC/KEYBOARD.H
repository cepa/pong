#ifndef __KEYBOARD_H__
  #define __KEYBOARD_H__

  #define KEY_ESC 		1
  #define KEY_F1		59
  #define KEY_F2      		60
  #define KEY_F3                61
  #define KEY_F4                62
  #define KEY_F5                63
  #define KEY_F6                64
  #define KEY_F7                65
  #define KEY_F8                66
  #define KEY_F9                67
  #define KEY_F10               68
  #define KEY_F11               87
  #define KEY_F12               88
  #define KEY_SCROLL_LOCK	70
  #define KEY_SPECIAL1		41 // '~'
  #define KEY_1			2
  #define KEY_2			3
  #define KEY_3			4
  #define KEY_4			5
  #define KEY_5			6
  #define KEY_6			7
  #define KEY_7			8
  #define KEY_8			9
  #define KEY_9			10
  #define KEY_10		11
  #define KEY_SPECIAL2		12 // '-'
  #define KEY_SPECIAL3		13 // '='
  #define KEY_SPECIAL4		43 // '|'
  #define KEY_BACKSPACE		14
  #define KEY_TAB		15
  #define KEY_Q			16
  #define KEY_W			17
  #define KEY_E			18
  #define KEY_R			19
  #define KEY_T			20
  #define KEY_Y			21
  #define KEY_U			22
  #define KEY_I			23
  #define KEY_O			24
  #define KEY_P			25
  #define KEY_SPECIAL5		26 // '['
  #define KEY_SPECIAL6		27 // ']'
  #define KEY_ENTER		28
  #define KEY_CAPS_LOCK		58
  #define KEY_A			30
  #define KEY_S			31
  #define KEY_D			32
  #define KEY_F			33
  #define KEY_G			34
  #define KEY_H			35
  #define KEY_J			36
  #define KEY_K			37
  #define KEY_L			38
  #define KEY_SPECIAL7		39 // ';'
  #define KEY_SPECIAL8		40 // '"'
  #define KEY_LSHIFT		42
  #define KEY_Z			44
  #define KEY_X			45
  #define KEY_C			46
  #define KEY_V			47
  #define KEY_B			48
  #define KEY_N			49
  #define KEY_M			50
  #define KEY_SPECIAL9		51 // '<'
  #define KEY_SPECIAL10		52 // '>'
  #define KEY_SPECIAL11		53 // '?'
  #define KEY_RSHIFT		54
  #define KEY_CTRL		29
  #define KEY_ALT		56
  #define KEY_SPACE		57
  #define KEY_INSERT		82
  #define KEY_HOME		71
  #define KEY_PAGE_UP		73
  #define KEY_DELETE		83
  #define KEY_END		79
  #define KEY_PAGE_DOWN		81
  #define KEY_UP		72
  #define KEY_DOWN		80
  #define KEY_RIGHT		77
  #define KEY_LEFT		75
  #define KEY_NUM_LOCK		69
  #define KEY_SPECIAL12		53 // NUM '/'
  #define KEY_SPECIAL13		55 // NUM '*'
  #define KEY_SPECIAL14		74 // NUM '-'
  #define KEY_SPECIAL15		78 // NUM '+'
  #define KEY_NUM0		82
  #define KEY_NUM1		79
  #define KEY_NUM2		80
  #define KEY_NUM3		81
  #define KEY_NUM4		75
  #define KEY_NUM5		76
  #define KEY_NUM6		77
  #define KEY_NUM7		71
  #define KEY_NUM8		72
  #define KEY_NUM9		73

extern unsigned char key[];
extern unsigned char lastkey;

void install_keyboard();
void remove_keyboard();
void wait_for_any_key();

#endif