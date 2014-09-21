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

#include "../hal/timer/Timer.h"

namespace avr_base{
	class Time{		// Singleton class with utils about time. Use Timer 1
	public:
		static void		delayUs(unsigned _micros);
		static void		delayMs(unsigned _millis);

		static void init();
	private:
		static hal::Timer1 sTimer;

	};

}	//	namespace avr_base


#endif	//	_AVR_BASE_CORE_TIME_H_