#pragma once

#include <concepts>
#include <type_traits>
#include "../meta/try_signed.hpp"
#include "../meta/try_unsigned.hpp"

namespace xieite {
	template<std::integral T, std::integral U>
	[[nodiscard]] constexpr T sign_cast(U value) noexcept {
		return static_cast<T>(static_cast<std::conditional_t<std::signed_integral<T>, xieite::try_signed<U>, xieite::try_unsigned<U>>>(value));
	}
}
