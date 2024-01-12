#ifndef XIEITE_HEADER_ALGORITHMS_ANY
#	define XIEITE_HEADER_ALGORITHMS_ANY

#	include <algorithm>
#	include <concepts>
#	include <ranges>
#	include "../concepts/no_throw_convertible_to.hpp"
#	include "../concepts/range_of.hpp"

namespace xieite::algorithms {
	template<xieite::concepts::RangeOf<bool> Range>
	[[nodiscard]] constexpr bool any(const Range& range)
	noexcept(noexcept(xieite::concepts::NoThrowConvertibleTo<std::ranges::range_reference_t<Range>, bool>)) {
		return !std::ranges::none_of(range, [](const auto value) {
			return static_cast<bool>(value);
		});
	}

	template<std::convertible_to<bool>... Values>
	[[nodiscard]] constexpr bool any(const Values&... values)
	noexcept(noexcept((... && xieite::concepts::NoThrowConvertibleTo<Values, bool>))) {
		return (... || static_cast<bool>(values));
	}
}

#endif
