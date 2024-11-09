#pragma once

#include "../meta/is_base.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_base_all = (... && xieite::is_base<T, Us>);
}
