#pragma once

#include <functional>
#include <type_traits>
#include <utility>
#include "../preprocessor/arrow.hpp"
#include "../preprocessor/forward.hpp"
#include "../types/list.hpp"
#include "../types/maybe_constant.hpp"

namespace xieite::functors {
	template<typename Functor, typename... Arguments>
	/* discardable */ constexpr auto tryConstantArguments(Functor&& functor, Arguments&&... arguments)
	XIEITE_ARROW(
		xieite::types::List<Arguments...>
		::template Transform<
			1,
			[]<typename Argument, typename... First> {
				return std::type_identity<
					std::conditional_t<
						xieite::types::List<Arguments...>
						::template Slice<sizeof...(First) + 1>
						::template Prepend<Functor, First..., xieite::types::MaybeConstant<Argument, true>>
						::template To<std::is_invocable>
						::value,
						xieite::types::MaybeConstant<Argument, true>,
						Argument
					>
				>();
			}
		>
		::apply(
			[&functor, &arguments...]<typename... MaybeConstantArguments>
			XIEITE_ARROW(std::invoke(XIEITE_FORWARD(functor), std::forward_like<MaybeConstantArguments>(arguments)...))
		)
	)
}
