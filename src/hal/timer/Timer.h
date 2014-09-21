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

		//-------------------------------------------------------------------------------------------------------------
		class TimerRegisterSize<8>{
			typedef std::uint8_t ExtendedReg;
		};

		//-------------------------------------------------------------------------------------------------------------
		class TimerRegisterSize<16>{
			typedef std::uint16_t ExtendedReg;
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
			static const ExtendedReg* TCNT = reinterpret_cast<registerRef*>(TCNT_);		// This registers have 2 bytes in timer 1
			static const ExtendedReg* OCRA = reinterpret_cast<registerRef*>(OCRnA_);
			static const ExtendedReg* OCRB = reinterpret_cast<registerRef*>(OCRnB_);
			static const ExtendedReg* ICR = reinterpret_cast<registerRef*>(ICRn_);
			static const std::uint8_t* TIFR		= reinterpret_cast<std::uint8_t*>(TIFRn_);
			static const std::uint8_t* TIMSK	= reinterpret_cast<std::uint8_t*>(TIMSKn_);
		};

		// Prescaler types
		enum class ePrescalerType8 {	eNonClock = 0,
										e1 = 1,
										e8 = 2,
										e64 = 3,
										e256 = 4,
										e1024 = 5,
										eExt0Falling = 6,
										eExt0Rising = 7	};

		//-------------------------------------------------------------------------------------------------------------
		enum class ePrescalerType16 {	};

		// Timer modes
		enum class eTimerMode8 { };
		enum class eTimerMode16 { };

		// Define timer traits
		typedef TimerRegisterTrait<TCCR0A, TCCR0B, 0x00, TCNT0, OCR0A, OCR0B, 0x00, TIFR0, TIMSK0, TimerRegisterSize<8>> Timer0Registers;		//	This timer havent got TCCTnC and ICR registers, are set to 0x00 but, Can it provoke errors? 666 TODO
		typedef TimerRegisterTrait<TCCR1A, TCCR1B, TCCR1C, TCNT1, OCR1A, OCR1B, ICR1, TIFR1, TIMSK1, TimerRegisterSize<16>> Timer1Registers;
		typedef TimerRegisterTrait<TCCR2A, TCCR2B, 0x00, TCNT2, OCR2A, OCR2B, 0x00, TIFR2, TIMSK2, TimerRegisterSize<8>> Timer2Registers;


		// Timer class
		template<class TimerReg_, class Prescaler_, class Mode_>
		class Timer{
		public:
			void setPrescaler(Prescaler_ _prescaler);
			void setMode(Mode_ _mode);
			
			void setCompA(TimerReg_::ExtendedReg _value);
			void setCompB(TimerReg_::ExtendedReg _value);

			void enableInterruptCompA();
			void enableInterruptCompB();
			void enableInterruptOvf();
			void disableInterruptCompA();
			void disableInterruptCompB();
			void disableInterruptOvf();

		};

		// Define timers
		typedef Timer<Timer0Registers, ePrescalerType8, eTimerMode8> Timer0;
		typedef Timer<Timer1Registers, ePrescalerType16, eTimerMode16> Timer1;
		typedef Timer<Timer2Registers, ePrescalerType8, eTimerMode8> Timer2;

		// Inline implementation of timer class:
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::setPrescaler(Prescaler_ _prescaler){

		}
		
		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::setMode(Mode_ _mode){

		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::setCompA(){

		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::setCompB(){

		}
		
		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::enableInterruptCompA(){
			*TimerReg_::TIMSK |= (std::uint8_t) 0x02;
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::enableInterruptCompA(){
			*TimerReg_::TIMSK |= (std::uint8_t) 0x04;
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::enableInterruptCompA(){
			*TimerReg_::TIMSK |= (std::uint8_t) 0x01;
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::disableInterruptCompA(){
			*TimerReg_::TIMSK |= !((std::uint8_t) 0x02);
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::disableInterruptCompB(){
			*TimerReg_::TIMSK |= !((std::uint8_t) 0x04);
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_>::disableInterruptOvf(){
			*TimerReg_::TIMSK |= !((std::uint8_t) 0x01);
		}

	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_TIMER_TIMER_H_