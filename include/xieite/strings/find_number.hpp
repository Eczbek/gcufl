#pragma once

#include <concepts>
#include <cstddef>
#include <string_view>
#include <type_traits>
#include "../concepts/arithmetic.hpp"
#include "../math/absolute.hpp"
#include "../math/signed_size.hpp"
#include "../strings/number_components.hpp"

namespace xieite::strings {
	template<xieite::concepts::Arithmetic Arithmetic>
	[[nodiscard]] constexpr std::string_view findNumber(const std::string_view value, const std::conditional_t<std::floating_point<Arithmetic>, xieite::math::SignedSize, Arithmetic> radix = 10, const xieite::strings::NumberComponents components = xieite::strings::NumberComponents()) noexcept {
		const std::size_t valueSize = value.size();
		const std::string_view digits = components.digits.substr(0, xieite::math::absolute(radix));
		std::size_t i = 0;
		while ((i < valueSize) && !digits.contains(value[i]) && !((i < (valueSize - 1)) && (components.negatives.contains(value[i]) || components.positives.contains(value[i])) && digits.contains(value[i + 1]))) {
			++i;
		}
		if (i >= valueSize) {
			return "";
		}
		const std::size_t start = i;
		i += components.negatives.contains(value[i]) || components.positives.contains(value[i]);
		if constexpr (std::floating_point<Arithmetic>) {
			bool point = false;
			for (; i < valueSize; ++i) {
				if (digits.contains(value[i])) {
					continue;
				}
				if (components.points.contains(value[i])) {
					if (!point) {
						point = true;
						continue;
					}
				} else if ((i < (valueSize - 1)) && components.exponents.contains(value[i])) {
					return value.substr(start, i - start + xieite::strings::findNumber<int>(value.substr(i + 1)).size() + 1);
				}
				break;
			}
		} else {
			while ((i < valueSize) && digits.contains(value[i])) {
				++i;
			}
		}
		return value.substr(start, i - start);
	}
}
