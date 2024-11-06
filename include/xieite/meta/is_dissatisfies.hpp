#pragma once

#include "../meta/is_satisfies.hpp"

namespace xieite {
	template<typename T, auto fn>
	concept is_dissatisfies = !xieite::is_satisfies<T, fn>;
}
