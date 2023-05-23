#ifndef XIEITE_HEADER_ALGORITHMS_PARTIALREVERSE
#	define XIEITE_HEADER_ALGORITHMS_PARTIALREVERSE

#	include <algorithm>
#	include <cstddef>
#	include <iterator>
#	include <vector>
#	include <xieite/concepts/Functional.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator ForwardIterator>
	constexpr void partialReverse(ForwardIterator begin, const std::sentinel_for<ForwardIterator> auto end, const xieite::concepts::Functional<bool(std::iter_value_t<ForwardIterator>)> auto& selector) {
		std::vector<ForwardIterator> iterators;
		for (; begin != end; ++begin) {
			if (selector(*begin)) {
				iterators.push_back(begin);
			}
		}
		const std::size_t iteratorsSize = iterators.size();
		for (std::size_t i = 0; i < iteratorsSize / 2; ++i) {
			std::iter_swap(iterators[i], iterators[iteratorsSize - i - 1]);
		}
	}
}

#endif
