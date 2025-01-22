#pragma once

#include "../trait/cp_c.hpp"
#include "../trait/cp_rref.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_crref = xieite::cp_c<T, xieite::cp_rref<T, U>>;
}
