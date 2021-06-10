#pragma once

#include <Windows.h>
#include <assert.h>
#include <inttypes.h>
#include <string>

namespace ono {

class api_base
{

    HMODULE handle_;

    template<class _Sign>
    _Sign *module_api(const char * funcName) const noexcept
    {
        return reinterpret_cast<_Sign*>(::GetProcAddress(handle_, funcName));
    }

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
        auto call = module_api<void(const char *, int32_t, const char *, const char *, const char *, int32_t)>("Api_SendMsg");
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
        auto call = module_api<void(const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t)>("Api_SendMsgEx");
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
    void send_xml(const std::string &botQQ, int32_t sendMode, int32_t msgType, const std::string &group, const std::string &receiver, const std::string &xml, int32_t structSubType) const
    {
        auto call = module_api<void(const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t)>("Api_SendMsgEx");
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
    void send_json(const std::string &botQQ, int32_t sendMode, int32_t msgType, const std::string &group, const std::string &receiver, const std::string &json) const
    {
        auto call = module_api<void(const char *, int32_t, int32_t, const char *, const char *, const char *)>("Api_SendJSON");
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
    void send_json_ex(const std::string &botQQ, int32_t sendMode, int32_t msgType, const std::string &group, const std::string &receiver, const std::string &json, int32_t structSubType) const
    {
        auto call = module_api<void(const char *, int32_t, int32_t, const char *, const char *, const char *, int32_t)>("Api_SendJsonEx");
        call(botQQ.c_str(), sendMode, msgType, group.c_str(), receiver.c_str(), json.c_str(), structSubType);
    }

    /**
     * @brief 调用一次点一下，成功返回空
     * 
     * @param botQQ 机器人QQ
     * @param object 填写被赞人QQ
     * @return 失败返回理由如：每天最多给他点十个赞哦，调用此Api时应注意频率，每人每日可被赞10次，每日每Q最多可赞50人
     */
    std::string up_vote(const std::string &botQQ, const std::string &object) const
    {
        auto call = module_api<const char*(const char *, const char *)>("Api_UpVote");
        return call(botQQ.c_str(), object.c_str());
    }

    /**
     * @brief 调用一次点一下，成功返回空
     * 
     * @param botQQ 机器人QQ
     * @param object 填写被赞人QQ
     * @return 失败返回理由如：每天最多给他点十个赞哦，调用此Api时应注意频率，每人每日可被赞10次，每日每Q最多可赞50人
     */
    std::string up_vote_ex(const std::string &botQQ, const std::string &object) const
    {
        auto call = module_api<const char*(const char *, const char *)>("Api_UpVoteEx");
        return call(botQQ.c_str(), object.c_str());
    }

    /**
     * @brief 取得机器人网页操作用的Cookies
     * 
     * @param botQQ 机器人QQ
     * @return 网页操作用的Cookies
     */
    std::string get_cookies(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetCookies");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得腾讯微博页面操作用参数P_skey
     * 
     * @param botQQ 机器人QQ
     * @return 腾讯微博页面操作用参数P_skey
     */
    std::string get_blog_psKey(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetBlogPsKey");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得QQ空间页面操作用参数P_skey
     * 
     * @param botQQ 机器人QQ
     * @return QQ空间页面操作用参数P_skey
     */
    std::string get_zone_psKey(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetZonePsKey");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得QQ群页面操作用参数P_skey
     * 
     * @param botQQ 机器人QQ
     * @return QQ群页面操作用参数P_skey
     */
    std::string get_group_ps_key(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetGroupPsKey");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得腾讯课堂页面操作用参数P_skey
     * 
     * @param botQQ 机器人QQ
     * @return 腾讯课堂页面操作用参数P_skey
     */
    std::string get_class_room_ps_key(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetClassRoomPsKey");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得机器人网页操作用参数Bkn或G_tk
     * 
     * @param botQQ 机器人QQ
     * @return 网页操作用参数Bkn或G_tk
     */
    std::string get_bkn(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetClassRoomPsKey");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得机器人网页操作用参数长Bkn或长G_tk
     * 
     * @param botQQ 机器人QQ
     * @return 网页操作用参数长Bkn或长G_tk
     */
    std::string get_bkn32(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetBkn32");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得机器人网页操作用参数长Ldw
     * 
     * @param botQQ 机器人QQ
     * @return 网页操作用参数长Ldw
     */
    std::string get_long_ldw(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetLongLdw");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得机器人网页操作用的Clientkey
     * 
     * @param botQQ 机器人QQ
     * @return 网页操作用的Clientkey
     */
    std::string get_client_key(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetClientkey");
        return call(botQQ.c_str());
    }

    /**
     * @brief 取得机器人网页操作用的长Clientkey
     * 
     * @param botQQ 机器人QQ
     * @return 网页操作用的长Clientkey
     */
    std::string get_long_client_key(const std::string &botQQ) const
    {
        auto call = module_api<const char*(const char *)>("Api_GetLongClientkey");
        return call(botQQ.c_str());
    }

    /**
     * @brief 管理员邀请对象入群，频率过快会失败
     * 
     * @param botQQ 机器人QQ
     * @param group 被邀请加入的群号
     * @param object 被邀请人QQ号码（多个号码使用 #换行符 分割）
     */
    void admin_invite_group(const std::string &botQQ, const std::string &group, const std::string &object) const
    {
        auto call = module_api<void(const char *, const char *, const char *)>("Api_GetLongClientkey");
        call(botQQ.c_str(), group.c_str(), object.c_str());
    }

    /**
     * @brief 非管理员邀请对象入群，频率过快会失败
     * 
     * @param botQQ 机器人QQ
     * @param group 被邀请加入的群号
     * @param object 被邀请人QQ号码（多个号码使用 #换行符 分割）
     */
    void not_admin_invite_group(const std::string &botQQ, const std::string &group, const std::string &object) const
    {
        auto call = module_api<void(const char *, const char *, const char *)>("Api_NoAdminInviteGroup");
        call(botQQ.c_str(), group.c_str(), object.c_str());
    }

    /**
     * @brief 取对象昵称
     * 
     * @param botQQ 机器人QQ
     * @param object 欲取得的QQ的号码
     */
    void get_nick(const std::string &botQQ, const std::string &object) const
    {
        auto call = module_api<void(const char *, const char *)>("Api_GetNick");
        call(botQQ.c_str(), object.c_str());
    }

};

class api : public api_base 
{
    //...
};

}

