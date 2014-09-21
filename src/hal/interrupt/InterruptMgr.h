///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/21
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


#ifndef _AVR_BASE_HAL_INTERRUPT_INTERRUPT_MGR_H_
#define _AVR_BASE_HAL_INTERRUPT_INTERRUPT_MGR_H_

#include <cstdint>

namespace avr_base{
	namespace hal{

		class InterruptMgr{
		public:
			static void init();
			static void lockInterrupts();
			static void unlockInterrupts();

			// Every process is responsible of disabling and enabling it's interrupt.
			static void startInterrupt();
			static void endInterrupt();


		private:
			static std::uint8_t nLocks;
		};

	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_INTERRUPT_INTERRUPT_MGR_H_