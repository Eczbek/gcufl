#ifndef XIEITE_HEADER_MATH_VERSION
#	define XIEITE_HEADER_MATH_VERSION

#	include <compare>
#	include <cstddef>
#	include <string>
#	include <string_view>
#	include "../concepts/string.hpp"
#	include "../concepts/string_view.hpp"
#	include "../math/stringify.hpp"

namespace xieite::math {
	template<xieite::concepts::String String = std::string>
	struct Version {
		std::size_t major;
		std::size_t minor;
		std::size_t patch;
		String label;

		template<xieite::concepts::StringView StringView = std::string_view>
		constexpr Version(const std::size_t major = 0, const std::size_t minor = 0, const std::size_t patch = 0, const std::string_view label = "") noexcept
		: major(major), minor(minor), patch(patch), label(label) {}

		[[nodiscard]] friend constexpr std::strong_ordering operator<=>(const xieite::math::Version& version1, const xieite::math::Version& version2) noexcept {
			return (version1.major != version2.major) ? (version1.major <=> version2.major) : ((version1.minor != version2.minor) ? (version1.minor <=> version2.minor) : (version1.patch <=> version2.patch));
		}

		[[nodiscard]] friend constexpr bool operator==(const xieite::math::Version& version1, const xieite::math::Version& version2) noexcept {
			return std::is_eq(version1 <=> version2);
		}

		[[nodiscard]] constexpr String string() const noexcept {
			String result = 'v' + xieite::math::stringify(this->major) + '.' + xieite::math::stringify(this->minor) + '.' + xieite::math::stringify(this->patch);
			if (this->label.size()) {
				result += '-' + this->label;
			}
			return result;
		}
	};
}

#endif

// TODO: Use xieite::strings::format() for constexpr stringification in the future
