#pragma once

#include "../meta/is_ptr.hpp"
#include "../meta/is_volatile.hpp"
#include "../meta/maybe_volatile_data.hpp"

namespace xieite {
	template<typename T, xieite::is_ptr U>
	using copy_volatile_data = xieite::maybe_volatile<U, xieite::is_volatile<T>>;
}
