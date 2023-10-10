#pragma once

#include "../macros/platform.hpp"

#if !XIEITE_PLATFORM_UNIX
#	error "System not supported"
#endif

#include <sys/socket.h>

namespace xieite::network {
	enum struct Protocol
	: int {
		Default = 0,
		ICMPv4 = IPPROTO_ICMP,
		ICMPv6 = IPPROTO_ICMPV6,
		IPv4 = IPPROTO_IP,
		IPv6 = IPPROTO_IPV6,
		Raw = IPPROTO_RAW,
		TCP = IPPROTO_TCP,
		UDP = IPPROTO_UDP
	};
}
