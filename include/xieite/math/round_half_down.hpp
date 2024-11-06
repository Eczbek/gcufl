#pragma once

#include <type_traits>
#include "../math/div_half_down.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_half_down(T value, std::type_identity_t<T> step = 1) noexcept {
		return xieite::div_half_down(value, step) * step;
	}
}
