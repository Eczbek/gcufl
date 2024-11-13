#pragma once

#include "../meta/set_const.hpp"
#include "../trait/is_const.hpp"

namespace xieite {
	template<typename T, typename U>
	using same_const = xieite::set_const<U, xieite::is_const<T>>;
}
