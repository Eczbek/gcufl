#pragma once

#include "../math/diff.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T farthest(T target, T value0, T value1) noexcept {
		return (xieite::diff(target, value0) > xieite::diff(target, value1)) ? value0 : value1;
	}
}
