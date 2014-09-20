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
		template<typename Port_, std::uint8_t bit_>
		class GPIOPin{
		public:
			void set_input();
			void set_output();

			void set_high();
			void set_low();
			void toggle();

		private:
			const std::uint16_t mPort = Port_;
			const std::uint8_t mBitMask = bit_;
		};
	}	//	namespace hal
}	//	namespace avr_base

#endif _AVR_BASE_HAL_GPIO_GPIO_PIN_H_	//	_AVR_BASE_HAL_GPIO_GPIO_H_