#pragma once

#include "../meta/is_template_of.hpp"

namespace xieite {
	template<template<typename...> typename M, typename... Ts>
	concept is_template_of_any = (... || xieite::is_template_of<M, Ts>);
}
