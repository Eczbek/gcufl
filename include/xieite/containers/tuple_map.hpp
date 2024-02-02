#ifndef XIEITE_HEADER_CONTAINERS_TUPLE_MAP
#	define XIEITE_HEADER_CONTAINERS_TUPLE_MAP

#	include <concepts>
#	include <cstddef>
#	include <initializer_list>
#	include <tuple>
#	include <utility>

namespace xieite::containers {
	template<template<typename, typename> typename, typename, typename>
	struct TupleMap;

	template<template<typename, typename> typename Container, typename Value, typename FirstKey, typename... RestKeys>
	class TupleMap<Container, std::tuple<FirstKey, RestKeys...>, Value> {
	public:
		constexpr TupleMap(const std::initializer_list<std::pair<FirstKey, TupleMap<Container, std::tuple<RestKeys...>, Value>>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		[[nodiscard]] constexpr const Value& operator[](const std::tuple<FirstKey, RestKeys...>& keys) const noexcept {
			return ([this, &keys]<std::size_t... indices>(std::index_sequence<indices...>) -> const Value& {
				return this->map.at(std::get<0>(keys))[std::make_tuple(std::get<indices + 1>(keys)...)];
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

		[[nodiscard]] constexpr Value& operator[](const std::tuple<FirstKey, RestKeys...>& keys) noexcept {
			return ([this, &keys]<std::size_t... indices>(std::index_sequence<indices...>) -> Value& {
				return this->map.at(std::get<0>(keys))[std::make_tuple(std::get<indices + 1>(keys)...)];
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

		template<std::convertible_to<Value> ValueReference>
		constexpr void insert(const std::tuple<FirstKey, RestKeys...>& keys, ValueReference&& value) noexcept {
			return ([this, &keys, &value]<std::size_t... indices>(std::index_sequence<indices...>) {
				this->map[std::get<0>(keys)].insert(std::make_tuple(std::get<indices + 1>(keys)...), std::forward<ValueReference>(value));
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

		[[nodiscard]] constexpr bool contains(const std::tuple<FirstKey, RestKeys...>& keys) const noexcept {
			return this->map.contains(std::get<0>(keys)) && ([this, &keys]<std::size_t... indices>(std::index_sequence<indices...>) {
				return this->map.at(std::get<0>(keys)).contains(std::make_tuple(std::get<indices + 1>(keys)...));
			})(std::make_index_sequence<sizeof...(RestKeys)>());
		}

	private:
		Container<FirstKey, TupleMap<Container, std::tuple<RestKeys...>, Value>> map;
	};

	template<template<typename, typename> typename Container, typename Value, typename Key>
	class TupleMap<Container, std::tuple<Key>, Value> {
	public:
		constexpr TupleMap(const std::initializer_list<std::pair<Key, Value>> list = {}) noexcept
		: map(list.begin(), list.end()) {}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr const Value& operator[](KeyReference&& key) const noexcept {
			return this->map.at(std::get<0>(std::forward<KeyReference>(key)));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr Value& operator[](KeyReference&& key) noexcept {
			return this->map.at(std::get<0>(std::forward<KeyReference>(key)));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference, std::convertible_to<Value> ValueReference>
		constexpr void insert(KeyReference&& key, ValueReference&& value) noexcept {
			this->map.emplace(std::make_pair(std::get<0>(std::forward<KeyReference>(key)), std::forward<ValueReference>(value)));
		}

		template<std::convertible_to<std::tuple<Key>> KeyReference>
		[[nodiscard]] constexpr bool contains(KeyReference&& key) const noexcept {
			return this->map.contains(std::get<0>(std::forward<KeyReference>(key)));
		}

	private:
		Container<Key, Value> map;
	};
}

#endif
