#pragma once

#include <concepts>
#include <limits>
#include "../meta/is_arith.hpp"
#include "../math/abs.hpp"
#include "../math/neg.hpp"

namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr bool mul_overflow(T first, Ts... rest) noexcept {
		return sizeof...(Ts)
			&& first
			&& (... || ([&first, rest] -> bool {
				if (rest && ((xieite::abs((xieite::neg(first) != xieite::neg(rest)) ? std::numeric_limits<T>::min() : std::numeric_limits<T>::max()) / xieite::abs(first)) < xieite::abs(rest))) {
					return true;
				}
				first *= static_cast<T>(rest);
				return false;
			})());
	}
}
