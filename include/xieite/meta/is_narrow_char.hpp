#pragma once

#include <concepts>
#include <type_traits>
#include "../meta/is_ordinary_char.hpp"

namespace xieite {
	template<typename T>
	concept is_narrow_char = xieite::is_ordinary_char<T> || std::same_as<std::remove_cv_t<T>, char8_t>;
}

// https://eel.is/c++draft/basic.fundamental#7
