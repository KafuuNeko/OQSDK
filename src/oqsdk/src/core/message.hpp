#pragma once

#include "inc_std.hpp"

namespace ono 
{

struct message
{
    
    std::stringstream ss_;

    message(const message & rhs) noexcept
    {
        ss_ << rhs.ss_.str();
    }

    message &operator=(const message & rhs)
    {
        ss_.clear();
        ss_ << rhs.ss_.str();

        return *this;
    }

    message() = default;


    template<class T>
    inline message& append(const T &content) noexcept
    {
        ss_ << content;
        return *this;
    }

    inline message& at(const std::string &obj = "全体人员") noexcept
    {
        return append("[@").append(obj).append(']');
    }

    inline message& face(int32_t code) noexcept
    {
        return append("[Face").append(code).append(".gif]");
    }

    inline message& emoji(const std::string &code) noexcept
    {
        return append("[emoji=").append(code).append(']');
    }

    inline message& pic(const std::string &img) noexcept
    {
        return append("[pic=").append(img).append(']');
    }

    template<class T>
    message& operator<<(const T &content) noexcept
    {
        return append(content);
    }

    operator std::string() const noexcept
    {
        return ss_.str();
    }
};

}
 

