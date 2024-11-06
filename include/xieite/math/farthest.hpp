#pragma once

#include <type_traits>
#include "../math/diff.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T farthest(T target, std::type_identity_t<T> value0, std::type_identity_t<T> value1) noexcept {
		return (xieite::diff(target, value0) > xieite::diff(target, value1)) ? value0 : value1;
	}
}
