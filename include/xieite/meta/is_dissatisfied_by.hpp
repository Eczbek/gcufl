#pragma once

#include "../meta/is_satisfied_by.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_by = !xieite::is_satisfied_by<fn, Ts...>;
}
