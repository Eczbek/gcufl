#ifndef XIEITE_HEADER__THREADS__TIMEOUT
#	define XIEITE_HEADER__THREADS__TIMEOUT

#	include <concepts>
#	include "../concepts/ChronoDuration.hpp"
#	include "../threads/Interval.hpp"

namespace xieite::threads {
	class Timeout {
	public:
		template<std::invocable<> Invocable, xieite::concepts::ChronoDuration ChronoDuration>
		Timeout(const Invocable& callback, const ChronoDuration duration) noexcept
		: interval([this, &callback] {
			this->stop();
			callback();
		}, duration) {}

		bool good() const noexcept {
			return this->interval.good();
		}

		void stop() noexcept {
			this->interval.stop();
		}

	private:
		xieite::threads::Interval interval;
	};
}

#endif
