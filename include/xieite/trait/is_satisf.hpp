#pragma once

#include "../trait/is_satisfd.hpp"

namespace xieite {
	template<typename T, auto fn>
	concept is_satisf = xieite::is_satisfd<fn, T>;
}
