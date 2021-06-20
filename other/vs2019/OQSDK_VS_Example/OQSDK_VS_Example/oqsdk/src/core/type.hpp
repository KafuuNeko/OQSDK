#pragma once

#include "inc_std.hpp"

namespace ono{

/**
 * @brief ����ʽ
 * 
 */
enum class Dispose : int32_t 
{
    Refused = -1,       //���յ����ܾ�����
    NotReceived = 0,    //δ�յ���������
    Continue = 1,       //�������Ҽ���ִ��
    Break = 2           //������ϲ������������������
};

enum class OnlineStatus : int32_t 
{
    Online  = 1, //����״̬_��������
    OMe     = 2, //����״̬_Q�Ұ�
    Leave   = 3, //����״̬_�뿪
    Busy    = 4, //����״̬_æµ
    DND     = 5, //����״̬_�������
    Hide    = 6  //����״̬_����
};

enum class LoadType : int32_t
{
    Load        = 12000, //OQ_��������� ����20�ɾܾ����� ��������ֵ����Ϊ����
    Enable      = 12001, //OQ_�û����ñ���� ����20�ɾܾ����� ��������ֵ����Ϊ��������
    Disabled    = 12002, //OQ_�û����ñ���� ��Ȩ�ܾ�
    Click       = 12003, //OQ_�������� �����ʽ�ο�������. 1=������� 2=�Ҽ����� 3=���˫��
    Update      = 12004  //OQ_������³ɹ� ��Ȩ�ܾ�,��������¼�
};

enum class FriendEvent : int32_t 
{
    SingleAdd           = 100, //�����˱��������Ϊ�˺���
    RequestAdd          = 101, //ĳ������ӻ�����Ϊ����
    BeAgreed            = 102, //�����˱�ĳ��ͬ���Ϊ����
    BeRejected          = 103, //ĳ�˾ܾ��˻����˵ļӺ�������
    StateChanges        = 108, //����״̬�ı���,��:��Ϊ����,æµ�ȵ�
    BeDeleted           = 104, //�����˱�ĳ��ɾ����
    SignatureChanges    = 106, //����ǩ���䶯,�޸���ǩ��
    BeReviewed          = 107, //�����˵�˵˵��ĳ������
    BeTyping            = 110, //��������������Ϣ
    BeShaking           = 109, //�����Ѷ�����һ��
    ReceiveOfflineFiles = 105, //�յ������ļ�,�ɴ���Ϣ��ȡ���ļ���������
    ReceiveVideo        = 111  //�յ�������Ƶ,�ɴ���Ϣ��ȡ����Ƶ��������
};

enum class GroupEvent : int32_t
{
    RequestJoin             = 213, //ĳ�������Ⱥ
    Invite                  = 215, //ĳ�˱������Ⱥ
    BeInvitedJoin           = 214, //�����˱������Ⱥ
    ApprovalJoin            = 212, //ĳ�˱���׼������Ⱥ
    InvitedJoin             = 219, //ĳ���Ѿ���Ⱥ��,�����������
    QuitGroup               = 201, //ĳ����Ⱥ��
    Removed                 = 202, //ĳ�˱������߳�Ⱥ
    Dissolve                = 216, //ĳȺ��ɢ��
    BecomeManagement        = 210, //ĳ�˳�Ϊ�˹���
    CancelManagement        = 211, //ĳ�˱�ȡ���˹���Ȩ��
    GroupCardChange         = 217, //ĳȺԱ��Ⱥ��Ƭ�Ķ���
    GroupNameChange         = 220, //ĳȺȺ�����ı���
    GroupNoticesChanged     = 209, //ĳȺ�������µĹ���
    Banned                  = 203, //ĳ�˱�����
    CancelBanned            = 204, //ĳ�˱��������
    AllBanned               = 205, //ĳȺ������ȫ�����
    CancelAllBanned         = 206, //ĳȺ�ر���ȫ�����
    EnableAnonymous         = 207, //ĳȺ��������������
    CloseAnonymous          = 208, //ĳȺ�ر�����������
    Withdraw                = 221, //ĳ�˳�����һ����Ϣ
    FileRecv                = 218, //�յ�Ⱥ�ļ�,�ɴ���Ϣ��ȡ���ļ���������
    VideoRecv               = 222, //�յ�Ⱥ��Ƶ,�ɴ���Ϣ��ȡ����Ƶ��������
    DisVideoRecv            = 223  //�յ���������Ƶ,�ɴ���Ϣ��ȡ����Ƶ��������
};

enum class MessageType : int32_t
{
    Undefined           = -1,   //OQ_δ����
    TempSession         = 0,    //OQ_������ʱ�Ự
    Friend              = 1,    //OQ_����
    Group               = 2,    //OQ_Ⱥ
    Discussion          = 3,    //OQ_������
    GroupTempSession    = 4,    //OQ_Ⱥ��ʱ�Ự
    DisTempSession      = 5,    //OQ_��������ʱ�Ự
    Collection          = 6,    //OQ_�յ��Ƹ�ͨת��
    FriendverifyReply   = 7,    //OQ_������֤�ظ��Ự
    ConfirmationEPF     = 0,    //OQ_�յ��Ƹ�ͨת��_��ȷ��
    WaitingEPF          = 1     //OQ_�յ��Ƹ�ͨת��_���տ�
};

}


