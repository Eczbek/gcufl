#pragma once

#include "../meta/set_volat_data.hpp"
#include "../trait/is_ptr.hpp"
#include "../trait/is_volat.hpp"

namespace xieite {
	template<typename T, xieite::is_ptr U>
	using same_volat_data = xieite::set_volat<U, xieite::is_volat<T>>;
}
