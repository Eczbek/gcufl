#pragma once

#include <tuple>
#include "../meta/is_spec.hpp"
#include "../pp/fwd.hpp"
#include "../pp/lift.hpp"

namespace xieite {
	template<xieite::is_spec<std::tuple> Tuple>
	[[nodiscard]] constexpr auto tuple_fwd(Tuple&& tuple) noexcept {
		return std::apply(XIEITE_LIFT(std::forward_as_tuple), XIEITE_FWD(tuple));
	}
}
