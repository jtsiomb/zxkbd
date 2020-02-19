#ifndef DEFS_H_
#define DEFS_H_

#include <avr/io.h>

/* pin assignments:
 * D2	PS/2 clock (INT0)
 * B2	PS/2 data
 *
 * C0-C5 SEL0-SEL5
 * B0,B1 SEL6,SEL7
 * D3-D7 DATA0-DATA4
 */

#define PCLK	2
#define PDATA	2

#define PCLK_BIT	(1 << PCLK)
#define PDATA_BIT	(1 << PDATA)

#endif	/* DEFS_H_ */
