#pragma once

#include <string_view>
#include "../containers/make_array.hpp"
#include "../preprocessor/compiler.hpp"
#include "../preprocessor/function_signature.hpp"
#include "../strings/after.hpp"
#include "../strings/between.hpp"

namespace XIEITE_DETAIL {
	[[nodiscard]] consteval std::string_view getTypeName(const std::string_view signature) noexcept {
#if XIEITE_COMPILER_TYPE_GCC
		return xieite::strings::between(signature, "= ", ';');
#elif XIEITE_COMPILER_TYPE_CLANG
		return xieite::strings::between(signature, "= ", ']');
#elif XIEITE_COMPILER_TYPE_WINDOWS
		return xieite::strings::between(xieite::strings::after(signature, " __"), '<', ">(");
#endif
	}
}

export namespace xieite::types {
	template<typename Type>
	[[nodiscard]] consteval std::string_view name() noexcept {
		static constexpr auto data = xieite::containers::makeArray<char, XIEITE_DETAIL::getTypeName(XIEITE_FUNCTION_SIGNATURE).size()>(XIEITE_DETAIL::getTypeName(XIEITE_FUNCTION_SIGNATURE));
		return std::string_view(data.begin(), data.end());
	}

	template<auto value>
	[[nodiscard]] consteval std::string_view name() noexcept {
		static constexpr auto data = xieite::containers::makeArray<char, XIEITE_DETAIL::getTypeName(XIEITE_FUNCTION_SIGNATURE).size()>(XIEITE_DETAIL::getTypeName(XIEITE_FUNCTION_SIGNATURE));
		return std::string_view(data.begin(), data.end());
	}
}
