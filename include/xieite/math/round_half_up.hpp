#pragma once

#include "../math/div_half_up.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_half_up(T value, T step = 1) noexcept {
		return xieite::div_half_up(value, step) * step;
	}
}
