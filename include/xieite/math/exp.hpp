#pragma once

#include <type_traits>
#include "../ctnr/set_cp_assign.hpp"
#include "../ctnr/set_mv_assign.hpp"
#include "../math/pow.hpp"
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	struct exp {
	private:
		struct proxy : xieite::set_cp_assign<false>, xieite::set_mv_assign<false> {
		public:
			[[nodiscard]] explicit constexpr proxy(T value) noexcept
			: value(value) {}

			template<xieite::is_arith U>
			[[nodiscard]] friend constexpr std::common_type_t<T, U> operator*(U base, xieite::exp<T>::proxy proxy) noexcept {
				return static_cast<std::common_type_t<T, U>>(xieite::pow(base, proxy.value));
			}

		private:
			T value;
		};

	public:
		[[nodiscard]] explicit constexpr exp(T value) noexcept
		: value(value) {}

		template<xieite::is_arith U>
		[[nodiscard]] constexpr operator std::common_type_t<T, U>() const noexcept {
			return static_cast<std::common_type_t<T, U>>(this->value);
		}

		[[nodiscard]] constexpr xieite::exp<T>::proxy operator*() const noexcept {
			return xieite::exp<T>::proxy(this->value);
		}

	private:
		T value;
	};

	template<typename T>
	exp(T) -> exp<T>;
}
