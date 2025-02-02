#pragma once

#include <utility>
#include "../trait/is_arith.hpp"

namespace xieite {
	template<xieite::is_arith T>
	struct vec2 {
		T x;
		T y;

		[[nodiscard]] vec2() = default;

		[[nodiscard]] constexpr vec2(T x, T y) noexcept
		: x(x), y(y) {}

		[[nodiscard]] constexpr xieite::vec2<T> operator+() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator+(xieite::vec2<T> l, xieite::vec2<T> r) noexcept {
			return xieite::vec2<T>(l.x + r.x, l.y + r.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator+(xieite::vec2<T> l, T r) noexcept {
			return l + xieite::vec2<T>(r, r);
		}

		constexpr xieite::vec2<T>& operator+=(xieite::vec2<T> r) noexcept {
			return *this = *this + r;
		}

		constexpr xieite::vec2<T>& operator+=(T r) noexcept {
			return *this = *this + r;
		}

		constexpr xieite::vec2<T>& operator++() noexcept {
			return *this += 1;
		}

		constexpr xieite::vec2<T> operator++(int) noexcept {
			return std::exchange(*this, *this + 1);
		}

		[[nodiscard]] constexpr xieite::vec2<T> operator-() const noexcept {
			return *this;
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator-(xieite::vec2<T> l, xieite::vec2<T> r) noexcept {
			return xieite::vec2<T>(l.x - r.x, l.y - r.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator-(xieite::vec2<T> l, T r) noexcept {
			return l - xieite::vec2<T>(r, r);
		}

		constexpr xieite::vec2<T>& operator-=(xieite::vec2<T> r) noexcept {
			return *this = *this - r;
		}

		constexpr xieite::vec2<T>& operator-=(T r) noexcept {
			return *this = *this - r;
		}

		constexpr xieite::vec2<T>& operator--() noexcept {
			return *this -= 1;
		}

		constexpr xieite::vec2<T> operator--(int) noexcept {
			return std::exchange(*this, *this - 1);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator*(xieite::vec2<T> l, xieite::vec2<T> r) noexcept {
			return xieite::vec2<T>(l.x * r.x, l.y * r.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator*(xieite::vec2<T> l, T r) noexcept {
			return l * xieite::vec2<T>(r, r);
		}

		constexpr xieite::vec2<T>& operator*=(xieite::vec2<T> r) noexcept {
			return *this = *this * r;
		}

		constexpr xieite::vec2<T>& operator*=(T r) noexcept {
			return *this = *this * r;
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator/(xieite::vec2<T> l, xieite::vec2<T> r) noexcept {
			return xieite::vec2<T>(l.x / r.x, l.y / r.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator/(xieite::vec2<T> l, T r) noexcept {
			return l / xieite::vec2<T>(r, r);
		}

		constexpr xieite::vec2<T>& operator/=(xieite::vec2<T> r) noexcept {
			return *this = *this / r;
		}

		constexpr xieite::vec2<T>& operator/=(T r) noexcept {
			return *this = *this / r;
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator%(xieite::vec2<T> l, xieite::vec2<T> r) noexcept {
			return xieite::vec2<T>(l.x % r.x, l.y % r.y);
		}

		[[nodiscard]] friend constexpr xieite::vec2<T> operator%(xieite::vec2<T> l, T r) noexcept {
			return l % xieite::vec2<T>(r, r);
		}

		constexpr xieite::vec2<T>& operator%=(xieite::vec2<T> r) noexcept {
			return *this = *this % r;
		}

		constexpr xieite::vec2<T>& operator%=(T r) noexcept {
			return *this = *this % r;
		}
	};

	template<typename T>
	vec2(T, T) -> vec2<T>;
}
