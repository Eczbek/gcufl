#pragma once

#include <tuple>
#include "../meta/tuple_reverse.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename F, typename... Args>
	constexpr auto reverse_args(F&& fn, Args&&... args)
	XIEITE_ARROW(std::apply(XIEITE_FWD(fn), xieite::tuple_reverse(std::forward_as_tuple(XIEITE_FWD(args)...))))

	template<typename T, typename... Args>
	[[nodiscard]] constexpr auto reverse_args(Args&&... args)
	XIEITE_ARROW(std::make_from_tuple<T>(xieite::tuple_reverse(std::forward_as_tuple(XIEITE_FWD(args)...))))
}
