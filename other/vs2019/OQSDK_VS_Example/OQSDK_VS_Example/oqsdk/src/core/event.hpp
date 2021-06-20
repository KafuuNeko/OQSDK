#pragma once

#include "type.hpp"
#include "inc_std.hpp"
            

#define APP_CREATE void ono::app_create()

#define APP_INFO(Name, Version, Author, Explain, Skey, Sdk) const char * ono::app_info() \
    { return "�������{"#Name"}\r\n����汾{"#Version"}\r\n�������{"#Author"}\r\n���˵��{"#Explain"}\r\n���skey{"#Skey"}\r\n���sdk{"#Sdk"}"; }

namespace ono
{

void app_create();
const char * app_info();

struct OriginalPacketEvent
{
    ono::Dispose result = ono::Dispose::Continue;

    const std::string qq; //�����ж��ĸ�QQ���յ�����Ϣ
    const std::string original; //����Tea���ܵ�ԭ��
    const std::string cookie; //���ڵ�¼��ҳ����cookies���粻ȷ����;�����
    const std::string sessionKey; //ͨ�Ű����õļ�����Կ
    const std::string clientKey; //��¼��ҳ�����õ���Կ

    int32_t type; //UDP�յ���ԭʼ��Ϣ

    OriginalPacketEvent(const std::string &qq, const std::string &original, const std::string &cookie, const std::string &sessionKey, const std::string &clientKey, int32_t type)
        : qq(qq), original(original), cookie(cookie), sessionKey(sessionKey), clientKey(clientKey), type(type) { }

};

struct MessageEvent
{
    ono::Dispose result = ono::Dispose::Continue;

    const std::string botQQ; //�����ж��ĸ�QQ���յ�����Ϣ
    const ono::MessageType type; //@see ono::MessageEvent
    const ono::MessageType subType; //@see ono::MessageEvent �˲����ڲ�ͬOQ_�£��в�ͬ�Ķ��壬�ݶ������ղƸ�ͨת��ʱ 1��ȷ���տ� 0Ϊ���տ�    ����������Ⱥʱ��������Ա����Ϊ1
    const std::string msgFrom; //����Ϣ����Դ���磺Ⱥ�š�������ID����ʱ�ỰQQ������QQ��
    const std::string iTObj; //��������������Ϣ��QQ������ʱΪ���˹���ԱQQ
    const std::string pTObj; //����������QQ����ĳ�˱��߳�Ⱥ����˲���Ϊ���߳���QQ
    const std::string content; //�˲����ж��غ��壬����Ϊ���Է����͵���Ϣ���ݣ�����OQ_��Ϣ����Ϊ ĳ��������Ⱥ����Ϊ��Ⱥ��������,����Ϣ����Ϊ�Ƹ�ͨת��ʱΪ ԭʼjson
    const std::string msgSerial; //�˲����ݶ�������Ϣ����
    const std::string msgId; //�˲����ݶ�������Ϣ����
    const std::string original; //UDP�յ���ԭʼ��Ϣ����������»᷵��JSON�ṹ����Ⱥ�¼�ʱ������Ϊ���¼�seq��
    const std::string remittance; //����Ϣ����Ϊת��ʱ,��Ϊת��ԭʼjson,����Ϣ����ͬԴ

    void * callback_text; //�˲������ڲ�����ؾܾ�����  �÷���д���ڴ棨���ܾ����ɡ���OQ_��Ϣ�ش��ı�ָ��_Out��

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



