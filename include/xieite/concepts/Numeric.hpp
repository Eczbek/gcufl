#ifndef XIEITE_HEADER__CONCEPTS__NUMERIC
#	define XIEITE_HEADER__CONCEPTS__NUMERIC

#	include <concepts>
#	include "../concepts/Arithmetic.hpp"

namespace xieite::concepts {
	template<typename Type>
	concept Numeric = !std::same_as<Type, bool> && xieite::concepts::Arithmetic<Type>;
}

#endif
