#pragma once

#include "../meta/is_rm_cvref_same.hpp"

namespace xieite {
	template<typename T, typename... Us>
	concept is_rm_cvref_same_any = (... && xieite::is_rm_cvref_same<T, Us>);
}
