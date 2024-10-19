#pragma once

#include "../preprocessor/arrow.hpp"
#include "../preprocessor/forward.hpp"

namespace xieite::functors {
	template<std::integral auto count>
	constexpr void repeat(auto&& functor, auto&&... arguments)
	XIEITE_ARROW_BASE(([&arguments...]<auto... i>(std::integer_sequence<decltype(count), i...>) XIEITE_ARROW((..., functor.template operator()<i>(XIEITE_FORWARD(arguments)...)))))
	template<typename... Types>
	constexpr void repeat(auto&& functor, auto&&... arguments)
	XIEITE_ARROW_BASE((..., functor.template operator()<Types>(XIEITE_FORWARD(arguments)...)))
}