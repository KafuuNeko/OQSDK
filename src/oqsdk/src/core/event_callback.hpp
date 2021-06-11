#pragma once

#include "inc_std.hpp"
#include "def_export_event.hpp"
#include "type.hpp"

#define INIT _OQ_EVENT(const char *, OQ_Create, 0)()

#define __PLUGIN_INIT__ ono::_init_api();

#define MAKE_PLUGIN_INFO(Name, Version, Author, Explain, Skey, Sdk)\
            "插件名称{"#Name"}\r\n"\
            "插件版本{"#Version"}\r\n"\
            "插件作者{"#Author"}\r\n"\
            "插件说明{"#Explain"}\r\n"\
            "插件skey{"#Skey"}\r\n"\
            "插件sdk{"#Sdk"}"

#define OQ_MESSAGE _OQ_EVENT(ono::Dispose, OQ_Message, 24)(\
    const char * qq, \
    int32_t type, \
    const char * original, \
    const char * cookie, \
    const char * sessionKey, \
    const char * clientKey\
)

#define OQ_Event _OQ_EVENT(ono::Dispose, OQ_Event, 48)(\
    const char * botQQ, \
    ono::MessageType type, \
    ono::MessageType subType, \
    const char *msgFrom, \
    const char *iTObj, \
    const char *pTObj, \
    const char *content, \
    const char *msgSerial, \
    const char *msgId, \
    const char *original, \
    const char *remittance, \
    void * callback\
)

#define OQ_SetUp _OQ_EVENT(void, OQ_SetUp, 0)()

#define OQ_DestroyPlugin _OQ_EVENT(int32_t, OQ_DestroyPlugin, 0)()

