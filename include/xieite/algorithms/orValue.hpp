#ifndef XIEITE_HEADER_ALGORITHMS_ORVALUE
#	define XIEITE_HEADER_ALGORITHMS_ORVALUE

#	include <concepts>

namespace xieite::algorithms {
	template<std::convertible_to<bool> Value>
	constexpr Value& orValue(Value& value1, Value& value2)
	noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>)) {
		return (static_cast<bool>(value1) ? value1 : value2);
	}

	template<std::convertible_to<bool> Value>
	constexpr const Value& orValue(const Value& value1, const Value& value2)
	noexcept(noexcept(std::is_nothrow_convertible_v<Value, bool>)) {
		return (static_cast<bool>(value1) ? value1 : value2);
	}
}

#endif
