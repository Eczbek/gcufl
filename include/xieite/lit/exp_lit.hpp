#pragma once

#include "../math/exp.hpp"

namespace xieite::exp_lit {
	[[nodiscard]] constexpr auto operator""_exp(unsigned long long int value) noexcept {
		return xieite::exp(value);
	}

	[[nodiscard]] constexpr auto operator""_exp(long double value) noexcept {
		return xieite::exp(value);
	}
}
