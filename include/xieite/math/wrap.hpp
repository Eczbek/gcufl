#pragma once

#include <algorithm>
#include <type_traits>
#include "../concepts/arithmetic.hpp"
#include "../math/modulo.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr Arithmetic wrap(const Arithmetic value, const std::type_identity_t<Arithmetic> limit1, const std::type_identity_t<Arithmetic> limit2) noexcept {
		const Arithmetic minimum = std::min(limit1, limit2);
		return xieite::math::modulo(value - minimum, std::max(limit1, limit2) - minimum + 1) + minimum;
	}
}
