#pragma once

#include "../trait/rm_c_referent.hpp"
#include "../trait/rm_noex.hpp"

namespace xieite {
	template<typename T>
	using rm_c_noex = xieite::rm_c_referent<xieite::rm_noex<T>>;
}
