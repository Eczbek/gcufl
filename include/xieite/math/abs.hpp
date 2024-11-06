#pragma once

#include <concepts>
#include "../math/neg.hpp"
#include "../meta/is_arith.hpp"
#include "../meta/try_unsigned.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr xieite::try_unsigned<T> abs(T value) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(value);
		} else {
			return xieite::neg(value)
				? -static_cast<xieite::try_unsigned<T>>(value)
				: static_cast<xieite::try_unsigned<T>>(value);
		}
	}
}
