#pragma once

#include "../meta/set_volat.hpp"
#include "../trait/is_volat.hpp"

namespace xieite {
	template<typename T, typename U>
	using same_volat = xieite::set_volat<U, xieite::is_volat<T>>;
}
