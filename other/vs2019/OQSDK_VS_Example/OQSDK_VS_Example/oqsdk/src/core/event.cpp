#include "event.hpp"
#include "event_callback.hpp"
#include "def_export_event.hpp"
#include "api.hpp"
#include "inc_std.hpp"

template<class _Cont, class... _Args>
void _call_all(const _Cont &callbacks, _Args &&... args)
{
    for(auto & callback : callbacks)
    {
        if(callback)
            callback(std::forward<_Args>(args)...);
    }
}

_OQ_EVENT(const char *, OQ_Create, 0)()
{
    ono::_init_api();
    ono::app_create();
    return ono::app_info();
}

_OQ_EVENT(ono::Dispose, OQ_Message, 24)(
    const char * qq,
    int32_t type,
    const char * original,
    const char * cookie,
    const char * sessionKey, 
    const char * clientKey)
{
    ono::OriginalPacketEvent event(qq, original, cookie, sessionKey, clientKey, type);

    _call_all(_original_packet_callbacks(), event);

    return event.result;
}

_OQ_EVENT(ono::Dispose, OQ_Event, 48)(
    const char * botQQ,
    ono::MessageType type,
    ono::MessageType subType,
    const char *msgFrom,
    const char *iTObj,
    const char *pTObj,
    const char *content,
    const char *msgSerial,
    const char *msgId,
    const char *original,
    const char *remittance,
    void * callback)
{
    ono::MessageEvent event(botQQ, type, subType, msgFrom, iTObj, pTObj, content, msgSerial, msgId, original, remittance, callback);

    _call_all(_message_callbacks(), event);

    return event.result;
}

_OQ_EVENT(void, OQ_SetUp, 0)()
{
    _call_all(_set_up_callbacks());
}

_OQ_EVENT(int32_t, OQ_DestroyPlugin, 0)()
{
    _call_all(_destroy_plugin_callbacks());
    return 1;
}
