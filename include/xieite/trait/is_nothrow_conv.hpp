#pragma once

#include <type_traits>
#include <utility>

namespace xieite {
	template<typename T, typename U>
	concept is_nothrow_conv = std::is_nothrow_convertible_v<T, U> && requires { static_cast<U>(std::declval<T>()); };
}
