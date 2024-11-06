#pragma once

#include "../meta/is_volatile.hpp"
#include "../meta/maybe_volatile.hpp"

namespace xieite {
	template<typename T, typename U>
	using copy_volatile = xieite::maybe_volatile<U, xieite::is_volatile<T>>;
}
