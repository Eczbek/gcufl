#pragma once

#include "../meta/is_ptr.hpp"
#include "../meta/is_volat.hpp"
#include "../meta/set_volat_data.hpp"

namespace xieite {
	template<typename T, xieite::is_ptr U>
	using same_volat_data = xieite::set_volat<U, xieite::is_volat<T>>;
}
