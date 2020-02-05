ZX Spectrum PS/2 keyboard controller
====================================

About
-----
This project is an PS/2 keyboard controller for the ZX Spectrum. It makes it
possible to connect and use an external PS/2 keyboard with the spectrum. It's
based on the a500kbd code: https://github.com/jtsiomb/a500kbd

The PS/2 keyboard controller is built around an AVR atmega168 microcontroller.
The firmware reads PS/2 keyboard scancodes, maintains a virtual spectrum
keyboard state, and monitors the address bus to keep the data lines going into
the ULA continuously up to date with the selected key row state.

NOTE: not done. check back soon.

License
-------
Copyright (C) 2020 John Tsiombikas <nuclear@member.fsf.org>

You are free to use, reproduce, modify, redistribute any parts of this project,
provided you make any derivative work you release, freely available under the
same terms.

More specifically the hardware design is released under the Creative Commons
Attribution Share-Alike license (see `LICENSE.hw` for details), and the
software/firmware is released under the GNU General Public License v3, or later
(see `LICENSE.fw` for details).
