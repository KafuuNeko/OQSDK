#include "api.hpp"

namespace ono 
{

namespace raw 
{
    #define OQApi(ReturnType, FuncName, ...) ReturnType(__stdcall *Api_##FuncName)(__VA_ARGS__) = nullptr;
    
    #include "./api_funcs.inc"

    #undef OQApi

    const char * (__stdcall *Api_TeaEncrypt)(const char *, const char *) = nullptr;
    const char * (__stdcall *Api_TeaDecode)(const char *, const char *)  = nullptr;

}

void _init_api() noexcept(false)
{
    const auto dll = GetModuleHandleW(L"OQapi.dll");

    #define OQApi(ReturnType, FuncName, ...) raw::Api_##FuncName = reinterpret_cast<decltype(raw::Api_##FuncName)>(GetProcAddress(dll, "Api_" #FuncName));

    #include "./api_funcs.inc"
    
    #undef OQApi

    raw::Api_TeaEncrypt = reinterpret_cast<decltype(raw::Api_TeaEncrypt)>(GetProcAddress(dll, "Api_Tea加密"));
    raw::Api_TeaDecode  = reinterpret_cast<decltype(raw::Api_TeaEncrypt)>(GetProcAddress(dll, "Api_Tea解密"));
}

/**
 * @brief 判断插件是否启动
 * 
 * @return true 启动
 * @return false 未启动
 */
bool is_enable()
{
    return raw::Api_IsEnable();
}

/**
 * @brief 发送普通文本消息
 * 
 * @param bot 机器人QQ
 * @param msgType @see ono::MessageEvent
 * @param group 发送群信息、讨论组、群或讨论组临时会话信息时填写，如发送对象为好友或信息类型是0时可空
 * @param qq 收信对象QQ
 * @param content 信息内容
 * @param bubble -1为随机气泡
 * @param anonymity 是否匿名信息
 */
void send_msg(const std::string &bot,
    ono::MessageType msgType, 
    const std::string &group, 
    const std::string &qq, 
    const std::string &content, 
    int32_t bubble, 
    bool anonymity) noexcept
{
    raw::Api_SendMsgEx(bot.c_str(), (anonymity ? 2 : 1), msgType, group.c_str(), qq.c_str(), content.c_str(), bubble);
}

/**
 * @brief 发送日志消息
 * 
 * @param message 日志消息内容
 */
void out_put_log(const std::string &message) 
{
    raw::Api_OutPutLog(message.c_str());
}

}


