#pragma once

#include <algorithm>
#include <type_traits>
#include "../math/mod.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T wrap(T value, std::type_identity_t<T> limit0, std::type_identity_t<T> limit1) noexcept {
		const T min = std::min(limit0, limit1);
		return xieite::mod(value - min, std::max(limit0, limit1) - min + 1) + min;
	}
}
