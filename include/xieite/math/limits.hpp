#pragma once

#include <algorithm>
#include <concepts>
#include "../math/intv.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T, std::convertible_to<T>... Ts>
	[[nodiscard]] constexpr xieite::intv<T> limits(T first, Ts... rest) noexcept {
		auto result = xieite::intv<T>(first, first);
		(..., (result =
			xieite::intv<T>(
				std::min(result.start, rest),
				std::max(result.end, rest)
			)
		));
		return result;
	}
}
