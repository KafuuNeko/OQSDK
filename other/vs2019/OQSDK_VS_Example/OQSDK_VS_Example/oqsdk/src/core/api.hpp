#pragma once

#include "inc_std.hpp"
#include "type.hpp"

namespace ono
{
namespace raw 
{

#define OQApi(ReturnType, FuncName, ...) extern ReturnType(__stdcall *Api_##FuncName)(__VA_ARGS__);
#include "./api_funcs.inc"
#undef OQApi

extern const char * (__stdcall *Api_TeaEncrypt)(const char *, const char *);
extern const char * (__stdcall *Api_TeaDecode)(const char *, const char *);

}

void _init_api() noexcept(false);

void send_msg(const std::string &bot,
    ono::MessageType msgType, 
    const std::string &group, 
    const std::string &qq, 
    const std::string &content, 
    int32_t bubble = -1, 
    bool anonymity = false) noexcept;

} 
