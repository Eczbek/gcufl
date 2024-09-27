export module xieite:types.List;

import std;
import :concepts.SatisfiedBy;
import :concepts.SatisfiedByAll;
import :concepts.SatisfiedByAny;
import :functors.Visitor;
import :types.Value;

namespace {
	constexpr auto defaultComparator = []<typename Type, std::same_as<Type>> {};
}

export namespace xieite::types {
	template<typename... Types>
	struct List {
	public:
		static constexpr std::size_t size = sizeof...(Types);

		template<auto condition>
		static constexpr bool all = xieite::concepts::SatisfiedByAll<condition, Types...>;

		template<auto condition>
		static constexpr bool any = xieite::concepts::SatisfiedByAny<condition, Types...>;

		template<typename Type, auto comparator = defaultComparator>
		static constexpr bool has = (... || xieite::concepts::SatisfiedBy<comparator, Type, Types>);

		template<auto selector>
		requires(List::any<selector>)
		static constexpr std::size_t find = ([] {
			std::size_t index = 0;
			(... && (!xieite::concepts::SatisfiedBy<selector, Types> && ++index));
			return index;
		})();

		template<typename Type, auto comparator = defaultComparator>
		requires(List::has<Type, comparator>)
		static constexpr std::size_t get = List::find<[]<typename OtherType> requires(xieite::concepts::SatisfiedBy<comparator, Type, OtherType>) {}>;

		template<std::size_t index>
		requires(index < sizeof...(Types))
		using At = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return xieite::functors::Visitor([](const xieite::types::Value<i>) {
				return std::type_identity<Types>();
			}...)(xieite::types::Value<index>());
		})(std::index_sequence_for<Types...>()))::type;

		static constexpr auto apply(auto callback) noexcept {
			return callback.template operator()<Types...>();
		}

		template<template<typename...> typename Template>
		using ApplyRange = Template<Types...>;

		template<typename Type>
		using Signature = decltype(([] {
			if constexpr ((... && !std::is_void_v<Types>)) {
				return std::type_identity_t<Type(Types...)>();
			} else {
				static_assert(false, "must not create function signature with void parameters");
			}
		})())::type;

		template<typename... OtherTypes>
		using Append = List<Types..., OtherTypes...>;

		template<typename Range>
		using AppendRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(Template<OtherTypes...>) {
			return std::type_identity<List::Append<OtherTypes...>>();
		})(std::declval<Range>()))::type;

		template<typename... OtherTypes>
		using Prepend = List<OtherTypes..., Types...>;

		template<typename Range>
		using PrependRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(Template<OtherTypes...>) {
			return std::type_identity<List::Prepend<OtherTypes...>>();
		})(std::declval<Range>()))::type;

		using Reverse = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<List<List::At<sizeof...(Types) - i - 1>...>>();
		})(std::index_sequence_for<Types...>()))::type;

		template<std::size_t start, std::size_t end = sizeof...(Types)>
		using Slice = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<List<List::At<i + std::min(start, end)>...>>();
		})(std::make_index_sequence<std::min(std::max(start, end), sizeof...(Types)) - std::min(std::min(start, end), sizeof...(Types))>()))::type;

		template<std::size_t start, std::size_t end = start + 1>
		using Erase = List::Slice<0, start>::template AppendRange<List::Slice<end>>;

		template<std::size_t start, std::size_t end, typename... OtherTypes>
		using Replace = List::Slice<0, start>::template Append<OtherTypes...>::template AppendRange<List::Slice<end>>;

		template<std::size_t start, std::size_t end, typename Range>
		using ReplaceRange = List::Slice<0, start>::template AppendRange<Range>::template AppendRange<List::Slice<end>>;

		template<std::size_t index, typename... OtherTypes>
		using Insert = List::Replace<index, index, OtherTypes...>;

		template<std::size_t index, typename Range>
		using InsertRange = List::ReplaceRange<index, index, Range>;

		template<std::size_t index, typename Type>
		using Set = List::Replace<index, index + 1, Type>;

		template<std::size_t index1, std::size_t index2>
		using Swap = List::Set<index1, List::At<index2>>::template Set<index2, List::At<index1>>;

		template<std::size_t start1, std::size_t end1, std::size_t start2, std::size_t end2>
		using SwapRanges = List::ReplaceRange<start1, end1, List::Slice<start2, end2>>::template ReplaceRange<start2, end2, List::Slice<start1, end1>>;

		template<std::size_t... indices>
		using Arrange = List<List::At<indices>...>;

	private:
		template<auto condition, auto transformer, typename... Results>
		struct TransformHelper
		: std::type_identity<List<Results...>> {
			template<typename Type>
			auto operator->*(std::type_identity<Type>) const noexcept {
				if constexpr (xieite::concepts::SatisfiedBy<condition, Type, Results...>) {
					return decltype(transformer.template operator()<Type, Results...>())::type::apply(([]<typename... Additions> {
						return TransformHelper<condition, transformer, Results..., Additions...>();
					}));
				} else {
					return TransformHelper<condition, transformer, Results...>();
				}
			}
		};

	public:
		template<auto selector>
		using Filter = decltype((List::TransformHelper<selector, []<typename Type> { return std::type_identity<Type>(); }>()->*...->*std::type_identity<Types>()))::type;

		template<auto comparator = []<typename First, typename... Rest> requires((... && !std::same_as<First, Rest>)) {}>
		using Deduplicate = List::Filter<comparator>;

		template<std::size_t repetitions>
		using Repeat = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return xieite::functors::Visitor([]<typename... Results>(this auto self, xieite::types::Value<i>) {
				return self.template operator()<Results..., Types...>(xieite::types::Value<i + 1>());
			}..., []<typename... Results>(xieite::types::Value<repetitions>) {
				return std::type_identity<List<Results...>>();
			})(xieite::types::Value<0uz>());
		})(std::make_index_sequence<repetitions>()))::type;

		template<std::size_t arity, auto transformer>
		requires(!(sizeof...(Types) % arity))
		using Transform = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<List<decltype(transformer.template operator()<List::Slice<arity * i, arity * (i + 1)>>())...>>();
		})(std::make_index_sequence<sizeof...(Types) / arity>()))::type;

		template<std::size_t arity, auto transformer>
		requires(!(sizeof...(Types) % arity))
		using TransformFlat = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<decltype((List::TransformHelper<[]<typename...> {}, []<typename Value> { return std::type_identity<List::Slice<arity * Value::value, arity * (Value::value + 1)>>(); }>()->*...->*std::type_identity<xieite::types::Value<i>>()))>();
		})(std::make_index_sequence<sizeof...(Types) / arity>()))::type;

		template<typename... OtherTypes>
		requires(sizeof...(Types) == sizeof...(OtherTypes))
		using Zip = decltype(([]<std::size_t... i>(std::index_sequence<i...>) {
			return std::type_identity<List<List<List::At<i>, OtherTypes>...>>();
		})(std::index_sequence_for<Types...>()))::type;

		template<typename Range>
		using ZipRange = decltype(([]<template<typename...> typename Template, typename... OtherTypes>(Template<OtherTypes...>) {
			return std::type_identity<List::Zip<OtherTypes...>>();
		})(std::declval<Range>()))::type;
	};
}

// Thanks to Eisenwave (https://github.com/Eisenwave) for the filtering algorithm, and eightfold (https://github.com/8ightfold) for helping compact the slicer
