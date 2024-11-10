#pragma once

#include <algorithm>
#include <concepts>
#include <functional>
#include <stdexcept>
#include <ranges>
#include <vector>
#include "../math/betw.hpp"
#include "../math/diff.hpp"
#include "../math/intv.hpp"
#include "../math/limits.hpp"
#include "../math/merge_intv.hpp"
#include "../math/uniform_distr.hpp"
#include "../meta/is_arith.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<xieite::is_arith T>
	struct uniform_interrupt_distr {
	public:
		template<std::ranges::input_range R>
		requires(std::convertible_to<std::ranges::range_value_t<R>, xieite::intv<T>>)
		uniform_interrupt_distr(xieite::intv<T> intv, R&& interrupts) {
			const auto [min, max] = xieite::limits(intv.start, intv.end);
			T upper = max;
			for (auto [start, end] : xieite::merge_intv(XIEITE_FWD(interrupts))) {
				if (!xieite::betw(start, min, max) || !xieite::betw(end, min, max)) {
					continue;
				}
				start = std::clamp(start, min, max);
				end = std::clamp(end, min, max);
				const auto diff = static_cast<T>(xieite::diff(start, end));
				if (upper <= (min + diff)) {
					throw std::out_of_range("must not exclude entire intv");
				}
				upper -= diff + std::integral<T>;
				this->interrupts.push_back(xieite::intv<T>(std::min(start, end), diff));
			}
			this->distr = xieite::uniform_distr<T>(min, upper);
			std::ranges::sort(this->interrupts, std::ranges::less(), &xieite::intv<T>::start);
		}

		template<std::uniform_random_bit_generator G>
		[[nodiscard]] T operator()(G& gen) noexcept {
			T result = this->distr(gen);
			for (auto [start, end] : this->interrupts) {
				if (result >= start) {
					result += end + std::integral<T>;
				}
			}
			return result;
		}

	private:
		xieite::uniform_distr<T> distr;
		std::vector<xieite::intv<T>> interrupts;
	};
}
