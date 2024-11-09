#pragma once

#include <concepts>
#include <cstddef>
#include <initializer_list>
#include <tuple>
#include <utility>
#include "../fn/unroll.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<template<typename> typename, typename>
	struct tuple_set;

	template<template<typename> typename Ctnr, typename K, typename... Ks>
	struct tuple_set<Ctnr, std::tuple<K, Ks...>> {
	public:
		constexpr tuple_set(std::initializer_list<std::pair<K, xieite::tuple_set<Ctnr, std::tuple<Ks...>>>> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto operator[](KsRef&& keys) const
		XIEITE_ARROW(this->has(XIEITE_FWD(keys)))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		constexpr auto insert(KsRef&& keys)
		XIEITE_ARROW(xieite::unroll<Ks...>(
			[this, &keys]<std::size_t... i>
			XIEITE_ARROW(this->set[std::get<0>(keys)].insert(std::make_tuple(std::get<i + 1>(keys)...)))
		))

		template<std::convertible_to<std::tuple<K, Ks...>> KsRef>
		[[nodiscard]] constexpr auto has(KsRef&& keys) const
		XIEITE_ARROW(
			this->set.has(std::get<0>(keys))
			&& xieite::unroll<Ks...>(
				[this, &keys]<std::size_t... i>
				XIEITE_ARROW(this->set.at(std::get<0>(keys)).has(std::make_tuple(std::get<i + 1>(keys)...)))
			)
		)

	private:
		Ctnr<xieite::tuple_set<Ctnr, std::tuple<Ks...>>> set;
	};

	template<template<typename> typename Ctnr, typename Key>
	struct tuple_set<Ctnr, std::tuple<Key>> {
	public:
		constexpr tuple_set(std::initializer_list<Key> list = {}) noexcept
		: set(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto operator[](KRef&& key) const
		XIEITE_ARROW(this->has(XIEITE_FWD(key)))

		template<std::convertible_to<std::tuple<Key>> KRef>
		constexpr auto insert(KRef&& key)
		XIEITE_ARROW(this->set.emplace(std::get<0>(XIEITE_FWD(key))))

		template<std::convertible_to<std::tuple<Key>> KRef>
		[[nodiscard]] constexpr auto has(KRef&& key) const
		XIEITE_ARROW(this->set.contains(std::get<0>(XIEITE_FWD(key))))

	private:
		Ctnr<Key> set;
	};
}
