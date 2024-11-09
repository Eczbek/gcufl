#pragma once

#include <cstddef>
#include <type_traits>

namespace xieite {
	template<template<typename> typename Ctnr, typename V, std::size_t rank>
	using dyn_md_ctnr = decltype(([]<std::size_t rest>(this auto self) {
		if constexpr (rest) {
			return std::type_identity<Ctnr<typename decltype(self.template operator()<rest - 1>())::type>>();
		} else {
			return std::type_identity<V>();
		}
	}).template operator()<rank>())::type;
}
