#pragma once

#include "../meta/is_const.hpp"
#include "../meta/set_const.hpp"

namespace xieite {
	template<typename T, typename U>
	using same_const = xieite::set_const<U, xieite::is_const<T>>;
}
