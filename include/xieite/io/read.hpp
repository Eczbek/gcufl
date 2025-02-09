#pragma once

#include <cstddef>
#include <cstdio>
#include <istream>
#include <iterator>
#include <string>

namespace xieite {
	[[nodiscard]] inline std::string read(std::istream& stream) noexcept {
		return std::string(std::istreambuf_iterator<char>(stream), {});
	}

	[[nodiscard]] inline std::string read(std::FILE* stream) noexcept {
		std::string result;
		std::size_t chunk = 1024;
		while (stream) {
			std::string buffer = std::string(chunk, '\0');
			const std::size_t bytes = std::fread(buffer.data(), 1, chunk, stream);
			result += buffer.substr(0, bytes);
			if (bytes != chunk) {
				break;
			}
			chunk *= 2;
		}
		return result;
	}
}

// TODO: Research best initial chunk size
