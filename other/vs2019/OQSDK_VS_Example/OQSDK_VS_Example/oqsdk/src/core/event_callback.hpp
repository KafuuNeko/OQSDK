#pragma once

#include "inc_std.hpp"
#include "type.hpp"
#include "event.hpp"

#define DEF_EVENT(EventName, EventType)                                             \
    inline auto &_##EventName##_callbacks() {                                       \
        static std::vector<std::function<void(EventType)>> EventName##callbacks;    \
        return EventName##callbacks;                                                \
    }                                                                               \
    inline void bind_##EventName(const std::function<void(EventType)> &cb) {        \
        _##EventName##_callbacks().push_back(cb);                                   \
    }

DEF_EVENT(original_packet, ono::OriginalPacketEvent&);
DEF_EVENT(message, ono::MessageEvent&);
DEF_EVENT(set_up, void);
DEF_EVENT(destroy_plugin, void);

#undef DEF_EVENT

