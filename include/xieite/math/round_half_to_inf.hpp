#pragma once

#include <type_traits>
#include "../math/div_half_to_inf.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T round_half_to_inf(T value, std::type_identity_t<T> step = 1) noexcept {
		return xieite::div_half_to_inf(value, step) * step;
	}
}
