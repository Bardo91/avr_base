///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/20
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _AVR_BASE_HAL_GPIO_GPIO_H_
#define _AVR_BASE_HAL_GPIO_GPIO_PORT_H_

#include <cstdint>
#include "../micro/Registers.h"

namespace avr_base{
	namespace hal{
		template<	std::uint16_t pin_,
					std::uint16_t ddr_,
					std::uint16_t port_	>
		class GPIOPort{
			static  std::uint16_t mPin = pin_;
			static  std::uint16_t mDdr = ddr_;
			static  std::uint16_t mPort = port_;
		};

#ifdef PORTA
		typedef GPIOPort<DDRA, PINA, PORTA>	PortA;
#endif // PORTA
#ifdef PORTB
		typedef GPIOPort<DDRB, PINB, PORTB>	PortB;
#endif // PORTB
#ifdef PORTC
		typedef GPIOPort<DDRC, PINC, PORTC>	PortC;
#endif // PORTC
#ifdef PORTD
		typedef GPIOPort<DDRD, PIND, PORTD>	PortD;
#endif // PORTD
#ifdef PORTE
		typedef GPIOPort<DDRE, PINE, PORTE>	PortE;
#endif // PORTE
#ifdef PORTF
		typedef GPIOPort<DDRF, PINF, PORTF>	PortF;
#endif // PORTF
#ifdef PORTG
		typedef GPIOPort<DDRG, PING, PORTG>	PortG;
#endif // PORTG
#ifdef PORTH
		typedef GPIOPort<DDRH, PINH, PORTH>	PortH;
#endif // PORTH
#ifdef PORTJ
		typedef GPIOPort<DDRJ, PINJ, PORTJ>	PortJ;
#endif // PORTJ
#ifdef PORTK
		typedef GPIOPort<DDRK, PINK, PORTK>	PortK;
#endif // PORTK
#ifdef PORTL
		typedef GPIOPort<DDRL, PINL, PORTL>	PortL;
#endif // PORTL
	}	//	namespace hal
}	//	namespace avr_base

#endif _AVR_BASE_HAL_GPIO_GPIO_PORT_H_	//	_AVR_BASE_HAL_GPIO_GPIO_H_