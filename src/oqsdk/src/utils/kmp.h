#pragma once

#include <inttypes.h>

namespace kmp {
	constexpr size_t npos = static_cast<size_t>(-1);
	size_t find(const char* findstr, const char* substr) noexcept;
	size_t find_count(const char* findstr, const char* substr) noexcept;
};
