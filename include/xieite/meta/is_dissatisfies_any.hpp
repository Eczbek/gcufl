#pragma once

#include "../meta/is_satisfies_all.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_dissatisfies_any = !xieite::is_satisfies_all<T, fns...>;
}
