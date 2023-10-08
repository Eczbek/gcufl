#ifndef XIEITE_HEADER__ALGORITHMS__FIND_OCCURRENCE
#	define XIEITE_HEADER__ALGORITHMS__FIND_OCCURRENCE

#	include <cstddef>
#	include <functional>
#	include <ranges>
#	include "../concepts/Functable.hpp"

namespace xieite::algorithms {
	template<std::ranges::range Range, xieite::concepts::Functable<bool(std::ranges::range_value_t<Range>, std::ranges::range_value_t<Range>)> Functor = std::ranges::equal_to>
	[[nodiscard]] constexpr std::ranges::const_iterator_t<const Range&> findOccurrence(const Range& range, const std::ranges::range_const_reference_t<Range> value, std::size_t count, const Functor& comparator = Functor()) {
		const auto end = std::ranges::end(range);
		for (auto begin = std::ranges::begin(range); begin != end; ++begin) {
			if (std::invoke(comparator, *begin, value) && !count--) {
				return begin;
			}
		}
		return end;
	}
}

#endif
