#pragma once
#include <cmath> // std::fmod
#include <xieite/concepts/Arithmetic.hpp>

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]]
	constexpr Number wrap(const Number value, const Number max, const Number min = 0.0) noexcept {
		const Number diff = max - min + 1.0;
		return std::fmod(std::fmod(value - min, diff) + diff, diff) + min;
	}
}
