#pragma once

#include <type_traits>

namespace xieite {
	template<typename T>
	concept is_rvalue_ref = std::is_rvalue_reference_v<T>;
}
