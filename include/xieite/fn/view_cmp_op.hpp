#pragma once

#include <algorithm>
#include <ranges>

namespace xieite::view_cmp_op {
	template<typename T>
	[[nodiscard]] constexpr auto operator<=>(const std::ranges::view_interface<T>& left, const std::ranges::view_interface<T>& right) noexcept {
		return std::ranges::lexicographical_compare(left.cbegin(), left.cend(), right.cbegin(), right.cend());
	}
}
