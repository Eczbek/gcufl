#pragma once

#include "../meta/is_rm_cvref_same_as.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_rm_cvref_same_as_all = (... && xieite::is_rm_cvref_same_as<T, Us>);
}
