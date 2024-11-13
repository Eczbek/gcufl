#pragma once

#include <concepts>
#include <ostream>

namespace xieite {
	template<typename T>
	concept is_streamable_out = requires(T value, std::ostream ostream) {
		{ ostream << value } -> std::convertible_to<std::ostream&>;
	};
}

// Thanks to fux for original code
