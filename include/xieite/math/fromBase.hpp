#pragma once
#include <array> // std::array
#include <concepts> // std::integral
#include <cstddef> // std::size_t
#include <limits> // std::numeric_limits
#include <string_view> // std::string_view

namespace xieite::math {
	template<std::integral N = int, std::integral O>
	[[nodiscard]]
	constexpr N fromBase(const std::string_view value, const O base, const std::string_view digits = "0123456789abcdefghijklmnopqrstuvwxyz") noexcept {
		const char min = std::numeric_limits<char>::min();
		std::array<std::size_t, std::numeric_limits<char>::max() - min> characterMap;
		const std::size_t digitsSize = digits.size();
		for (std::size_t i = 0; i < digitsSize; ++i)
			characterMap[digits[i] - min] = i;
		N result = 0;
		N power = 1;
		for (std::size_t i = value.size(); i--;) {
			result += characterMap[value[i] - min] * power;
			power *= base;
		}
		return result;
	}
}
