#pragma once

#include "../meta/is_conv_from.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_conv_from_all = (... && xieite::is_conv_from<T, Us>);
}
