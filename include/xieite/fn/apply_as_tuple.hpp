#pragma once

#include <tuple>
#include <type_traits>
#include "../meta/make_tuple.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename F, typename V>
	constexpr auto apply_as_tuple(F&& fn, V&& value)
	XIEITE_ARROW(std::apply(XIEITE_FWD(fn), xieite::make_tuple(XIEITE_FWD(value))))

	template<typename T, typename V>
	[[nodiscard]] constexpr T apply_as_tuple(V&& value)
	XIEITE_ARROW(std::make_from_tuple<T>(xieite::make_tuple(XIEITE_FWD(value))))
}
