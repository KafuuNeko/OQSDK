#pragma once

#include <Windows.h>
#include <assert.h>
#include <inttypes.h>
#include <string>


namespace ono 
{

    namespace raw 
    {
        #define OQApi(ReturnType, FuncName, ...) static ReturnType(__stdcall *Api_##FuncName)(__VA_ARGS__) = nullptr;
        
        #include "./api_funcs.inc"

        #undef OQApi
    }

    void _init_api()
    {
        const auto dll = GetModuleHandleW(L"OQapi.dll");

        #define OQApi(ReturnType, FuncName, ...) raw::Api_##FuncName = reinterpret_cast<decltype(raw::Api_##FuncName)>(GetProcAddress(dll, "Api_" #FuncName));

        #include "./api_funcs.inc"
        
        #undef OQApi
    }

}

