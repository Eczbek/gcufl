#pragma once

#include <cmath>
#include <type_traits>
#include "../math/almost_eq.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T value0, std::type_identity_t<T> value1) noexcept {
		return (std::isinf(value0) && std::isinf(value1)) || xieite::almost_eq(value0, value1);
	}

	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool almost_eq_slope(T value0, std::type_identity_t<T> value1, std::type_identity_t<T> epsilon) noexcept {
		return (std::isinf(value0) && std::isinf(value1)) || xieite::almost_eq(value0, value1, epsilon);
	}
}
