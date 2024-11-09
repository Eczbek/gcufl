#pragma once

#include "../meta/is_ptr.hpp"
#include "../meta/set_ptr.hpp"
#include "../meta/set_volat.hpp"

namespace xieite {
	template<xieite::is_ptr T, bool cond>
	using set_volat_data = xieite::set_ptr<xieite::set_volat<xieite::set_ptr<T, false>, cond>, true>;
}
