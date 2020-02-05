#ifndef SCANTBL_H_
#define SCANTBL_H_

enum {
	KEY_ESC = 27,
	KEY_DEL = 127,

	KEY_F1 = 128,
	KEY_F2, KEY_F3, KEY_F4, KEY_F5, KEY_F6, KEY_F7, KEY_F8,
	KEY_F9, KEY_F10, KEY_F11, KEY_F12, KEY_SYSRQ, KEY_BRK,
	KEY_SCRLK, KEY_CAPSLK, KEY_NUMLK,

	KEY_LSHIFT, KEY_RSHIFT,
	KEY_LCTRL, KEY_RCTRL,
	KEY_LALT, KEY_RALT,
	KEY_LWIN, KEY_RWIN, KEY_MENU,

	KEY_INS, KEY_HOME, KEY_END, KEY_PGUP, KEY_PGDOWN,
	KEY_LEFT, KEY_RIGHT, KEY_UP, KEY_DOWN,

	KEY_KP_0, KEY_KP_1, KEY_KP_2, KEY_KP_3, KEY_KP_4,
	KEY_KP_5, KEY_KP_6, KEY_KP_7, KEY_KP_8, KEY_KP_9,
	KEY_KP_DIV, KEY_KP_MUL, KEY_KP_MINUS, KEY_KP_PLUS,
	KEY_KP_DOT, KEY_KP_ENTER,

	MAX_NUM_KEYS
};

#define KEYMAP_NORMAL_SIZE	(sizeof keymap_normal / sizeof *keymap_normal)
static unsigned char keymap_normal[] = {
	0, KEY_F9, 0, KEY_F5, KEY_F3, KEY_F1, KEY_F2, KEY_F12,	/* 00 - 07 */
	0, KEY_F10, KEY_F8, KEY_F6,	KEY_F4, '\t', '`', 0,		/* 08 - 0f */
	0, KEY_LALT, KEY_LSHIFT, 0, KEY_LCTRL, 'Q', '1', 0,		/* 10 - 17 */
	0, 0, 'Z', 'S', 'A', 'W', '2', 0,						/* 18 - 1f */
	0, 'C', 'X', 'D', 'E', '4', '3', 0,						/* 20 - 27 */
	0, ' ', 'V', 'F', 'T', 'R', '5', 0,						/* 28 - 2f */
	0, 'N', 'B', 'H', 'G', 'Y', '6', 0,						/* 30 - 37 */
	0, 0, 'M', 'J', 'U', '7', '8', 0,						/* 38 - 3f */
	0, ',', 'K', 'I', 'O', '0', '9', 0,						/* 40 - 47 */
	0, '.', '/', 'L', ';', 'P', '-', 0,						/* 48 - 4f */
	0, 0, '\'', 0, '[', '=', 0, 0,							/* 50 - 57 */
	KEY_CAPSLK, KEY_RSHIFT, '\n', ']', 0, '\\', 0, 0,		/* 58 - 5f */
	0, 0, 0, 0, 0, 0, '\b', 0,								/* 60 - 67 */
	0, KEY_KP_1, 0, KEY_KP_4, KEY_KP_7, 0, 0, 0,				/* 68 - 6f */
	KEY_KP_0, KEY_KP_DOT, KEY_KP_2, KEY_KP_5, KEY_KP_6, KEY_KP_8, KEY_ESC, KEY_NUMLK, /* 70 - 77 */
	KEY_F11, KEY_KP_PLUS, KEY_KP_3, KEY_KP_MINUS, KEY_KP_MUL, KEY_KP_9, KEY_SCRLK, 0,/* 78 - 7f */
	0, 0, 0, KEY_F7											/* 80 - 83 */
};

#define KEYMAP_EXT_SIZE	(sizeof keymap_ext / sizeof *keymap_ext)
static unsigned char keymap_ext[] = {
	0, 0, 0, 0, 0, 0, 0, 0,									/* 00 - 07 */
	0, 0, 0, 0, 0, 0, 0, 0,									/* 08 - 0f */
	0, KEY_RALT, 0, 0, KEY_RCTRL, 0, 0, 0,	/* 10 - 17 */
	0, 0, 0, 0, 0, 0, 0, KEY_LWIN,				/* 18 - 1f */
	0, 0, 0, 0, 0, 0, 0, KEY_RWIN,	/* 20 - 27 */
	0, 0, 0, 0, 0, 0, 0, 0,		/* 28 - 2f */
	0, 0, 0, 0, 0, 0, 0, 0,	/* 30 - 37 */
	0, 0, 0, 0, 0, 0, 0, 0,	/* 38 - 3f */
	0, 0, 0, 0, 0, 0, 0, 0,						/* 40 - 47 */
	0, 0, KEY_KP_DIV, 0, 0, 0, 0, 0,	/* 48 - 4f */
	0, 0, 0, 0, 0, 0, 0, 0,						/* 50 - 57 */
	0, 0, KEY_KP_ENTER, 0, 0, 0, 0, 0,		/* 58 - 5f */
	0, 0, 0, 0, 0, 0, 0, 0,									/* 60 - 67 */
	0, KEY_END, 0, KEY_LEFT, KEY_HOME, 0, 0, 0,				/* 68 - 6f */
	KEY_INS, KEY_DEL, KEY_DOWN, 0, KEY_RIGHT, KEY_UP, 0, 0,	/* 70 - 77 */
	0, 0, KEY_PGDOWN, 0, 0, KEY_PGUP, 0, 0,					/* 78 - 7f */
};

#endif	/* SCANTBL_H_ */
