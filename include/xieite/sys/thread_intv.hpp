#pragma once

#include <concepts>
#include <functional>
#include <thread>
#include "../meta/is_dur.hpp"
#include "../sys/thread_loop.hpp"

namespace xieite {
	struct thread_intv {
	public:
		template<std::invocable<> F, xieite::is_dur Dur>
		thread_intv(F&& fn, Dur dur) noexcept
		: loop([&fn, dur] -> void {
			static bool first = true;
			if (first) {
				first = false;
			} else {
				std::invoke(fn);
			}
			std::this_thread::sleep_for(dur);
		}) {}

		[[nodiscard]] explicit operator bool() const noexcept {
			return static_cast<bool>(this->loop);
		}

		void stop() noexcept {
			this->loop.stop();
		}

	private:
		xieite::thread_loop loop;
	};
}
