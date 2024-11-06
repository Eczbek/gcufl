#pragma once

#include "../meta/is_satisfies_any.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_dissatisfies_all = !xieite::is_satisfies_any<T, fns...>;
}
