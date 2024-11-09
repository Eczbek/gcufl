#pragma once

#include "../meta/is_volat.hpp"
#include "../meta/set_volat.hpp"

namespace xieite {
	template<typename T, typename U>
	using same_volat = xieite::set_volat<U, xieite::is_volat<T>>;
}
