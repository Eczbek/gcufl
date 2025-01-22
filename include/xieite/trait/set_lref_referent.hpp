#pragma once

#include <type_traits>
#include "../trait/add_lref_referent.hpp"
#include "../trait/rm_lref_referent.hpp"

namespace xieite {
	template<bool qual, typename T>
	using set_lref_referent = std::conditional_t<qual, xieite::add_lref_referent<T>, xieite::rm_lref_referent<T>>;
}
