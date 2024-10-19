#pragma once

#include <cstddef>
#include "../functors/counter.hpp"

namespace XIEITE_DETAIL {
	using TypeIdentifierCounter = xieite::functors::Counter<>;
}

namespace xieite::types {
	template<typename>
	constexpr std::size_t identifier = XIEITE_DETAIL::TypeIdentifierCounter::advance();
}
