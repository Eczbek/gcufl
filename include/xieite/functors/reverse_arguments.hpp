#pragma once

#include <tuple>
#include "../containers/reverse_tuple.hpp"
#include "../preprocessor/arrow.hpp"
#include "../preprocessor/forward.hpp"
#include "../types/list.hpp"

namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	constexpr auto reverseArguments(Functor&& functor, Arguments&&... arguments)
	XIEITE_ARROW(std::apply(XIEITE_FORWARD(functor), xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...))))

	template<typename Structure, typename... Arguments>
	[[nodiscard]] constexpr auto reverseArguments(Arguments&&... arguments)
	XIEITE_ARROW(std::make_from_tuple<Structure>(xieite::containers::reverseTuple(std::forward_as_tuple(XIEITE_FORWARD(arguments)...))))
}
