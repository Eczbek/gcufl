#pragma once

#include "../meta/is_ptr.hpp"
#include "../meta/maybe_const.hpp"
#include "../meta/maybe_ptr.hpp"

namespace xieite {
	template<xieite::is_ptr T, bool cond>
	using maybe_const_data = xieite::maybe_ptr<xieite::maybe_const<xieite::maybe_ptr<T, false>, cond>, true>;
}
