#pragma once

#include "../meta/is_satisfd.hpp"

namespace xieite {
	template<auto fn, typename... Ts>
	concept is_dsatisfd = !xieite::is_satisfd<fn, Ts...>;
}
