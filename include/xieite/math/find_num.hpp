#pragma once

#include <concepts>
#include <cstddef>
#include <string_view>
#include <type_traits>
#include "../ctnr/str_num_cfg.hpp"
#include "../math/abs.hpp"
#include "../math/ssize_t.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	[[nodiscard]] constexpr std::string_view find_num(std::string_view str, std::conditional_t<std::floating_point<T>, xieite::ssize_t, T> radix = 10, xieite::str_num_cfg cfg = {}) noexcept {
		const std::size_t size = str.size();
		const std::string_view digits = cfg.digits.substr(0, xieite::abs(radix));
		std::size_t i = 0;
		while ((i < size) && !digits.contains(str[i]) && !((i < (size - 1)) && (cfg.neg.contains(str[i]) || cfg.pos.contains(str[i])) && digits.contains(str[i + 1]))) {
			++i;
		}
		if (i >= size) {
			return "";
		}
		const std::size_t start = i;
		i += cfg.neg.contains(str[i]) || cfg.pos.contains(str[i]);
		if constexpr (std::floating_point<T>) {
			bool point = false;
			for (; i < size; ++i) {
				if (digits.contains(str[i])) {
					continue;
				}
				if (cfg.pts.contains(str[i])) {
					if (!point) {
						point = true;
						continue;
					}
				} else if ((i < (size - 1)) && cfg.exp.contains(str[i])) {
					return str.substr(start, i - start + xieite::find_num<int>(str.substr(i + 1)).size() + 1);
				}
				break;
			}
		} else {
			while ((i < size) && digits.contains(str[i])) {
				++i;
			}
		}
		return str.substr(start, i - start);
	}
}
