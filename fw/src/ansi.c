#include <stdio.h>
#include "ansi.h"

void ansi_reset(void)
{
	fputs("\033c", stdout);
	fflush(stdout);
}

void ansi_clearscr(void)
{
	fputs("\033[2J", stdout);
}

void ansi_setcursor(int row, int col)
{
	printf("\033[%d;%dH", row + 1, col + 1);
}

void ansi_cursor(int show)
{
	printf("\033[?25%c", show ? 'h' : 'l');
	fflush(stdout);
}

void ansi_bright(void)
{
	printf("\033[1m\n");
}

void ansi_reverse(void)
{
	printf("\033[7m\n");
}

void ansi_normal(void)
{
	printf("\033[0m\n");
}
