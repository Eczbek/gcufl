#pragma once

#include "../meta/is_const.hpp"
#include "../meta/is_ptr.hpp"
#include "../meta/set_const_data.hpp"

namespace xieite {
	template<typename T, xieite::is_ptr U>
	using same_const_data = xieite::set_const_data<U, xieite::is_const<T>>;
}
