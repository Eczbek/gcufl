#pragma once

#include <tuple>
#include "../meta/tuple_rev.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename F, typename... Args>
	constexpr auto rev_args(F&& fn, Args&&... args)
	XIEITE_ARROW(std::apply(XIEITE_FWD(fn), xieite::tuple_rev(std::forward_as_tuple(XIEITE_FWD(args)...))))

	template<typename T, typename... Args>
	[[nodiscard]] constexpr auto rev_args(Args&&... args)
	XIEITE_ARROW(std::make_from_tuple<T>(xieite::tuple_rev(std::forward_as_tuple(XIEITE_FWD(args)...))))
}
