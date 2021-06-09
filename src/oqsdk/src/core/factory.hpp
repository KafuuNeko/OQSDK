#pragma once

#include <inttypes.h>

#define MAKE_PLUGIN_INFO(Name, Version, Author, Explain, Skey, Sdk)\
            "插件名称{"#Name"}\r\n"\
            "插件版本{"#Version"}\r\n"\
            "插件作者{"#Author"}\r\n"\
            "插件说明{"#Explain"}\r\n"\
            "插件skey{"#Skey"}\r\n"\
            "插件sdk{"#Sdk"}"


enum class Dispose : int32_t {
    Refused = -1,       //已收到并拒绝处理
    NotReceived = 0,    //未收到并不处理
    Continue = 1,       //处理完且继续执行
    Break = 2           //处理完毕并不再让其他插件处理
};