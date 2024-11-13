#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_virt_dtor = std::has_virtual_destructor_v<T>;
}
