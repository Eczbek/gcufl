#pragma once

#include "../meta/is_satisfied_by_any.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_by_all = !xieite::is_satisfied_by_any<fn, Ts...>;
}
