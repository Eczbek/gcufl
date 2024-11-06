#pragma once

#include <type_traits>

namespace xieite {
	template<auto value_>
	using value = std::integral_constant<decltype(value_), value_>;
}
