#pragma once

#include "type.hpp"
#include "inc_std.hpp"
            

#define APP_CREATE void ono::app_create()

#define APP_INFO(Name, Version, Author, Explain, Skey, Sdk) const char * ono::app_info() \
    { return "插件名称{"#Name"}\r\n插件版本{"#Version"}\r\n插件作者{"#Author"}\r\n插件说明{"#Explain"}\r\n插件skey{"#Skey"}\r\n插件sdk{"#Sdk"}"; }

namespace ono
{

void app_create();
const char * app_info();

struct OriginalPacketEvent
{
    ono::Dispose result = ono::Dispose::Continue;

    const std::string qq; //用于判定哪个QQ接收到该消息
    const std::string original; //经过Tea加密的原文
    const std::string cookie; //用于登录网页所需cookies，如不确定用途请忽略
    const std::string sessionKey; //通信包所用的加密秘钥
    const std::string clientKey; //登录网页服务用的秘钥

    int32_t type; //UDP收到的原始信息

    OriginalPacketEvent(const std::string &qq, const std::string &original, const std::string &cookie, const std::string &sessionKey, const std::string &clientKey, int32_t type)
        : qq(qq), original(original), cookie(cookie), sessionKey(sessionKey), clientKey(clientKey), type(type) { }

};

struct MessageEvent
{
    ono::Dispose result = ono::Dispose::Continue;

    const std::string botQQ; //用于判定哪个QQ接收到该消息
    const ono::MessageType type; //@see ono::MessageEvent
    const ono::MessageType subType; //@see ono::MessageEvent 此参数在不同OQ_下，有不同的定义，暂定：接收财付通转账时 1待确认收款 0为已收款    有人请求入群时，不良成员这里为1
    const std::string msgFrom; //此消息的来源，如：群号、讨论组ID、临时会话QQ、好友QQ等
    const std::string iTObj; //主动发送这条消息的QQ，踢人时为踢人管理员QQ
    const std::string pTObj; //被动触发的QQ，如某人被踢出群，则此参数为被踢出人QQ
    const std::string content; //此参数有多重含义，常见为：对方发送的消息内容，但当OQ_消息类型为 某人申请入群，则为入群申请理由,当消息类型为财付通转账时为 原始json
    const std::string msgSerial; //此参数暂定用于消息撤回
    const std::string msgId; //此参数暂定用于消息撤回
    const std::string original; //UDP收到的原始信息，特殊情况下会返回JSON结构（入群事件时，这里为该事件seq）
    const std::string remittance; //当消息类型为转账时,此为转账原始json,跟消息内容同源

    void * callback_text; //此参数用于插件加载拒绝理由  用法：写到内存（“拒绝理由”，OQ_信息回传文本指针_Out）

    MessageEvent(const std::string &botQQ, 
                ono::MessageType type,
                ono::MessageType subType,
                const std::string &msgFrom,
                const std::string &iTObj,
                const std::string &pTObj,
                const std::string &content,
                const std::string &msgSerial,
                const std::string &msgId,
                const std::string &original,
                const std::string &remittance,
                void * callback_text)
            :   botQQ(botQQ), type(type), subType(subType),  msgFrom(msgFrom), 
                iTObj(iTObj), pTObj(pTObj), content(content), msgSerial(msgSerial), 
                msgId(msgId), original(original), remittance(remittance), callback_text(callback_text) {}
};


}



