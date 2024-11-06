#pragma once

#include <cmath>
#include <concepts>
#include <type_traits>
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T rem(T dividend, std::type_identity_t<T> divisor) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::fmod(dividend, divisor);
		} else {
			return dividend % divisor;
		}
	}
}
