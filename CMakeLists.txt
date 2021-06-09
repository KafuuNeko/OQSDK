cmake_minimum_required(VERSION 3.9)
project(Example)

include_directories(src)

#设置使用C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

#确保 Win32 环境下存在 WIN32 定义
if (WIN32)
    add_definitions(-DWIN32) 
endif ()

#必须是32位的
set(CMAKE_C_FLAGS "-m32 -fexec-charset=GBK")
set(CMAKE_CXX_FLAGS "-m32 -fexec-charset=GBK")

#强制静态链接并取消输出函数@后缀
set(CMAKE_SHARED_LINKER_FLAGS "-static -Wl,--kill-at,--enable-stdcall-fixup")

aux_source_directory(./src/example DIR_TOOT_SRCS)

add_library(Example SHARED ${DIR_TOOT_SRCS})
