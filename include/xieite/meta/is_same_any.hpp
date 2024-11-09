#pragma once

#include <concepts>

namespace xieite {
	template<typename T, typename... Us>
	concept is_same_any = (... || std::same_as<T, Us>);
}
