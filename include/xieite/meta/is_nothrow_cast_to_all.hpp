#pragma once

#include "../meta/is_nothrow_cast_to.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_cast_to_all = (... && xieite::is_nothrow_cast_to<T, Us>);
}
