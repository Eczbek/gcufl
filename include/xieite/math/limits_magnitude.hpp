#pragma once

#include <concepts>
#include "../concepts/arithmetic.hpp"
#include "../math/closest_to.hpp"
#include "../math/farthest_from.hpp"
#include "../math/interval.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic First, std::convertible_to<First>... Rest>
	[[nodiscard]] constexpr xieite::math::Interval<First> limitsMagnitude(const First first, const Rest... rest) noexcept {
		auto result = xieite::math::Interval<First>(first, first);
		(..., (result =
			xieite::math::Interval<First>(
				xieite::math::closestTo(static_cast<First>(0), result.start, static_cast<First>(rest)),
				xieite::math::farthestFrom(static_cast<First>(0), result.end, static_cast<First>(rest))
			)
		));
		return result;
	}
}
