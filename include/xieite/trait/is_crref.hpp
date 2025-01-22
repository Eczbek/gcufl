#pragma once

#include "../trait/is_c.hpp"
#include "../trait/is_rref.hpp"

namespace xieite {
	template<typename T>
	concept is_crref = xieite::is_c<T> && xieite::is_rref<T>;
}
