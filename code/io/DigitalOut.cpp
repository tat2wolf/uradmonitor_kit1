/*
    File:       DigitalOut.cpp
    Version:    0.1.0
    Date:       Feb. 21, 2013
	License:	GPL v2
    
	simple use of leds controlled directly by I/O pins
    
    ****************************************************************************
    Copyright (C) 2013 Radu Motisan  <radu.motisan@gmail.com>

	http://www.pocketmagic.net

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
    ****************************************************************************
 */



#include "DigitalOut.h"

void DigitalOut::init( volatile  uint8_t  *port, uint8_t  dq) {
	// save globals
	m_pport = port;
	m_dq = dq;
	// set for output
	*Port2DDR(m_pport) |= (1<<m_dq);
}

void DigitalOut::set(uint8_t st) {
	m_ledstate = st;
	if (st)
		*m_pport |= (1<<m_dq);
	else
		*m_pport &= ~(1<<m_dq);
}


void DigitalOut::toggle() {
	set(1 - m_ledstate);
}
