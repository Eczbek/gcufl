#pragma once

#include <type_traits>
#include "../ctnr/maybe_copy_assign.hpp"
#include "../ctnr/maybe_move_assign.hpp"
#include "../math/pow.hpp"
#include "../meta/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	struct exp {
	private:
		struct inter : xieite::maybe_copy_assign<false>, xieite::maybe_move_assign<false> {
		public:
			explicit constexpr inter(T value) noexcept
			: value(value) {}

			template<xieite::is_arith U>
			[[nodiscard]] friend constexpr std::common_type_t<T, U> operator*(U base, xieite::exp<T>::inter inter) noexcept {
				return static_cast<std::common_type_t<T, U>>(xieite::pow(base, inter.value));
			}

		private:
			T value;
		};

	public:
		explicit constexpr exp(T value) noexcept
		: value(value) {}

		template<xieite::is_arith U>
		[[nodiscard]] explicit(false) constexpr operator std::common_type_t<T, U>() const noexcept {
			return static_cast<std::common_type_t<T, U>>(this->value);
		}

		[[nodiscard]] constexpr xieite::exp<T>::inter operator*() const noexcept {
			return xieite::exp<T>::inter(this->value);
		}

	private:
		T value;
	};

	template<typename T>
	exp(T) -> exp<T>;
}