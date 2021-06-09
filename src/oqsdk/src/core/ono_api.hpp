#pragma once

#include <Windows.h>
#include <assert.h>
#include <inttypes.h>
#include <string>

class OqApi {

    HMODULE handle_;

public:
    OqApi() = default;

    void init() {
        handle_ = ::GetModuleHandle("OQapi.dll");
        assert(handle_);
    }

    /**
     * @brief 发送普通文本消息
     * 
     * @param botQQ 机器人QQ
     * @param type 0在线临时会话 1好友 2群 3讨论组 4群临时会话 5讨论组临时会话 7好友验证回复会话（0、7只支持Pro版）
     * @param group 发送群信息、讨论组、群或讨论组临时会话信息时填写，如发送对象为好友或信息类型是0时可空
     * @param fromQQ 收信对象QQ
     * @param content 信息内容
     * @param bubbleId -1为随机气泡
     */
    void send_msg(const std::string &botQQ, int32_t type, const std::string &group, const std::string &fromQQ, const std::string &content, int32_t bubbleId) const {
        using sign = void(const char *, int32_t, const char *, const char *, const char *, int32_t);
        auto call = (sign*)(::GetProcAddress(handle_, "Api_SendMsg"));
        call(botQQ.c_str(), type, group.c_str(), fromQQ.c_str(), content.c_str(), bubbleId);
    }

};