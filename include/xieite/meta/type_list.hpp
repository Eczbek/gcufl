#pragma once

#include <algorithm>
#include <concepts>
#include <cstddef>
#include <type_traits>
#include "../fn/unroll.hpp"
#include "../fn/visitor.hpp"
#include "../math/diff.hpp"
#include "../meta/fold.hpp"
#include "../meta/is_satisfied_by.hpp"
#include "../meta/is_satisfied_by_all.hpp"
#include "../meta/is_satisfied_by_any.hpp"
#include "../meta/is_satisfies.hpp"
#include "../meta/value.hpp"
#include "../pp/arrow.hpp"
#include "../pp/fwd.hpp"

namespace xieite {
	template<typename... Ts>
	struct type_list {
		static constexpr std::size_t size = sizeof...(Ts);

		template<auto cond>
		static constexpr bool all = xieite::is_satisfied_by_all<cond, Ts...>;

		template<auto cond>
		static constexpr bool any = xieite::is_satisfied_by_any<cond, Ts...>;

		template<typename T, auto comp = []<typename U, std::same_as<U>> {}>
		static constexpr bool has = (... || xieite::is_satisfied_by<comp, T, Ts>);

		template<auto fn>
		requires(xieite::type_list<Ts...>::any<fn>)
		static constexpr std::size_t find = ([] -> std::size_t {
			std::size_t idx = 0;
			(... && (!xieite::is_satisfied_by<fn, Ts> && ++idx));
			return idx;
		})();

		template<typename T, auto comp = []<typename U, std::same_as<U>> {}>
		requires(xieite::type_list<Ts...>::has<T, comp>)
		static constexpr std::size_t get =
			xieite::type_list<Ts...>
			::find<[]<typename U> requires(xieite::is_satisfied_by<comp, T, U>) {}>;

		template<std::size_t idx>
		using at = decltype(xieite::unroll<Ts...>([]<std::size_t... i> {
			return xieite::visitor(
				[](xieite::value<i>) {
					return std::type_identity<Ts>();
				}...
			)(xieite::value<idx>());
		}))::type;

		static constexpr auto apply(auto&& fn)
		XIEITE_ARROW(XIEITE_FWD(fn).template operator()<Ts...>())

		template<auto fn>
		static constexpr bool is_satisfies = xieite::is_satisfied_by<fn, Ts...>;

		template<template<typename...> typename M>
		using to = M<Ts...>;

		template<typename Ret>
		using as_fn = decltype(([] {
			if constexpr ((sizeof...(Ts) < 2) || (... && !std::is_void_v<Ts>)) {
				return std::type_identity<Ret(Ts...)>();
			} else {
				static_assert(false, "function signature must not have void parameters");
			}
		})())::type;

		template<typename... Us>
		using append = xieite::type_list<Ts..., Us...>;

		template<typename R>
		using append_range = decltype(
			([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) {
				return std::type_identity<xieite::type_list<Ts...>::append<Us...>>();
			})(std::type_identity<R>())
		)::type;

		template<typename... Us>
		using prepend = xieite::type_list<Us..., Ts...>;

		template<typename R>
		using prepend_range = decltype(
			([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) {
				return std::type_identity<xieite::type_list<Ts...>::prepend<Us...>>();
			})(std::type_identity<R>())
		)::type;

		using reverse = decltype(xieite::unroll<Ts...>([]<std::size_t... i> {
			return std::type_identity<xieite::type_list<xieite::type_list<Ts...>::at<sizeof...(Ts) - i - 1>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = sizeof...(Ts), auto = [] {}> // Lambda is a temporary workaround for GCC
		using slice = decltype(xieite::unroll<xieite::diff(start, end)>([]<std::size_t... i> {
			return std::type_identity<xieite::type_list<xieite::type_list<Ts...>::at<i + std::min(start, end)>...>>();
		}))::type;

		template<std::size_t start, std::size_t end = start + 1>
		using erase =
			xieite::type_list<Ts...>
			::slice<0, start>
			::template append_range<
				xieite::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t start, std::size_t end, typename... Us>
		using replace =
			xieite::type_list<Ts...>
			::slice<0, start>
			::template append<Us...>
			::template append_range<
				xieite::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t start, std::size_t end, typename R>
		using replace_range =
			xieite::type_list<Ts...>
			::slice<0, start>
			::template append_range<R>
			::template append_range<
				xieite::type_list<Ts...>
				::slice<end>
			>;

		template<std::size_t idx, typename... Us>
		using insert = xieite::type_list<Ts...>::replace<idx, idx, Us...>;

		template<std::size_t idx, typename R>
		using insert_range = xieite::type_list<Ts...>::replace_range<idx, idx, R>;

		template<std::size_t idx, typename T>
		using set = xieite::type_list<Ts...>::replace<idx, idx + 1, T>;

		template<std::size_t idx0, std::size_t idx1>
		using swap =
			xieite::type_list<Ts...>
			::set<idx0, xieite::type_list<Ts...>::at<idx1>>
			::template set<idx1, xieite::type_list<Ts...>::at<idx0>>;

		template<std::size_t start0, std::size_t end0, std::size_t start1, std::size_t end1>
		using swap_ranges =
			xieite::type_list<Ts...>
			::replace_range<start0, end0, type_list::slice<start1, end1>>
			::template replace_range<start1, end1, type_list::slice<start0, end0>>;

		template<std::size_t... indices>
		using arrange =
			xieite::type_list<
				xieite::type_list<Ts...>::at<indices>...
			>;

		template<auto cond>
		using filter =
			xieite::fold<
				[]<typename T, typename List> {
					return std::type_identity<std::conditional_t<xieite::is_satisfies<T, cond>, typename List::template append<T>, List>>();
				},
				xieite::type_list<>,
				Ts...
			>;

		template<auto comp = []<typename T, std::same_as<T>> {}>
		using deduplicate =
			xieite::fold<
				[]<typename T, typename List> {
					return std::type_identity<std::conditional_t<!xieite::type_list<Ts...>::has<T, comp>, typename List::template append<T>, List>>();
				},
				xieite::type_list<>,
				Ts...
			>;

		template<std::size_t n>
		using repeat = decltype(([]<std::size_t i = 0, typename... Us>(this auto self) {
			if constexpr (i < n) {
				return self.template operator()<i + 1, Us..., Ts...>();
			} else {
				return std::type_identity<xieite::type_list<Us...>>();
			}
		})())::type;

		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using transform = decltype(xieite::unroll<sizeof...(Ts) / arity>([]<std::size_t... i> {
			return std::type_identity<
				type_list<typename decltype(
					type_list::template slice<arity * i, arity * (i + 1)>
					::template append_range<type_list::template slice<0, arity * i>>
					::apply(fn)
				)::type...>
			>();
		}))::type;

		template<std::size_t arity, auto fn>
		requires(!(sizeof...(Ts) % arity))
		using transform_flat = decltype(xieite::unroll<sizeof...(Ts) / arity>([]<std::size_t... i> {
			return xieite::fold<
				[]<typename Index, typename> {
					return type_list
					::template slice<arity * Index::value, arity * (Index::value + 1)>
					::template append_range<type_list::template slice<0, arity * Index::value>>
					::apply(fn);
				},
				type_list<>,
				Ts...
			>();
		}))::type;

		template<typename... Us>
		requires(sizeof...(Ts) == sizeof...(Us))
		using zip = decltype(xieite::unroll<Ts...>([]<std::size_t... i> {
			return std::type_identity<type_list<type_list<type_list::at<i>, Us>...>>();
		}))::type;

		template<typename R>
		using zip_range = decltype(
			([]<template<typename...> typename M, typename... Us>(std::type_identity<M<Us...>>) {
				return std::type_identity<type_list::zip<Us...>>();
			})(std::type_identity<R>())
		)::type;
	};
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for the filtering algorithm, and eightfold (https://github.com/8ightfold) for helping compact the slicer
