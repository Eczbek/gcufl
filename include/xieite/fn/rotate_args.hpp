#pragma once

#include <cstddef>
#include <functional>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<std::size_t n, typename F, typename... Args>
	constexpr auto rotate_args(F&& fn, Args&&... args)
	XIEITE_ARROW(xieite::unroll<Args...>(
		[&fn, args_tuple = std::forward_as_tuple(XIEITE_FWD(args)...)]<std::size_t... i>
		XIEITE_ARROW(std::invoke(
			XIEITE_FWD(fn),
			std::get<(i + n % sizeof...(Args)) % sizeof...(Args)>(std::move(args_tuple))...
		))
	))
}

// Note: the `std::move` is necessary
