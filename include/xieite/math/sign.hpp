#pragma once

#include "../math/neg.hpp"
#include "../meta/is_arith.hpp"
#include "../pp/fn.hpp"

namespace xieite {
	template<xieite::is_arith T, xieite::is_arith... Ts>
	[[nodiscard]] constexpr int sign(T first, Ts... rest) noexcept {
		static constexpr auto get = XIEITE_FN(($0 > 0) - xieite::neg($0));
		return (get(first) * ... * get(rest));
	}
}
