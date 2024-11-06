#pragma once

#include "../meta/is_const.hpp"
#include "../meta/maybe_const.hpp"

namespace xieite {
	template<typename T, typename U>
	using copy_const = xieite::maybe_const<U, xieite::is_const<T>>;
}
