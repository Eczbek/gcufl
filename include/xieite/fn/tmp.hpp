#pragma once

namespace xieite {
	template<typename T>
	[[nodiscard]] constexpr T& tmp(T&& value = {}) noexcept {
		return { value }; // :)
	}
}
