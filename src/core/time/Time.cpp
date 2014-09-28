///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/22
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 

#include "Time.h"
#include "../../hal/interrupt/InterruptMgr.h"

using namespace avr_base::hal;

// Map interrupt of COMPA with tickTimer
MapInterrupt(TIMER1_COMPA, avr_base::Time::tickTimer);

namespace avr_base{
	// Static data initialization
	volatile std::uint32_t Time::sMicros = 0;
	volatile std::uint32_t Time::sMillis = 0;

	//-----------------------------------------------------------------------------------------------------------------
	void Time::init(){

		sTimer.setCompA(2000);							// Set the top comp
		sTimer.setPrescaler(hal::ePrescalerType::e8);	// Set the "speed"
		sTimer.setMode(Timer1::Mode::eCTCA);			// Set the mode of the timer
		sTimer.enableInterruptCompA();					// Enable interrupts related to comparing with A registers
	}
	//-----------------------------------------------------------------------------------------------------------------
	void Time::delayMs(unsigned _millis){
		unsigned s0 = millis();
		while ((millis() - s0) < _millis)
		{ }
	}

	//-----------------------------------------------------------------------------------------------------------------
	void Time::delayUs(unsigned _micros){
		unsigned s0 = micros();
		while ((micros() - s0) < _micros)
		{ }
	}

	//-----------------------------------------------------------------------------------------------------------------
	unsigned Time::seconds(){
		InterruptMgr::lockInterrupts();
		unsigned temp = static_cast<unsigned>(sMillis);
		InterruptMgr::unlockInterrupts();
		return unsigned(temp / 1000);
	}

	//-----------------------------------------------------------------------------------------------------------------
	unsigned Time::millis(){
		InterruptMgr::lockInterrupts();
		unsigned temp = static_cast<unsigned>(sMillis);
		InterruptMgr::unlockInterrupts();
		return temp;
	}

	//-----------------------------------------------------------------------------------------------------------------
	unsigned Time::micros(){
		InterruptMgr::lockInterrupts();
		unsigned temp = static_cast<unsigned>(sMicros);
		InterruptMgr::unlockInterrupts();
		return temp;
	}

	//-----------------------------------------------------------------------------------------------------------------
	void Time::tickTimer(){
		sMillis++;
		sMicros += 1000;
	}
}

