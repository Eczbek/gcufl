#pragma once

#include "../meta/is_ptr.hpp"
#include "../meta/set_const.hpp"
#include "../meta/set_ptr.hpp"

namespace xieite {
	template<xieite::is_ptr T, bool cond>
	using set_const_data = xieite::set_ptr<xieite::set_const<xieite::set_ptr<T, false>, cond>, true>;
}
