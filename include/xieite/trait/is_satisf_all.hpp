#pragma once

#include "../trait/is_satisf.hpp"

namespace xieite {
	template<typename T, auto... fns>
	concept is_satisf_all = (... && xieite::is_satisf<T, fns>);
}
