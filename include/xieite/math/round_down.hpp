#pragma once

#include "../math/div_down.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_down(T value, T step = 1) noexcept {
		return xieite::div_down(value, step) * step;
	}
}
