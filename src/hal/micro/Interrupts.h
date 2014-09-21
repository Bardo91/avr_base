///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/21
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// Interrupt basic definitions


#ifndef _AVR_BASE_HAL_MICRO_INTERRUPTS_H_
#define _AVR_BASE_HAL_MICRO_INTERRUPTS_H_

namespace avr_base{
	namespace hal{
		//	This macro is used to declare inline implementation of the program to be executed 
		//	when an interrupt occur. Example:
		//
		//			Interrupt(TIMER0_COMPA){
		//				doSomething();
		//			}
		//
		#define Interrupt(vector_) \
		extern "C" void vector_(void) __attribute__((signal, used)); \
		void vector_(void)
		
		#define ExtendedInterrupt(vector_, options_) \
		extern "C" void vector_(void) __attribute__((signal, used, options_)); \
		void vector_(void)

		// This macro is used to attach an existing function to an interrupt. Example:
		//
		//			void doSomething(){
		//				something;
		//			}
		//			MapInterrupt(TIMER0_COMPA, doSomething)
		//
		#define MapInterrupt(vector_, callback_) \
		extern "C" void vector_(void) __attribute__((signal, used)); \
		void vector_(void) { callback_(); }

		#define _VECTOR(N) __vector_ ## N

		#if defined (__ATMEGA328P__)
			#define RESET			_VECTOR(1)	// External pin, Power-on Reset, Brown-out reset and watchdog system reset
			#define INT0			_VECTOR(2)	// External interrupt request 0 
			#define INT1			_VECTOR(3)	// External interrupt request 1
			#define PCINT0			_VECTOR(4)	// Pin change interrupt request 0
			#define PCINT1			_VECTOR(5)	// Pin change interrupt request 1
			#define PCINT2			_VECTOR(6)	// Pin change interrupt request 2
			#define WDT				_VECTOR(7)	// Watchdog time-out interrupt
			#define TIMER2_COMPA	_VECTOR(8)	// Timer/Counter2 Compare Match A
			#define TIMER2_COMPB	_VECTOR(9)	// Timer/Counter2 Compare Match B
			#define TIMER2_OVF		_VECTOR(10)	// Timer/Counter2 Overflow
			#define TIMER1_CAPT		_VECTOR(11)	// Timer/Counter1 Capture event
			#define TIMER1_COMPA	_VECTOR(12)	// Timer/Counter1 Compare Match A
			#define TIMER1_COMPB	_VECTOR(13)	// Timer/Counter1 ComPare Match B
			#define TIMER1_OVF		_VECTOR(14)	// Timer/Counter1 Overflow
			#define TIMER0_COMPA	_VECTOR(15)	// Timer/Counter0 Compare Match A
			#define TIMER0_COMPB	_VECTOR(16)	// Timer/Counter0 Compare Match B
			#define TIMER0_OVF		_VECTOR(17)	// Timer/Counter0 Overflow
			#define SPI_STC			_VECTOR(18)	// SPI serial transfer complete
			#define USART_RX		_VECTOR(19)	// USART RX complete
			#define USART_UDRE		_VECTOR(20)	// USART data resgister empty
			#define USART_TX		_VECTOR(21)	// USART Tx complete
			#define ADC				_VECTOR(22)	// ADC conversion Complete
			#define EE_READY		_VECTOR(23)	// EEPROM ready
			#define ANALOG_COMP		_VECTOR(24)	// Analog comparator
			#define TWI				_VECTOR(25)	// 2-wire serial interface
			#define SPM_READY		_VECTOR(26)	// Store Program Memory Ready
		#endif
	}	//	namespace hal
}	//	namespace avr_base

#endif	//	_AVR_BASE_HAL_MICRO_INTERRUPTS_H_