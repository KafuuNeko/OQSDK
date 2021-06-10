#pragma once

#if defined(_MSC_VER)

 #define _OQ_EVENT(ReturnType, FuncName, ParamsSize)                                \
     __pragma(comment(linker, "/EXPORT:" #FuncName "=_" #FuncName "@" #ParamsSize)) \
     extern "C" __declspec(dllexport) ReturnType __stdcall FuncName

#else

#define _OQ_EVENT(ReturnType, FuncName, ParamsSize) \
    extern "C" __declspec(dllexport) ReturnType __stdcall FuncName

#endif

