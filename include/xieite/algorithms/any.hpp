#pragma once
#include <concepts> // std::convertible_to

namespace xieite::algorithms {
	template<std::convertible_to<bool>... T>
	[[nodiscard]]
	constexpr bool any(T&&... values) noexcept {
		return (static_cast<bool>(values) || ...);
	}
}
