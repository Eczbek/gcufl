#pragma once

#include <concepts>
#include <type_traits>
#include "../meta/try_sign.hpp"
#include "../meta/try_unsign.hpp"
#include "../pp/arrow.hpp"

namespace xieite {
	template<std::integral T>
	constexpr auto sign_cast = []<std::integral U>(U n) static noexcept {
		return static_cast<T>(static_cast<std::conditional_t<std::signed_integral<T>, xieite::try_sign<U>, xieite::try_unsign<U>>>(n));
	};
}
