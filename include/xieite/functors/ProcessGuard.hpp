#ifndef XIEITE_HEADER__FUNCTORS__PROCESS_GUARD
#	define XIEITE_HEADER__FUNCTORS__PROCESS_GUARD

#	include <concepts>
#	include <memory>

namespace xieite::functors {
	class ProcessGuard {
	public:
		template<std::invocable<> Functor>
		ProcessGuard(const Functor callback) noexcept
		: released(std::make_shared<bool>(false)) {
			static const std::shared_ptr<bool> released = this->released;
			static const struct Lock final {
				~Lock() {
					if (!*released) {
						callback();
					}
				}
			} lock;
		}

		void release() noexcept {
			*this->released = true;
		}

	private:
		std::shared_ptr<bool> released;
	};
}

#endif
