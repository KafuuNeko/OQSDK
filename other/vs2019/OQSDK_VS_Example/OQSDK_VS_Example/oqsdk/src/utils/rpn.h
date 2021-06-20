#pragma once

#include <string>

namespace rpn {

std::string make(const std::string& math_exp) noexcept;

bool calculate(const std::string& rpn_exp, double & result) noexcept;

}
