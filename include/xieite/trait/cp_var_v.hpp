#pragma once

#include "../trait/cp_v_referent.hpp"
#include "../trait/cp_var.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_var_v = xieite::cp_var<T, xieite::cp_v_referent<T, U>>;
}
