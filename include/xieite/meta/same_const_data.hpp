#pragma once

#include "../meta/set_const_data.hpp"
#include "../trait/is_const.hpp"
#include "../trait/is_ptr.hpp"

namespace xieite {
	template<typename T, xieite::is_ptr U>
	using same_const_data = xieite::set_const_data<U, xieite::is_const<T>>;
}
