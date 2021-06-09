#pragma once

#include <Windows.h>
#include <assert.h>
#include <inttypes.h>
#include <string>

namespace ono {

class api_base
{

    HMODULE handle_;

public:
    api_base() = default;

    void init() 
    {
        handle_ = ::GetModuleHandle("OQapi.dll");
        assert(handle_);
    }

    /**
     * @brief 发送普通文本消息
     * 
     * @param botQQ 机器人QQ
     * @param msgType 0在线临时会话 1好友 2群 3讨论组 4群临时会话 5讨论组临时会话 7好友验证回复会话（0、7只支持Pro版）
     * @param group 发送群信息、讨论组、群或讨论组临时会话信息时填写，如发送对象为好友或信息类型是0时可空
     * @param receiver 收信对象QQ
     * @param content 信息内容
     * @param bubbleId -1为随机气泡
     */
    void send_msg(const std::string &botQQ, int32_t msgType, const std::string &group, const std::string &receiver, const std::string &content, int32_t bubbleId) const 
    {
        using sign = void(const char *, int32_t, const char *, const char *, const char *, int32_t);
        auto call = (sign*)(::GetProcAddress(handle_, "Api_SendMsg"));
        call(botQQ.c_str(), msgType, group.c_str(), receiver.c_str(), content.c_str(), bubbleId);
    }

    /**
     * @brief 发送普通文本消息
     * 
     * @param botQQ 机器人QQ
     * @param anonymity 1为普通 2为匿名（匿名需要群开启,Pro可用）
     * @param msgType 0在线临时会话 1好友 2群 3讨论组 4群临时会话 5讨论组临时会话 7好友验证回复会话（0、7只支持Pro版）
     * @param group 发送群信息、讨论组、群或讨论组临时会话信息时填写，如发送对象为好友或信息类型是0时可空
     * @param receiver 收信对象QQ
     * @param content 信息内容
     * @param bubbleId -1为随机气泡
     */
    void send_msg_ex(const std::string &botQQ, int32_t anonymity, int32_t msgType, const std::string &group, const std::string &receiver, const std::string &content, int32_t bubbleId) const 
    {
        using sign = void(const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t);
        auto call = (sign*)(::GetProcAddress(handle_, "Api_SendMsgEx"));
        call(botQQ.c_str(), anonymity, msgType, group.c_str(), receiver.c_str(), content.c_str(), bubbleId);
    }

    /**
     * @brief 发送XML消息
     * 
     * @param botQQ 机器人QQ
     * @param sendMode 1普通 2匿名（匿名需要群开启,Pro可用）
     * @param msgType 0在线临时会话 1好友 2群 3讨论组 4群临时会话 5讨论组临时会话 7好友验证回复会话（0、7只支持Pro版）
     * @param group 发送群信息、讨论组、群或讨论组临时会话信息时填写，如发送对象为好友或信息类型是0时可空
     * @param receiver 收信对象QQ
     * @param xml XML代码
     * @param structSubType 0 基本 2 点歌
     */
    void send_xml(const std::string &botQQ, int32_t sendMode, int32_t msgType, const std::string &group, const std::string &receiver, const std::string &xml, int32_t structSubType)
    {
        using sign = void(const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t);
        auto call = (sign*)(::GetProcAddress(handle_, "Api_SendMsgEx"));
        call(botQQ.c_str(), sendMode, msgType, group.c_str(), receiver.c_str(), xml.c_str(), structSubType);
    }

    /**
     * @brief 发送JSON结构消息
     * 
     * @param botQQ 机器人QQ
     * @param sendMode 1普通 2匿名（匿名需要群开启,Pro可用）
     * @param msgType 0在线临时会话 1好友 2群 3讨论组 4群临时会话 5讨论组临时会话 7好友验证回复会话（0、7只支持Pro版）
     * @param group 发送群信息、讨论组、群或讨论组临时会话信息时填写，如发送对象为好友或信息类型是0时可空
     * @param receiver 收信对象QQ
     * @param json Json结构内容
     */
    void send_json(const std::string &botQQ, int32_t sendMode, int32_t msgType, const std::string &group, const std::string &receiver, const std::string &json)
    {
        using sign = void(const char *, int32_t, int32_t, const char *, const char *, const char *);
        auto call = (sign*)(::GetProcAddress(handle_, "Api_SendJSON"));
        call(botQQ.c_str(), sendMode, msgType, group.c_str(), receiver.c_str(), json.c_str());
    }

    /**
     * @brief 发送JSON结构消息
     * 
     * @param botQQ 机器人QQ
     * @param sendMode 1普通 2匿名（匿名需要群开启,Pro可用）
     * @param msgType 0在线临时会话 1好友 2群 3讨论组 4群临时会话 5讨论组临时会话 7好友验证回复会话（0、7只支持Pro版）
     * @param group 发送群信息、讨论组、群或讨论组临时会话信息时填写，如发送对象为好友或信息类型是0时可空
     * @param receiver 收信对象QQ
     * @param json Json结构内容
     * @param structSubType 0普通(如点歌) 1假红包JSON
     */
    void send_json_ex(const std::string &botQQ, int32_t sendMode, int32_t msgType, const std::string &group, const std::string &receiver, const std::string &json, int32_t structSubType)
    {
        using sign = void(const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t);
        auto call = (sign*)(::GetProcAddress(handle_, "Api_SendJsonEx"));
        call(botQQ.c_str(), sendMode, msgType, group.c_str(), receiver.c_str(), json.c_str(), structSubType);
    }

};

class api : public api_base {
    //...
};

}