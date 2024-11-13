#pragma once

#include <cmath>
#include "../math/almost_eq.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T value0, T value1) noexcept {
		return (std::isinf(value0) && std::isinf(value1)) || xieite::almost_eq(value0, value1);
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T value0, T value1, T epsilon) noexcept {
		return (std::isinf(value0) && std::isinf(value1)) || xieite::almost_eq(value0, value1, epsilon);
	}
}
