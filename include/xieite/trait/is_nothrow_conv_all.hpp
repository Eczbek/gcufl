#pragma once

#include "../trait/is_nothrow_conv.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_conv_all = (... && xieite::is_nothrow_conv<T, Us>);
}
