#pragma once

#include "../math/pi.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	inline constexpr T tau = xieite::pi<T> * 2;
}
