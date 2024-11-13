#pragma once

#include "../trait/is_nothrow_conv.hpp"

namespace xieite {
	template<typename T, typename U>
	concept is_nothrow_conv_from = xieite::is_nothrow_conv<U, T>;
}
