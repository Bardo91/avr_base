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

		template<typename regType_, std::uint16_t reg_>
		class Register{

		};

		template<std::uint16_t reg_>
		class Register<std::uint8_t, reg_>{
			void operator=(std::uint8_t _val){ *static_cast<*std::uint_8t>(reg_) = _val; };
			operator std::uint8_t() const{ *static_cast<*std::uint8_t>(reg_); };
		};

		template<std::uint16_t reg_>
		class Register<std::uint16_t, reg_>{
			void operator=(std::uint16_t _val){ *static_cast<*std::uint_16t>(reg_) = _val; };
			operator std::uint16_t() const{ *static_cast<*std::uint16_t>(reg_); };

			static constexpr std::uint8_t low = static_cast<*std::uint16_t>(reg_);
			static constexpr std::uint8_t high = static_cast<*std::uint16_t + 1>(reg_);
		};

#if defined(__ATMEGA328P__)
		
		// Existing ports
		#define PORTB PORTB
		#define PORTC PORTC
		#define PORTD PORTD

		Register<std::uint8_t, 0x23> PINB;
		Register<std::uint8_t, 0x24> DDRB;
		Register<std::uint8_t, 0x25> PORTB;
				   
		Register<std::uint8_t, 0x26> PINC;
		Register<std::uint8_t, 0x27> DDRC;
		Register<std::uint8_t, 0x28> PORTC;
				   
		Register<std::uint8_t, 0x29> PIND;
		Register<std::uint8_t, 0x2A> DDRD;
		Register<std::uint8_t, 0x2B> PORTD;
		
		Register<std::uint8_t, 0x44> TCCR0A;	// Timer/Counter 0 Control Register A.
		Register<std::uint8_t, 0x45> TCCR0B;	// Timer/Counter 0 Control Register B.
		Register<std::uint8_t, 0x46> TCNT0;	// Timer/Counter 0 Register --> Give acces for read and write operation to the Timer/Counter
		Register<std::uint8_t, 0x47> OCR0A;	// Ouput Compare Register A --> Value that is compared with the counter TCNT0. Match can be use to generate an OutputCompare interrupt o waveform gen on OC0A.
		Register<std::uint8_t, 0x48> OCR0B;	// Ouput Compare Register B --> Idem than A but with B.
		Register<std::uint8_t, 0x6E> TIMSK0;	// Timer/Counter interrrupt Mask Register
		Register<std::uint8_t, 0x35> TIFR0;	// Timer/Counter 0 Interrupt Flag Register.

		Register<std::uint8_t, 0x80> TCCR1A;	// Timer/Counter 1 Control Register A.
		Register<std::uint8_t, 0x81> TCCR1B;	// Timer/Counter 1 Control Register B.
		Register<std::uint8_t, 0x82> TCCR1C;	// Timer/Counter 1 Control Register C.
		Register<std::uint16_t, 0x84> TCNT1;	// Timer/Counter 1 Register
		Register<std::uint16_t, 0x86> ICR1;	// Input capture Register 1
		Register<std::uint16_t, 0x88> OCR1A;	// Output Compare Register 1 A
		Register<std::uint16_t, 0x8A> OCR1B;	// Output Compare Register 1 B
		Register<std::uint8_t, 0x6F> TIMSK1;	//	Timer/Counter 1 Interrupt Mask Register
		Register<std::uint8_t, 0x36> TIFR1;	//	Timer/Counter 1 Interrupt flag register

		Register<std::uint8_t, 0xB0> TCCR2A;	// Timer/Counter 2 Control Register A.
		Register<std::uint8_t, 0xB1> TCCR2B;	// Timer/Counter 2 Control Register B.
		Register<std::uint8_t, 0xB2> TCNT2;	// Timer/Counter 2 Register
		Register<std::uint8_t, 0xB3> OCR2A;	// Output Compare Register 2 A
		Register<std::uint8_t, 0xB4> OCR2B;	// Output Compare Register 2 B
		Register<std::uint8_t, 0x70> TIMSK2;	//	Timer/Counter 2 Interrupt Mask Register
		Register<std::uint8_t, 0x37> TIFR2;	//	Timer/Counter 2 Interrupt flag register
		Register<std::uint8_t, 0xB6> ASSR;	//	Asynchronous Status Register

		

		const std::uint16_t MCUCR = 0x55;

#endif

	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_MICRO_REGISTERS_H_