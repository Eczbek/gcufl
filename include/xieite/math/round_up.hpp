#pragma once

#include "../math/div_up.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_up(T value, T step = 1) noexcept {
		return xieite::div_up(value, step) * step;
	}
}
