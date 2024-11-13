#pragma once

#include <concepts>
#include <istream>

namespace xieite {
	template<typename T>
	concept is_streamable_in = requires(T value, std::istream istream) {
		{ istream >> value } -> std::convertible_to<std::istream&>;
	};
}
