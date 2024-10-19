#pragma once

#include <type_traits>
#include "../concepts/arithmetic.hpp"
#include "../math/limits_fixed.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr bool isBetweenFixed(const Arithmetic value, const std::type_identity_t<Arithmetic> limit1, const std::type_identity_t<Arithmetic> limit2, const bool lowerInclusive = true, const bool upperInclusive = true) noexcept {
		const auto [lower, upper] = xieite::math::limitsFixed(limit1, limit2);
		return (lowerInclusive ? (value >= lower) : (value > lower))
			&& (upperInclusive ? (value <= upper) : (value < upper));
	}
}
