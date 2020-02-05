#include <stdio.h>
#include <ctype.h>
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include "serial.h"
#include "scantbl.h"
#include "ps2kbd.h"
#include "defs.h"
#include "timer.h"
#include "zxkbd.h"

enum {
	KF_BRK = 1,
	KF_EXT = 2,
	KF_EXT1 = 4,
};
#define KF_TRANSIENT	0x0f
#define KF_STICKY		0xf0

#define RESET_WAIT 1000



int main(void)
{
	unsigned int keyflags = 0;
	unsigned char c;
	int keycode;

	/* disable all pullups globally */
	MCUCR |= 1 << PUD;

	DDRB = 0;
	PORTB = 0;
	DDRC = 0;
	PORTC = 0;
	DDRD = 0xf8;	/* bits 3-7 output (data bus) */
	PORTD = 0xf8;
	EIMSK = 0;	/* mask external interrupts */
	EICRA = 1 << ISC01;	/* falling edge of PCLK triggers interrupt */

	init_timer();

	/* initialize the UART and enable interrupts */
	init_serial(9600);
	sei();

	printf("PS/2 keyboard controller - John Tsiombikas <nuclear@member.fsf.org>\r\n");

	EIMSK = 1 << INT0;	/* enable ps/2 clock interrupt */

	_delay_ms(500);
	ps2setled(PS2LED_NUMLK);
	_delay_ms(200);
	ps2setled(PS2LED_CAPSLK);
	_delay_ms(200);
	ps2setled(PS2LED_SCRLK);
	_delay_ms(200);
	ps2setled(PS2LED_CAPSLK);
	_delay_ms(200);
	ps2setled(PS2LED_NUMLK);
	_delay_ms(200);
	ps2setled(0);	/* start with all LEDs off */

	for(;;) {
		if(ps2pending()) {
			c = ps2read();
			switch(c) {
			case 0xe0:	/* extended */
				keyflags |= KF_EXT;
				break;

			case 0xe1:	/* extended */
				keyflags |= KF_EXT1;
				break;

			case 0xf0:	/* break code */
				keyflags |= KF_BRK;
				break;

			default:
				keycode = -1;
				if(keyflags & KF_EXT) {
					if(c < KEYMAP_EXT_SIZE) {
						keycode = keymap_ext[(int)c];
					}
				} else if(keyflags & KF_EXT1) {
				} else {
					if(c < KEYMAP_NORMAL_SIZE) {
						keycode = keymap_normal[(int)c];
					}
				}

				if(keycode != -1) {
					int press = ~keyflags & KF_BRK;
					zxkbd_key(keycode, press);
				} else {
					printf("PS/2 unknown command or keycode: %x\r\n", (unsigned int)c);
				}
				keyflags &= ~KF_TRANSIENT;
			}
		}

		update_zxkbd();
	}
	return 0;
}
