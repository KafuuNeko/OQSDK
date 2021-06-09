#pragma once

#include <inttypes.h>
#include "def_export_event.hpp"
#include "factory.hpp"

#define INIT _OQ_EVENT(const char *, OQ_Create)()

#define OQ_MESSAGE _OQ_EVENT(Dispose, OQ_Message)(\
    const char * qq, \
    int32_t type, \
    const char * original, \
    const char * cookie, \
    const char * sessionKey, \
    const char * clientKey\
)

#define OQ_Event _OQ_EVENT(Dispose, OQ_Event)(\
    const char * botQQ, \
    int32_t type, \
    int32_t subType, \
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

#define OQ_SetUp _OQ_EVENT(void, OQ_SetUp)()

#define OQ_DestroyPlugin _OQ_EVENT(int32_t, OQ_DestroyPlugin)()