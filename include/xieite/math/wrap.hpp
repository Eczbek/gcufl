#pragma once

#include <type_traits>
#include "../math/mod.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T wrap(T value, std::type_identity_t<T> limit0, std::type_identity_t<T> limit1) noexcept {
		const auto [min, max] = xieite::limits(limit0, limit1);
		return xieite::mod(value - min, max - min) + min;
	}
}
