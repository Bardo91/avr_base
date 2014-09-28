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
		template<>
		struct TimerRegisterSize<8>{
			typedef std::uint8_t ExtendedReg;
		};

		//-------------------------------------------------------------------------------------------------------------
		template<>
		struct TimerRegisterSize<16>{
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
					class sizeTrait_>
		class TimerRegisterTrait{
		public:
			typedef typename sizeTrait_::ExtendedReg ExtendedReg;
		
		private:
			static constexpr std::uint8_t* TCCRA	= reinterpret_cast<std::uint8_t*>(TCCRnA_);
			static constexpr std::uint8_t* TCCRB	= reinterpret_cast<std::uint8_t*>(TCCRnB_);
			static constexpr std::uint8_t* TCCRC	= reinterpret_cast<std::uint8_t*>(TCCRnC_);
			static constexpr ExtendedReg* TCNT		= reinterpret_cast<ExtendedReg*>(TCNT_);		// This registers have 2 bytes in timer 1
			static constexpr ExtendedReg* OCRA		= reinterpret_cast<ExtendedReg*>(OCRnA_);
			static constexpr ExtendedReg* OCRB		= reinterpret_cast<ExtendedReg*>(OCRnB_);
			static constexpr ExtendedReg* ICR		= reinterpret_cast<ExtendedReg*>(ICRn_);
			static constexpr std::uint8_t* TIFR		= reinterpret_cast<std::uint8_t*>(TIFRn_);
			static constexpr std::uint8_t* TIMSK	= reinterpret_cast<std::uint8_t*>(TIMSKn_);
		};

		// Prescaler types
		enum class ePrescalerType {	eNonClock = 0,
									e1 = 1,
									e8 = 2,
									e64 = 3,
									e256 = 4,
									e1024 = 5,
									eExt0Falling = 6,
									eExt0Rising = 7	};



		// Timer modes
		enum class eTimerMode8 { eNormal = 0 };
		enum class eTimerMode16 { eNormal = 0 };

		// Define timer traits
		typedef TimerRegisterTrait<TCCR0A, TCCR0B, 0x00, TCNT0, OCR0A, OCR0B, 0x00, TIFR0, TIMSK0, TimerRegisterSize<8>> Timer0Registers;		//	This timer havent got TCCTnC and ICR registers, are set to 0x00 but, Can it provoke errors? 666 TODO
		typedef TimerRegisterTrait<TCCR1A, TCCR1B, TCCR1C, TCNT1, OCR1A, OCR1B, ICR1, TIFR1, TIMSK1, TimerRegisterSize<16>> Timer1Registers;
		typedef TimerRegisterTrait<TCCR2A, TCCR2B, 0x00, TCNT2, OCR2A, OCR2B, 0x00, TIFR2, TIMSK2, TimerRegisterSize<8>> Timer2Registers;


		// Timer class
		template<class TimerReg_, class Prescaler_, class Mode_>
		class Timer{
		public:
			typedef typename TimerReg_::ExtendedReg ExtendedReg;

			void setPrescaler(Prescaler_ _prescaler);
			void setMode(Mode_ _mode);
			
			void setCompA(ExtendedReg _value);
			void setCompB(ExtendedReg _value);

			void enableInterruptCompA();
			void enableInterruptCompB();
			void enableInterruptOvf();
			void disableInterruptCompA();
			void disableInterruptCompB();
			void disableInterruptOvf();

		};

		// Define timers
		typedef Timer<Timer0Registers, ePrescalerType, eTimerMode8> Timer0;
		typedef Timer<Timer1Registers, ePrescalerType, eTimerMode16> Timer1;
		typedef Timer<Timer2Registers, ePrescalerType, eTimerMode8> Timer2;

		// Inline implementation of timer class:
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::setPrescaler(Prescaler_ _prescaler){
			*TimerReg_::TCCRB &= static_cast<std::uint8_t>(_prescaler);
		}
		
		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::setMode(Mode_ _mode){
			// 666 TODO: to do later
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::setCompA(std::uint8_t _value){
			*TimerReg_::OCRA = _value;
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::setCompB(std::uint8_t _value){
			*TimerReg_::OCRA = _value;
		}
		
		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::enableInterruptCompA(){
			*TimerReg_::TIMSK |= (std::uint8_t) 0x02;
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::disableInterruptCompA(){
			*TimerReg_::TIMSK |= (std::uint8_t) 0x04;
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::enableInterruptCompB(){
			*TimerReg_::TIMSK |= (std::uint8_t) 0x01;
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::disableInterruptCompB(){
			*TimerReg_::TIMSK |= !((std::uint8_t) 0x04);
		}

		//-------------------------------------------------------------------------------------------------------------
		template<class TimerReg_, class Prescaler_, class Mode_>
		void Timer<class TimerReg_, class Prescaler_, class Mode_>::disableInterruptOvf(){
			*TimerReg_::TIMSK |= !((std::uint8_t) 0x01);
		}

	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_TIMER_TIMER_H_