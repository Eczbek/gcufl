#pragma once

#include <bit>
#include <concepts>

namespace xieite {
	template<std::integral T>
	[[nodiscard]] constexpr T big_endify(T value) noexcept {
		return (std::endian::native == std::endian::little) ? std::byteswap(value) : value;
	}
}
