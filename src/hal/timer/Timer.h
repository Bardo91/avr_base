///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/21
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 


#ifndef _AVR_BASE_HAL_TIMER_TIMER_H_
#define	_AVR_BASE_HAL_TIMER_TIMER_H_

#include "../micro/Registers.h"
#include <cstdint>

namespace avr_base{
	namespace hal{
		// Timer traits
		// Register size traits
		template<std::uint8_t bitSize_>
		class TimerRegisterSize{};

		class TimerRegisterSize<8>{
			typedef std::uint8_t RegisterRef;
		};

		class TimerRegisterSize<16>{
			typedef std::uint16_t RegisterRef;
		};

		// Registrer trait
		template<	std::uint16_t TCCRnA_,
					std::uint16_t TCCRnB_,
					std::uint16_t TCCRnC_,
					std::uint16_t TCNT_, 
					std::uint16_t OCRnA_,
					std::uint16_t OCRnB_,
					std::uint16_t ICRn_,
					std::uint16_t TIFRn_,
					std::uint16_t TIMSKn_,
					class trait_>
		class TimerRegisterTrait{
			static const std::uint8_t* TCCRA	= reinterpret_cast<std::uint8_t*>(TCCRnA_);
			static const std::uint8_t* TCCRB	= reinterpret_cast<std::uint8_t*>(TCCRnB_);
			static const std::uint8_t* TCCRC	= reinterpret_cast<std::uint8_t*>(TCCRnC_);
			static const RegisterRef* TCNT		= reinterpret_cast<registerRef*>(TCNT_);		// This register have 2 bytes in timers 1 and 2
			static const RegisterRef* OCRA		= reinterpret_cast<registerRef*>(OCRnA_);
			static const RegisterRef* OCRB		= reinterpret_cast<registerRef*>(OCRnB_);
			static const RegisterRef* ICR		= reinterpret_cast<registerRef*>(ICRn_);
			static const std::uint8_t* TIFR		= reinterpret_cast<std::uint8_t*>(TIFRn_);
			static const std::uint8_t* TIMSK	= reinterpret_cast<std::uint8_t*>(TIMSKn_);
		};

		// Define timer traits
		typedef TimerRegisterTrait<TCCR0A, TCCR0B, 0x00, TCNT0, OCR0A, OCR0B, 0x00, TIFR0, TIMSK0, TimerRegisterSize<8>> Timer0Registers;		//	This timer havent got TCCTnC and ICR registers, are set to 0x00 but, Can it provoke errors? 666 TODO
		typedef TimerRegisterTrait<TCCR1A, TCCR1B, TCCR1C, TCNT1, OCR1A, OCR1B, ICR1, TIFR1, TIMSK1, TimerRegisterSize<16>> Timer1Registers;





	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_TIMER_TIMER_H_