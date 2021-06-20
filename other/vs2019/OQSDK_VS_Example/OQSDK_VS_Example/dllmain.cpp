// dllmain.cpp : 定义 DLL 应用程序的入口点。
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
	OQSDK_VS_Example, //插件名称
	1:0 : 0, //插件版本
	KafuuNeko, //插件作者
	OQSDK C++ SDK, //插件说明
	8956RTEWDFG3216598WERDF3, //Skey 
	S3 //SDK版本
);

APP_CREATE
{
	//接收所有原始封包内容
	bind_original_packet([](ono::OriginalPacketEvent& e) {

	});

//分发OQ_机器人QQ接收到的所有：事件，消息；您可在此函数中自行调用所有参数
bind_message([](ono::MessageEvent& e) {
	ono::raw::Api_OutPutLog("C++SDK");

	if (ono::raw::Api_IsEnable() && e.type == MessageType::Group) {
		auto index = kmp::find(e.content, "计算");
		if (index != kmp::npos)
		{
			double result = 0;
			if (rpn::calculate(rpn::make(e.content.c_str() + index), result))
			{
				ono::send_msg(e.botQQ, MessageType::Group, e.msgFrom, e.iTObj, ono::message().at(e.iTObj) << "Vs SDK测试计算结果：" << std::to_string(result));
			}
			else
			{
				ono::send_msg(e.botQQ, MessageType::Group, e.msgFrom, e.iTObj, ono::message().at(e.iTObj) << "表达式错误，请检查您输入的表达式是否有误，且保证除数不能为0");
			}
		}
	}

});

//当用户按下“设置”执行本函数
bind_set_up([]() {

});

//当插件被卸载时将会调用
bind_destroy_plugin([]() {

});
}

