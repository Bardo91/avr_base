///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/20
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _AVR_BASE_HAL_MICRO_REGISTERS_H_
#define _AVR_BASE_HAL_MICRO_REGISTERS_H_

#include <cstdint>

namespace avr_base{
	namespace hal {

#if defined(__ATMEGA328P__)
		
		#define PORTB PORTB
		#define PORTC PORTC
		#define PORTD PORTD

		const std::uint16_t PINB = 0x23;
		const std::uint16_t DDRB = 0x24;
		const std::uint16_t PORTB = 0x25;
				   
		const std::uint16_t PINC = 0x26;
		const std::uint16_t DDRC = 0x27;
		const std::uint16_t PORTC = 0x28;
				   
		const std::uint16_t PIND = 0x29;
		const std::uint16_t DDRD = 0x2A;
		const std::uint16_t PORTD = 0x2B;
				   
		const std::uint16_t MCUCR = 0x55;

#endif

	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_MICRO_REGISTERS_H_