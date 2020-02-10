#ifndef DEFS_H_
#define DEFS_H_

#include <avr/io.h>

/* pin assignments:
 * D2	PS/2 clock (INT0)
 * B2	PS/2 data
 *
 * KA0,KA1: C4,C5
 * KA2,KA3: B0,B1
 * KA4-KA7: C0-C3
 * KD0-KD4: D3-D7
 */

#define PCLK	2
#define PDATA	2

#define PCLK_BIT	(1 << PCLK)
#define PDATA_BIT	(1 << PDATA)

#endif	/* DEFS_H_ */
