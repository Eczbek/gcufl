#pragma once

#include <type_traits>
#include "../meta/is_same_any.hpp"

namespace xieite {
	template<typename T>
	concept is_ordinary_ch = xieite::is_same_any<std::remove_cv_t<T>, char, signed char, unsigned char>;
}

// https://eel.is/c++draft/basic.fundamental#7
