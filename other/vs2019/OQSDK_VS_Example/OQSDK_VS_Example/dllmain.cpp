// dllmain.cpp : ���� DLL Ӧ�ó������ڵ㡣
#include "oqsdk/include/oqsdk.hpp"
#include "framework.h"

BOOL APIENTRY DllMain(HMODULE hModule,
	DWORD  ul_reason_for_call,
	LPVOID lpReserved
)
{
	switch (ul_reason_for_call)
	{
	case DLL_PROCESS_ATTACH:
	case DLL_THREAD_ATTACH:
	case DLL_THREAD_DETACH:
	case DLL_PROCESS_DETACH:
		break;
	}
	return TRUE;
}

using namespace ono;

APP_INFO(
	OQSDK_VS_Example, //�������
	1:0 : 0, //����汾
	KafuuNeko, //�������
	OQSDK C++ SDK, //���˵��
	8956RTEWDFG3216598WERDF3, //Skey 
	S3 //SDK�汾
);

APP_CREATE
{
	//��������ԭʼ�������
	bind_original_packet([](ono::OriginalPacketEvent& e) {

	});

//�ַ�OQ_������QQ���յ������У��¼�����Ϣ�������ڴ˺��������е������в���
bind_message([](ono::MessageEvent& e) {
	ono::raw::Api_OutPutLog("C++SDK");

	if (ono::raw::Api_IsEnable() && e.type == MessageType::Group) {
		auto index = kmp::find(e.content, "����");
		if (index != kmp::npos)
		{
			double result = 0;
			if (rpn::calculate(rpn::make(e.content.c_str() + index), result))
			{
				ono::send_msg(e.botQQ, MessageType::Group, e.msgFrom, e.iTObj, ono::message().at(e.iTObj) << "Vs SDK���Լ�������" << std::to_string(result));
			}
			else
			{
				ono::send_msg(e.botQQ, MessageType::Group, e.msgFrom, e.iTObj, ono::message().at(e.iTObj) << "���ʽ��������������ı��ʽ�Ƿ������ұ�֤��������Ϊ0");
			}
		}
	}

});

//���û����¡����á�ִ�б�����
bind_set_up([]() {

});

//�������ж��ʱ�������
bind_destroy_plugin([]() {

});
}

