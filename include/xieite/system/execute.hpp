#pragma once

#include <string>
#include <string_view>
#include "../streams/pipe.hpp"
#include "../streams/read.hpp"
#include "../system/result.hpp"

namespace xieite::system {
	inline xieite::system::Result execute(const std::string_view command) noexcept {
		xieite::streams::Pipe pipe = xieite::streams::Pipe(std::string(command), "r");
		const std::string output = xieite::streams::read(pipe.file());
		return xieite::system::Result(output, pipe.close());
	}
}
