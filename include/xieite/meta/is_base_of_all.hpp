#pragma once

#include "../meta/is_base_of.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_base_of_all = (... && xieite::is_base_of<T, Us>);
}
