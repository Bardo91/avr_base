///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//		avr_base library
//			Author: Pablo Ramon Soria
//			Date:	2014/09/20
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

#ifndef _AVR_BASE_HAL_GPIO_GPIO_PIN_H_
#define _AVR_BASE_HAL_GPIO_GPIO_PIN_H_

#include <cstdint>

namespace avr_base{
	namespace hal{
		template<typename port_, std::uint8_t bit_>
		class GPIOPin{
		public:
			void set_input();
			void set_output();

			void set_high();
			void set_low();
			void toggle();

			bool isHigh() const;
			bool isLow() const;

		private:
			const std::uint16_t mPort = port_;
			const std::uint8_t mBitMask = bit_;
		};

		//-------------------------------------------------------------------------------------------------------------------
		// Inline implementation
		template<typename port_, std::uint8_t bit_>
		void GPIOPin::set_input(){ *mPort::ddr |= mBitMask; };

		//-------------------------------------------------------------------------------------------------------------------
		template<typename port_, std::uint8_t bit_>
		void GPIOPin::set_output(){ *mPort::ddr &= ~mBitMask; };

		//-------------------------------------------------------------------------------------------------------------------
		template<typename port_, std::uint8_t bit_>
		void GPIOPin::set_high(){ *mPort::port |= mBitMask; };

		//-------------------------------------------------------------------------------------------------------------------
		template<typename port_, std::uint8_t bit_>
		void GPIOPin::set_low(){ *mPort::port &= ~mBitMask };

		//-------------------------------------------------------------------------------------------------------------------
		template<typename port_, std::uint8_t bit_>
		void GPIOPin::toggle(){ *mPort::pin != mBitMask };

		//-------------------------------------------------------------------------------------------------------------------
		template<typename port_, std::uint8_t bit_>
		bool GPIOPin::isHigh(){ return *port::mPin & mBitMask };
		//-------------------------------------------------------------------------------------------------------------------
		template<typename port_, std::uint8_t bit_>
		bool GPIOPin::isLow(){ return !(*port::mPin & mBitMask) };

	}	//	namespace hal
}	//	namespace avr_base

#endif _AVR_BASE_HAL_GPIO_GPIO_PIN_H_	//	_AVR_BASE_HAL_GPIO_GPIO_H_