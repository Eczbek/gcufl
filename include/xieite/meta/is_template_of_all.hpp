#pragma once

#include "../meta/is_template_of.hpp"

namespace xieite {
	template<template<typename...> typename M, typename... Ts>
	concept is_template_of_all = (... && xieite::is_template_of<M, Ts>);
}
