#pragma once

#include "inc_std.hpp"

namespace ono{

enum class Dispose : int32_t {
    Refused = -1,       //已收到并拒绝处理
    NotReceived = 0,    //未收到并不处理
    Continue = 1,       //处理完且继续执行
    Break = 2           //处理完毕并不再让其他插件处理
};

}
