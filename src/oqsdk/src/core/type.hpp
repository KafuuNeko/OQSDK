#pragma once

#include "inc_std.hpp"

namespace ono{

/**
 * @brief 处理方式
 * 
 */
enum class Dispose : int32_t 
{
    Refused = -1,       //已收到并拒绝处理
    NotReceived = 0,    //未收到并不处理
    Continue = 1,       //处理完且继续执行
    Break = 2           //处理完毕并不再让其他插件处理
};

enum class OnlineStatus : int32_t 
{
    Online  = 1, //在线状态_我在线上
    OMe     = 2, //在线状态_Q我吧
    Leave   = 3, //在线状态_离开
    Busy    = 4, //在线状态_忙碌
    DND     = 5, //在线状态_请勿打扰
    Hide    = 6  //在线状态_隐身
};

enum class LoadType : int32_t
{
    Load        = 12000, //OQ_本插件载入 返回20可拒绝加载 其他返回值均视为允许
    Enable      = 12001, //OQ_用户启用本插件 返回20可拒绝启用 其他返回值均视为允许启用
    Disabled    = 12002, //OQ_用户禁用本插件 无权拒绝
    Click       = 12003, //OQ_插件被点击 点击方式参考子类型. 1=左键单击 2=右键单击 3=左键双击
    Update      = 12004  //OQ_插件更新成功 无权拒绝,插件更新事件
};

enum class FriendEvent : int32_t 
{
    SingleAdd           = 100, //机器人被单项添加为了好友
    RequestAdd          = 101, //某人请求加机器人为好友
    BeAgreed            = 102, //机器人被某人同意加为好友
    BeRejected          = 103, //某人拒绝了机器人的加好友请求
    StateChanges        = 108, //好友状态改变了,如:改为在线,忙碌等等
    BeDeleted           = 104, //机器人被某人删除了
    SignatureChanges    = 106, //好友签名变动,修改了签名
    BeReviewed          = 107, //机器人的说说被某人评论
    BeTyping            = 110, //好友正在输入消息
    BeShaking           = 109, //被好友抖动了一下
    ReceiveOfflineFiles = 105, //收到好友文件,可从消息中取出文件下载链接
    ReceiveVideo        = 111  //收到好友视频,可从消息中取出视频下载链接
};

enum class GroupEvent : int32_t
{
    RequestJoin             = 213, //某人申请进群
    Invite                  = 215, //某人被邀请进群
    BeInvitedJoin           = 214, //机器人被邀请进群
    ApprovalJoin            = 212, //某人被批准加入了群
    InvitedJoin             = 219, //某人已经进群了,被邀请进来的
    QuitGroup               = 201, //某人退群了
    Removed                 = 202, //某人被管理踢出群
    Dissolve                = 216, //某群解散了
    BecomeManagement        = 210, //某人成为了管理
    CancelManagement        = 211, //某人被取消了管理权限
    GroupCardChange         = 217, //某群员的群名片改动了
    GroupNameChange         = 220, //某群群名被改变了
    GroupNoticesChanged     = 209, //某群发布了新的公告
    Banned                  = 203, //某人被禁言
    CancelBanned            = 204, //某人被解除禁言
    AllBanned               = 205, //某群开启了全体禁言
    CancelAllBanned         = 206, //某群关闭了全体禁言
    EnableAnonymous         = 207, //某群开启了匿名聊天
    CloseAnonymous          = 208, //某群关闭了匿名聊天
    Withdraw                = 221, //某人撤回了一条消息
    FileRecv                = 218, //收到群文件,可从消息中取出文件下载链接
    VideoRecv               = 222, //收到群视频,可从消息中取出视频下载链接
    DisVideoRecv            = 223  //收到讨论组视频,可从消息中取出视频下载链接
};

enum class MessageEvent : int32_t
{
    Undefined           = -1,   //OQ_未定义
    TempSession         = 0,    //OQ_在线临时会话
    Friend              = 1,    //OQ_好友
    Group               = 2,    //OQ_群
    Discussion          = 3,    //OQ_讨论组
    GroupTempSession    = 4,    //OQ_群临时会话
    DisTempSession      = 5,    //OQ_讨论组临时会话
    Collection          = 6,    //OQ_收到财付通转账
    FriendverifyReply   = 7,    //OQ_好友验证回复会话
    ConfirmationEPF     = 0,    //OQ_收到财付通转账_已确认
    WaitingEPF          = 1     //OQ_收到财付通转账_待收款
};

}
