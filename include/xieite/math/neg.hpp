#pragma once

#include <concepts>
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr bool neg(T value) noexcept {
		if constexpr (!std::unsigned_integral<T>) {
			return value < 0;
		} else {
			return false;
		}
	}
}
