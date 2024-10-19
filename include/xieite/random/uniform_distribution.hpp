#pragma once

#include <concepts>
#include <random>
#include <type_traits>
#include "../concepts/arithmetic.hpp"

namespace xieite::random {
	template<xieite::concepts::Arithmetic Arithmetic>
	using UniformDistribution = std::conditional_t<std::floating_point<Arithmetic>, std::uniform_real_distribution<Arithmetic>, std::conditional_t<std::same_as<Arithmetic, bool>, std::bernoulli_distribution, std::uniform_int_distribution<Arithmetic>>>;
}

