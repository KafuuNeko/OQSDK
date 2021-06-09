#pragma once

// #define _OQ_EVENT(ReturnType, FuncName, ParamsSize)                                                                 \
//     __pragma(comment(linker, "/EXPORT:" #FuncName "=_" #FuncName "@" #ParamsSize)) extern "C" __declspec(dllexport) \
//         ReturnType __stdcall FuncName

#define _OQ_EVENT(ReturnType, FuncName) extern "C" __declspec(dllexport) ReturnType __stdcall FuncName

