#ifndef XIEITE_HEADER_RANDOM_UNIFORM_INTERRUPTABLE_DISTRIBUTION
#	define XIEITE_HEADER_RANDOM_UNIFORM_INTERRUPTABLE_DISTRIBUTION

#	include <algorithm>
#	include <concepts>
#	include <iterator>
#	include <random>
#	include <stdexcept>
#	include "../concepts/numeric.hpp"
#	include "../concepts/range_of.hpp"
#	include "../concepts/uniform_random_bit_generator.hpp"
#	include "../math/interval.hpp"
#	include "../math/difference.hpp"
#	include "../math/merge_intervals.hpp"
#	include "../random/uniform_distribution.hpp"

namespace xieite::random {
	template<xieite::concepts::Numeric Number>
	class UniformInterruptableDistribution {
	public:
		template<xieite::concepts::RangeOf<xieite::math::Interval<Number>> IntervalRange>
		UniformInterruptableDistribution(const xieite::math::Interval<Number> interval, const IntervalRange& interruptions) {
			const Number minimum = std::min(interval.start, interval.end);
			const Number maximum = std::max(interval.start, interval.end);
			Number upper = maximum;
			for (const xieite::math::Interval<Number> interruption : xieite::math::mergeIntervals<Number>(interruptions)) {
				if (((interruption.start >= minimum) || (interruption.end >= minimum)) && ((interruption.start <= maximum) || (interruption.end <= maximum))) {
					const Number start = std::clamp(interruption.start, minimum, maximum);
					const Number end = std::clamp(interruption.end, minimum, maximum);
					const Number difference = xieite::math::difference(start, end);
					if (upper <= minimum + difference) {
						throw std::range_error("Cannot exclude entire interval");
					}
					upper -= difference + std::integral<Number>;
					this->interruptions.push_back(xieite::math::Interval<Number>(std::min(start, end), difference));
				}
			}
			this->distribution = xieite::random::UniformDistribution<Number>(minimum, upper);
			std::ranges::sort(this->interruptions.begin(), this->interruptions.end(), [](const xieite::math::Interval<Number> interruption1, const xieite::math::Interval<Number> interruption2) {
				return interruption1.start < interruption2.start;
			});
		}

		template<xieite::concepts::UniformRandomBitGenerator UniformRandomBitGenerator>
		[[nodiscard]] Number operator()(UniformRandomBitGenerator& generator) const noexcept {
			Number result = this->distribution(generator);
			for (const xieite::math::Interval<Number> interruption : this->interruptions) {
				if (result >= interruption.start) {
					result += (interruption.end + std::integral<Number>);
				}
			}
			return result;
		}

	private:
		mutable xieite::random::UniformDistribution<Number> distribution;
		std::vector<xieite::math::Interval<Number>> interruptions;
	};
}

#endif
