#pragma once

#include "../meta/is_satisfies.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_satisfies_all = (... && xieite::is_satisfies<T, fns>);
}
