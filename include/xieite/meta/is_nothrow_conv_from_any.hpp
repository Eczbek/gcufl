#pragma once

#include "../meta/is_nothrow_conv_from.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_nothrow_conv_from_any = (... && xieite::is_nothrow_conv_from<T, Us>);
}
