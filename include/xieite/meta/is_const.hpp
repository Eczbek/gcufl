#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_const = std::is_const_v<std::remove_reference_t<T>>;
}
