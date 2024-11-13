#pragma once

#include "../math/div_half_to_zero.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_half_to_zero(T value, T step = 1) noexcept {
		return xieite::div_half_to_zero(value, step) * step;
	}
}
