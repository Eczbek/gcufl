#pragma once

#include "../trait/add_ptr.hpp"
#include "../meta/get_ptr.hpp"
#include "../trait/rm_ptr.hpp"

namespace xieite {
	template<typename T, typename U>
	using cp_ptr = xieite::add_ptr<xieite::get_ptr<T>, xieite::rm_ptr<U>>;
}
