#include "defs.h"

enum {
	RCAPS = 0, RZ = 0, RX = 0, RC = 0, RV = 0,
	RA = 1, RS = 1, RD = 1, RF = 1, RG = 1,
	RQ = 2, RW = 2, RE = 2, RR = 2, RT = 2,
	R1 = 3, R2 = 3, R3 = 3, R4 = 3, R5 = 3,
	R0 = 4, R9 = 4, R8 = 4, R7 = 4, R6 = 4,
	RP = 5, RO = 5, RI = 5, RU = 5, RY = 5,
	RENTER = 6, RL = 6, RK = 6, RJ = 6, RH = 6,
	RSPACE = 7, RSYMB = 7, RM = 7, RN = 7, RB = 7
};

enum {
	CCAPS = 0, CZ = 1, CX = 2, CC = 3, CV = 4,
	CA = 0, CS = 1, CD = 2, CF = 3, CG = 4,
	CQ = 0, CW = 1, CE = 2, CR = 3, CT = 4,
	C1 = 0, C2 = 1, C3 = 2, C4 = 3, C5 = 4,
	C0 = 0, C9 = 1, C8 = 2, C7 = 3, C6 = 4,
	CP = 0, CO = 1, CI = 2, CU = 3, CY = 4,
	CENTER = 0, CL = 1, CK = 2, CJ = 3, CH = 4,
	CSPACE = 0, CSYMB = 1, CM = 2, CN = 3, CB = 4
};

#define KEY(x)		(0xf0 | (x))
#define PAIR(x, y)	((x) << 4 | (y))


/* row of modifier (high order nibble) and key (low order nibble) for each keycode */
static const unsigned char keyrow[] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 00 - 07 */
	0xff, 0xff, KEY(RENTER), 0xff, 0xff, KEY(RENTER), 0xff, 0xff,		/* 08 - 0f */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 10 - 17 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 18 - 1f */
	KEY(RSPACE), PAIR(RSYMB, R1), PAIR(RSYMB, RP), PAIR(RSYMB, R3),		/* 20 - 23 */
	PAIR(RSYMB, R4), PAIR(RSYMB, R5), PAIR(RSYMB, R6), PAIR(RSYMB, R7),	/* 23 - 27 */
	PAIR(RSYMB, R8), PAIR(RSYMB, R9), PAIR(RSYMB, RB), PAIR(RSYMB, RK), /* 28 - 2b */
	PAIR(RSYMB, RN), PAIR(RSYMB, RJ), PAIR(RSYMB, RM), PAIR(RSYMB, RV), /* 2c - 2f */
	KEY(R0), KEY(R1), KEY(R2), KEY(R3), KEY(R4), KEY(R5), KEY(R6), KEY(R7),	/* 30 - 37 */
	KEY(R8), KEY(R9), PAIR(RSYMB, RZ), PAIR(RSYMB, RO),					/* 38 - 3b */
	PAIR(RSYMB, RR), PAIR(RSYMB, RL), PAIR(RSYMB, RT), PAIR(RSYMB, RC),	/* 3c - 3f */
	PAIR(RSYMB, R2), KEY(RA), KEY(RB), KEY(RC), KEY(RD), KEY(RE), KEY(RF), KEY(RG),	/* 40 - 47 */
	KEY(RH), KEY(RI), KEY(RJ), KEY(RK), KEY(RL), KEY(RM), KEY(RN), KEY(RO),	/* 48 - 4f */
	KEY(RP), KEY(RQ), KEY(RR), KEY(RS), KEY(RT), KEY(RU), KEY(RV), KEY(RW),	/* 50 - 57 */
	KEY(RX), KEY(RY), KEY(RZ), 0xff, 0xff, 0xff, PAIR(RSYMB, RH), PAIR(RSYMB, R0),	/* 58 - 5f */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 60 - 67 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 68 - 6f */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 70 - 77 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, PAIR(RCAPS, R0),			/* 78 - 7f */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 80 - 87 */
	0xff, 0xff, 0xff, 0xff, 0xff, PAIR(RCAPS, RSPACE), 0xff, PAIR(RCAPS, R2),	/* 88 - 8f */
	0xff, KEY(RCAPS), KEY(RCAPS), 0xff, 0xff, KEY(RSYMB), KEY(RSYMB),	/* 90 - 97 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 98 - 9f */
	PAIR(RCAPS, R5), PAIR(RCAPS, R8), PAIR(RCAPS, R7), PAIR(RCAPS, R6), 0xff, 0xff, 0xff, 0xff,	/* a0 - a7 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, PAIR(RSYMB, RV), PAIR(RSYMB, RB),	/* a8 - af */
	PAIR(RSYMB, RJ), PAIR(RSYMB, RK), PAIR(RSYMB, RM), KEY(RENTER)	/* b0 - b3 */
};

/* column of modifier (high order nibble) and key (low order nibble) for each keycode */
static const unsigned char keycol[] = {
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 00 - 07 */
	0xff, 0xff, KEY(CENTER), 0xff, 0xff, KEY(CENTER), 0xff, 0xff,		/* 08 - 0f */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 10 - 17 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 18 - 1f */
	KEY(CSPACE), PAIR(CSYMB, C1), PAIR(CSYMB, CP), PAIR(CSYMB, C3),		/* 20 - 23 */
	PAIR(CSYMB, C4), PAIR(CSYMB, C5), PAIR(CSYMB, C6), PAIR(CSYMB, C7),	/* 23 - 27 */
	PAIR(CSYMB, C8), PAIR(CSYMB, C9), PAIR(CSYMB, CB), PAIR(CSYMB, CK), /* 28 - 2b */
	PAIR(CSYMB, CN), PAIR(CSYMB, CJ), PAIR(CSYMB, CM), PAIR(CSYMB, CV), /* 2c - 2f */
	KEY(C0), KEY(C1), KEY(C2), KEY(C3), KEY(C4), KEY(C5), KEY(C6), KEY(C7),	/* 30 - 37 */
	KEY(C8), KEY(C9), PAIR(CSYMB, CZ), PAIR(CSYMB, CO),					/* 38 - 3b */
	PAIR(CSYMB, CR), PAIR(CSYMB, CL), PAIR(CSYMB, CT), PAIR(CSYMB, CC),	/* 3c - 3f */
	PAIR(CSYMB, C2), KEY(CA), KEY(CB), KEY(CC), KEY(CD), KEY(CE), KEY(CF), KEY(CG),	/* 40 - 47 */
	KEY(CH), KEY(CI), KEY(CJ), KEY(CK), KEY(CL), KEY(CM), KEY(CN), KEY(CO),	/* 48 - 4f */
	KEY(CP), KEY(CQ), KEY(CR), KEY(CS), KEY(CT), KEY(CU), KEY(CV), KEY(CW),	/* 50 - 57 */
	KEY(CX), KEY(CY), KEY(CZ), 0xff, 0xff, 0xff, PAIR(CSYMB, CH), PAIR(CSYMB, C0),	/* 58 - 5f */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 60 - 67 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 68 - 6f */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 70 - 77 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, PAIR(CCAPS, C0),			/* 78 - 7f */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 80 - 87 */
	0xff, 0xff, 0xff, 0xff, 0xff, PAIR(CCAPS, CSPACE), 0xff, PAIR(CCAPS, C2),	/* 88 - 8f */
	0xff, KEY(CCAPS), KEY(CCAPS), 0xff, 0xff, KEY(CSYMB), KEY(CSYMB),	/* 90 - 97 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff,						/* 98 - 9f */
	PAIR(CCAPS, C5), PAIR(CCAPS, C8), PAIR(CCAPS, C7), PAIR(CCAPS, C6), 0xff, 0xff, 0xff, 0xff,	/* a0 - a7 */
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, PAIR(CSYMB, CV), PAIR(CSYMB, CB),	/* a8 - af */
	PAIR(CSYMB, CJ), PAIR(CSYMB, CK), PAIR(CSYMB, CM), KEY(CENTER)	/* b0 - b3 */
};

static unsigned char keystate[8];

void zxkbd_key(int keycode, int press)
{
	unsigned char row, col, krow, kcol, mrow, mcol, mask;

	row = keyrow[keycode];
	if(row == 0xff) return;
	col = keycol[keycode];

	krow = row & 0xf;
	kcol = col & 0xf;
	mrow = row >> 4;

	mask = 1 << kcol;
	if(press) {
		keystate[krow] |= mask;
	} else {
		keystate[krow] &= ~mask;
	}

	if(mrow != 0xf) {
		mcol = col >> 4;
		mask = 1 << mcol;

		if(press) {
			keystate[mrow] |= mask;
		} else {
			keystate[mrow] &= ~mask;
		}
	}
}

void update_zxkbd(void)
{
	unsigned char data, pb, pc;

	/* address bits 4-7 in port C 0-3
	 *         bits 0-1 in port C 4-5
	 *         bits 2-3 in port B 0-1
	 */
	pc = PINC;
	pb = PINB;

	data = 0;
	if(pc & 0x10) data |= keystate[0];
	if(pc & 0x20) data |= keystate[1];
	if(pb & 0x01) data |= keystate[2];
	if(pb & 0x02) data |= keystate[3];
	if(pc & 0x01) data |= keystate[4];
	if(pc & 0x02) data |= keystate[5];
	if(pc & 0x04) data |= keystate[6];
	if(pc & 0x08) data |= keystate[7];

	/* write to the data bus */
	PORTD = ~data << 3;
}
