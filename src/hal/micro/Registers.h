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

#if defined(__AVR_ATmega328P__)
		
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

		const std::uint16_t TCCR1A	= 0x80;	// Timer/Counter 1 Control Register A.
		const std::uint16_t TCCR1B	= 0x81;	// Timer/Counter 1 Control Register B.
		const std::uint16_t TCCR1C	= 0x82;	// Timer/Counter 1 Control Register C.
		const std::uint16_t TCNT1	= 0x84;	// Timer/Counter 1 Register
		const std::uint16_t ICR1	= 0x86;	// Input capture Register 1
		const std::uint16_t OCR1A	= 0x88;	// Output Compare Register 1 A
		const std::uint16_t OCR1B	= 0x8A;	// Output Compare Register 1 B
		const std::uint16_t TIMSK1	= 0x6F;	//	Timer/Counter 1 Interrupt Mask Register
		const std::uint16_t TIFR1	= 0x36;	//	Timer/Counter 1 Interrupt flag register

		const std::uint16_t TCCR2A	= 0xB0;	// Timer/Counter 2 Control Register A.
		const std::uint16_t TCCR2B	= 0xB1;	// Timer/Counter 2 Control Register B.
		const std::uint16_t TCNT2	= 0xB2;	// Timer/Counter 2 Register
		const std::uint16_t OCR2A	= 0xB3;	// Output Compare Register 2 A
		const std::uint16_t OCR2B	= 0xB4;	// Output Compare Register 2 B
		const std::uint16_t TIMSK2	= 0x70;	//	Timer/Counter 2 Interrupt Mask Register
		const std::uint16_t TIFR2	= 0x37;	//	Timer/Counter 2 Interrupt flag register
		const std::uint16_t ASSR	= 0xB6;	//	Asynchronous Status Register

		

		const std::uint16_t MCUCR = 0x55;

#endif

	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_MICRO_REGISTERS_H_