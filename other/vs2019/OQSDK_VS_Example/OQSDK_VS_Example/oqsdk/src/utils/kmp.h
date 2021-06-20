#pragma once

#include <inttypes.h>
#include <string>

namespace kmp {
	constexpr size_t npos = static_cast<size_t>(-1);
	size_t find(const std::string &findstr, const std::string &substr) noexcept;
	size_t find_count(const std::string &findstr, const std::string &substr) noexcept;
}
