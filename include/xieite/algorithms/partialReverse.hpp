#pragma once

#include <algorithm>
#include <cstddef>
#include <iterator>
#include <vector>
#include <xieite/concepts/Function.hpp>

namespace xieite::algorithms {
	template<std::forward_iterator Iterator>
	constexpr void partialReverse(Iterator begin, const Iterator end, const xieite::concepts::Function<bool(typename std::iterator_traits<Iterator>::value_type)> auto& selector) {
		std::vector<Iterator> iterators;
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
