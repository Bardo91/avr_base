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
		
		// Existing ports
		#define PORTB PORTB
		#define PORTC PORTC
		#define PORTD PORTD

		const std::uint16_t PINB	= 0x23;
		const std::uint16_t DDRB	= 0x24;
		const std::uint16_t PORTB	= 0x25;
				   
		const std::uint16_t PINC	= 0x26;
		const std::uint16_t DDRC	= 0x27;
		const std::uint16_t PORTC	= 0x28;
				   
		const std::uint16_t PIND	= 0x29;
		const std::uint16_t DDRD	= 0x2A;
		const std::uint16_t PORTD	= 0x2B;
		
		const std::uint16_t TCCR0A	= 0x44;	// Timer/Counter 0 Control Register A.
		const std::uint16_t TCCR0B	= 0x45;	// Timer/Counter 0 Control Register B.
		const std::uint16_t TCNT0	= 0x46;	// Timer/Counter 0 Register --> Give acces for read and write operation to the Timer/Counter
		const std::uint16_t OCR0A	= 0x47;	// Ouput Compare Register A --> Value that is compared with the counter TCNT0. Match can be use to generate an OutputCompare interrupt o waveform gen on OC0A.
		const std::uint16_t OCR0B	= 0x48;	// Ouput Compare Register B --> Idem than A but with B.
		const std::uint16_t TIMSK0	= 0x6E;	// Timer/Counter interrrupt Mask Register
		const std::uint16_t TIFR0	= 0x35;	// Timer/Counter 0 Interrupt Flag Register.


		const std::uint16_t MCUCR = 0x55;

#endif

	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_MICRO_REGISTERS_H_