#pragma once

#include <type_traits>
#include "../meta/is_same_as_any.hpp"
#include "../meta/is_wide_char.hpp"

namespace xieite {
	template<typename T>
	concept is_char = xieite::is_wide_char<T> || xieite::is_same_as_any<std::remove_cv_t<T>, char, char8_t>;
}

// https://eel.is/c++draft/basic.fundamental#11
