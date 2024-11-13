#pragma once

#include <type_traits>
#include "../trait/is_same_any.hpp"

namespace xieite {
	template<typename T>
	concept is_wide_ch = xieite::is_same_any<std::remove_cv_t<T>, wchar_t, char16_t, char32_t>;
}

// https://eel.is/c++draft/basic.fundamental#8
