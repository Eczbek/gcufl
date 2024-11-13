#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_ptr = std::is_pointer_v<std::remove_reference_t<T>>;
}
