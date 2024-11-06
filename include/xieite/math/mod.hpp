#pragma once

#include <type_traits>
#include "../math/rem.hpp"
#include "../math/sign.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr T mod(T dividend, std::type_identity_t<T> divisor) noexcept {
		return xieite::rem(xieite::rem(dividend, divisor) + divisor * (xieite::sign(dividend) != xieite::sign(divisor)), divisor);
	}
}
