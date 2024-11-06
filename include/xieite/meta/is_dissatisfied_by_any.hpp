#pragma once

#include "../meta/is_satisfied_by_all.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dissatisfied_by_any = !xieite::is_satisfied_by_all<fn, Ts...>;
}
