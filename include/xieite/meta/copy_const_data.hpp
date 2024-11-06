#pragma once

#include "../meta/is_const.hpp"
#include "../meta/is_ptr.hpp"
#include "../meta/maybe_const_data.hpp"

namespace xieite {
	template<typename T, xieite::is_ptr U>
	using copy_const_data = xieite::maybe_const_data<U, xieite::is_const<T>>;
}
