#pragma once

#include "../meta/is_satisfied_by.hpp"

namespace xieite {
	template<typename T, auto fn>
	concept is_satisfies = xieite::is_satisfied_by<fn, T>;
}
