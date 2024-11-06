#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_ref = std::is_reference_v<T>;
}
