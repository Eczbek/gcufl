#pragma once

#include "../math/div_floor.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T floor(T value, T step = 1) noexcept {
		return xieite::div_floor(value, step) * step;
	}
}
