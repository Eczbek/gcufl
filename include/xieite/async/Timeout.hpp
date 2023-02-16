#pragma once
#include <atomic> // std::atomic
#include <concepts> // std::invocable
#include <memory> // std::make_shared, std::shared_ptr
#include <thread> // std::this_thread::sleep_for, std::thread
#include <utility> // std::forward
#include <xieite/concepts/TemporalDuration.hpp>

namespace xieite::async {
	class Timeout {
	private:
		std::shared_ptr<std::atomic<bool>> cancelled;
		std::thread thread;

	public:
		template<std::invocable<> C, xieite::concepts::TemporalDuration D>
		Timeout(C&& callback, const D duration) noexcept
		: cancelled(std::make_shared<std::atomic<bool>>(false)), thread([this, callback = std::forward<C>(callback), duration]() -> void {
			std::this_thread::sleep_for(duration);
			if (this)
				callback();
		}) {}

		inline ~Timeout() {
			if (thread.joinable())
				thread.detach();
		}

		inline operator bool() const noexcept {
			return !*cancelled;
		}

		inline void cancel() noexcept {
			*cancelled = true;
			thread.detach();
		}
	};
}
