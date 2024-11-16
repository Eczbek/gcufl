#pragma once

#include "../math/div_trunc.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T trunc(T value, T step = 1) noexcept {
		return xieite::div_trunc(value, step) * step;
	}
}
