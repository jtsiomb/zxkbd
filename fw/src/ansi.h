#ifndef ANSI_H_
#define ANSI_H_

void ansi_reset(void);
void ansi_clearscr(void);
void ansi_setcursor(int row, int col);
void ansi_cursor(int show);
void ansi_bright(void);
void ansi_reverse(void);
void ansi_normal(void);

#endif	/* ANSI_H_ */
