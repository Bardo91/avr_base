///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/20
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _AVR_BASE_HAL_GPIO_BOARD_H_
#define _AVR_BASE_HAL_GPIO_BOARD_H_

#include "../micro/Registers.h"
#include "GPIOPort.h"
#include "GPIOPin.h"

namespace avr_base{
	namespace hal{

#if defined(__ATMEGA328P__)
		typedef GPIOPin<PortB, 0> pin14;
		typedef GPIOPin<PortB, 1> pin15;
		typedef GPIOPin<PortB, 2> pin16;
		typedef GPIOPin<PortB, 3> pin17;
		typedef GPIOPin<PortB, 4> pin18;
		typedef GPIOPin<PortB, 5> pin19;
		typedef GPIOPin<PortB, 6> pin9;
		typedef GPIOPin<PortB, 7> pin10;

		typedef GPIOPin<PortC, 0> pin23;
		typedef GPIOPin<PortC, 1> pin24;
		typedef GPIOPin<PortC, 2> pin25;
		typedef GPIOPin<PortC, 3> pin26; 
		typedef GPIOPin<PortC, 4> pin27;
		typedef GPIOPin<PortC, 5> pin28;
		typedef GPIOPin<PortC, 6> pin1;

		typedef GPIOPin<PortD, 0> pin2;
		typedef GPIOPin<PortD, 1> pin3;
		typedef GPIOPin<PortD, 2> pin4;
		typedef GPIOPin<PortD, 3> pin5;
		typedef GPIOPin<PortD, 4> pin6;
		typedef GPIOPin<PortD, 5> pin11;
		typedef GPIOPin<PortD, 6> pin12;
		typedef GPIOPin<PortD, 7> pin13;
#endif

	}	//	namespace hal
}	//	namespace avr_base


#endif	//_AVR_BASE_HAL_GPIO_BOARD_H_