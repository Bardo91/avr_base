///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/22
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 


#ifndef _AVR_BASE_CORE_TIME_H_
#define _AVR_BASE_CORE_TIME_H_

#include "../../hal/timer/Timer.h"
#include <cstdint>

namespace avr_base{
	class Time{		// Singleton class with utils about time. Use Timer 1
	public:
		static void init();

		static void		delayUs(unsigned _micros);
		static void		delayMs(unsigned _millis);
				
		static unsigned seconds();
		static unsigned millis();
		static unsigned micros();

		static void tickTimer();
	private:
		static volatile std::uint32_t sMillis;
		static volatile std::uint32_t sMicros;

		static hal::Timer1 sTimer;

	};

}	//	namespace avr_base


#endif	//	_AVR_BASE_CORE_TIME_H_