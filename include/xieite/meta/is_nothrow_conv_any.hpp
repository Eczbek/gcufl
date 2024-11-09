#pragma once

#include "../meta/is_nothrow_conv.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_conv_any = (... || xieite::is_nothrow_conv<T, Us>);
}
