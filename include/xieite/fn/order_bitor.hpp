#pragma once

#include <compare>
#include "../trait/is_order.hpp"

namespace xieite::order_bitor {
	template<xieite::is_order Order>
	[[nodiscard]] constexpr Order operator|(Order left, Order right) noexcept {
		return std::is_eq(left) ? right : left;
	}
}
