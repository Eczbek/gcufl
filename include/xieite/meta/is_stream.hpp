#pragma once

#include "../meta/is_istream.hpp"
#include "../meta/is_ostream.hpp"

namespace xieite {
	template<typename T>
	concept is_stream = xieite::is_istream<T> || xieite::is_ostream<T>;
}
