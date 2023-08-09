#ifndef XIETIE__HEADER__MEMORY__GET_PAGE_SIZE
#	define XIETIE__HEADER__MEMORY__GET_PAGE_SIZE

#	include "../macros/SYSTEM_TYPE.hpp"

#	if XIEITE__SYSTEM_TYPE__UNIX
#		include <cstddef>
#		include <unistd.h>

namespace xieite::memory {
	inline std::size_t getPageSize() noexcept {
		return ::sysconf(_SC_PAGE_SIZE);
	}
}

#	elif XIEITE__SYSTEM_TYPE__WINDOWS
#		include <cstddef>
#		include <windows.h>

namespace xieite::memory {
	inline std::size_t getPageSize() noexcept {
		::SYSTEM_INFO info;
		::GetSystemInfo(&info);
		return info.dwPageSize;
	}
}

#	else
#		error "System not supported"
#	endif

#endif
