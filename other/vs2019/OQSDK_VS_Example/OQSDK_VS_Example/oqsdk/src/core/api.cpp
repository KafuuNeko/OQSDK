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

    raw::Api_TeaEncrypt = reinterpret_cast<decltype(raw::Api_TeaEncrypt)>(GetProcAddress(dll, "Api_Tea����"));
    raw::Api_TeaDecode  = reinterpret_cast<decltype(raw::Api_TeaEncrypt)>(GetProcAddress(dll, "Api_Tea����"));
}

/**
 * @brief ������ͨ�ı���Ϣ
 * 
 * @param bot ������QQ
 * @param msgType @see ono::MessageEvent
 * @param group ����Ⱥ��Ϣ�������顢Ⱥ����������ʱ�Ự��Ϣʱ��д���緢�Ͷ���Ϊ���ѻ���Ϣ������0ʱ�ɿ�
 * @param qq ���Ŷ���QQ
 * @param content ��Ϣ����
 * @param bubble -1Ϊ�������
 * @param anonymity �Ƿ�������Ϣ
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

}

