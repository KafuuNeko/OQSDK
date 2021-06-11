#include "example.hpp"

using namespace ono;

INIT {
    __PLUGIN_INIT__
    return MAKE_PLUGIN_INFO(
            Example, //插件名称
            1:0:0, //插件版本
            KafuuNeko, //插件作者
            OQSDK C++ SDK, //插件说明
            8956RTEWDFG3216598WERDF3, //Skey 
            S3 //SDK版本
    );
}

/**
 * @brief 此子程序用于接收所有原始封包内容
 * @param qq 用于判定哪个QQ接收到该消息
 * @param type UDP收到的原始信息
 * @param original 经过Tea加密的原文
 * @param cookie 用于登录网页所需cookies，如不确定用途请忽略
 * @param sessionKey 通信包所用的加密秘钥
 * @param clientKey 登录网页服务用的秘钥
 * @return @see Dispose
 */
OQ_MESSAGE {
    return Dispose::Continue;
}

/**
 * @brief 此子程序会分发OQ_机器人QQ接收到的所有：事件，消息；您可在此函数中自行调用所有参数
 * @param botQQ 用于判定哪个QQ接收到该消息
 * @param type @see ono::MessageEvent
 * @param subType @see ono::MessageEvent 此参数在不同OQ_下，有不同的定义，暂定：接收财付通转账时 1待确认收款 0为已收款    有人请求入群时，不良成员这里为1
 * @param msgFrom 此消息的来源，如：群号、讨论组ID、临时会话QQ、好友QQ等
 * @param iTObj 主动发送这条消息的QQ，踢人时为踢人管理员QQ
 * @param pTObj 被动触发的QQ，如某人被踢出群，则此参数为被踢出人QQ
 * @param content 此参数有多重含义，常见为：对方发送的消息内容，但当OQ_消息类型为 某人申请入群，则为入群申请理由,当消息类型为财付通转账时为 原始json
 * @param msgSerial 此参数暂定用于消息撤回
 * @param msgId 此参数暂定用于消息撤回
 * @param original UDP收到的原始信息，特殊情况下会返回JSON结构（入群事件时，这里为该事件seq）
 * @param remittance 当消息类型为转账时,此为转账原始json,跟消息内容同源
 * @param callback 此参数用于插件加载拒绝理由  用法：写到内存（“拒绝理由”，OQ_信息回传文本指针_Out）
 */
OQ_Event {
    ono::raw::Api_OutPutLog("C++SDK");

    if(ono::raw::Api_IsEnable() && type == MessageType::Group) {
        auto index = kmp::find(content, "计算");
        if(index != kmp::npos) 
        {
            double result = 0;
            if(rpn::calculate(rpn::make(content + index), result))
            {
                ono::send_msg(botQQ, MessageType::Group, msgFrom, iTObj, ono::message().at(iTObj) << "Ono测试计算结果：" << std::to_string(result));
            }
            else
            {
                ono::send_msg(botQQ, MessageType::Group, msgFrom, iTObj, ono::message().at(iTObj) << "表达式错误，请检查您输入的表达式是否有误，且保证除数不能为0");
            }
        }
    }
    return Dispose::Continue;
}


/**
 * @brief 当用户按下“设置”执行本函数
 * 
 */
OQ_SetUp {

}

/**
 * @brief 当插件被卸载时将会调用
 * @return 返回非0成功 亦可不返回或为空
 */
OQ_DestroyPlugin {
    return 0;
}

