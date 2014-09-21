///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/22
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 

#include "Time.h"

namespace avr_base{
	// Static data initialization
	volatile std::uint32_t Time::sMicros = 0;
	volatile std::uint32_t Time::sMillis = 0;

	//-----------------------------------------------------------------------------------------------------------------
	void Time::init(){

		sTimer.setCompA(2000);
		sTimer.setPrescaler(hal::ePrescalerType::e8);
		sTimer.setMode(MODE);
	}
	//-----------------------------------------------------------------------------------------------------------------

	//-----------------------------------------------------------------------------------------------------------------
}

