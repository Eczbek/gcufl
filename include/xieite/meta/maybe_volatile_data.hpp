#pragma once

#include "../meta/is_ptr.hpp"
#include "../meta/maybe_ptr.hpp"
#include "../meta/maybe_volatile.hpp"

namespace xieite {
	template<xieite::is_ptr T, bool cond>
	using maybe_volatile_data = xieite::maybe_ptr<xieite::maybe_volatile<xieite::maybe_ptr<T, false>, cond>, true>;
}
