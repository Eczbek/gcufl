#pragma once

#include "../math/div_half_to_inf.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_half_to_inf(T value, T step = 1) noexcept {
		return xieite::div_half_to_inf(value, step) * step;
	}
}
