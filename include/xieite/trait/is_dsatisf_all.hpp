#pragma once

#include "../trait/is_satisf_any.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_dsatisf_all = !xieite::is_satisf_any<T, fns...>;
}
