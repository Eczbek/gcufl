#pragma once

#include <concepts>
#include "../math/neg.hpp"
#include "../meta/try_unsign.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr xieite::try_unsign<T> abs(T value) noexcept {
		if constexpr (std::floating_point<T>) {
			return std::abs(value);
		} else {
			return xieite::neg(value)
				? -static_cast<xieite::try_unsign<T>>(value)
				: static_cast<xieite::try_unsign<T>>(value);
		}
	}
}
