#pragma once

#include <concepts>
#include <functional>
#include "../meta/is_duration.hpp"
#include "../pp/fwd.hpp"
#include "../sys/thread_interval.hpp"

namespace xieite {
	struct thread_timeout {
	public:
		template<std::invocable<> F, xieite::is_duration Duration>
		thread_timeout(F&& callback, Duration duration) noexcept
		: interval([this, &callback] -> void {
			this->stop();
			std::invoke(XIEITE_FWD(callback));
		}, duration) {}

		[[nodiscard]] explicit operator bool() const noexcept {
			return static_cast<bool>(this->interval);
		}

		void stop() noexcept {
			this->interval.stop();
		}

	private:
		xieite::thread_interval interval;
	};
}
