#ifndef XIEITE_HEADER_MATH_CLOSEST_TO
#	define XIEITE_HEADER_MATH_CLOSEST_TO

#	include <concepts>
#	include <type_traits>
#	include "../concepts/arithmetic.hpp"
#	include "../math/difference.hpp"

namespace xieite::math {
	template<xieite::concepts::Arithmetic Number>
	[[nodiscard]] constexpr std::conditional_t<std::is_const_v<Number>, Number, Number&> closestTo(const Number target, Number& value1, Number& value2) noexcept {
		return (value1 >= target) ? ((value2 >= target) ? ((value1 < value2) ? value1 : value2) : ((xieite::math::difference(target, value1) > xieite::math::difference(target, value2)) ? value1 : value2)) : ((value2 < target) ? ((value1 > value2) ? value1 : value2) : ((xieite::math::difference(target, value1) < xieite::math::difference(target, value2)) ? value1 : value2));
	}
}

#endif
