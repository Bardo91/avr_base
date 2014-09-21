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

#include <cstdint>

namespace avr_base{
	namespace hal{
		// Timer traits
		template<	std::uint16_t TCCRnA_,
					std::uint16_t TCCRnB,
					std::uint16_t TCNT_, 
					std::uint16_t OCRnA_,
					std::uint16_t OCRnB_,
					std::uint16_t TOVn_,
					std::uint16_t TIFRn_,
					std::uint16_t TIMSKn_>
		class TimerRegisterTrait{
			static const std::uint8_t* 
		};





	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_TIMER_TIMER_H_