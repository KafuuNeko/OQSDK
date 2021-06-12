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

set(CPPSDK_SRC_DIR ./src/oqsdk/src)

set(PROJECT_DIR ./src/example)

# 递归搜索 core 和 utils 中的源文件
file(GLOB_RECURSE _SOURCE_FILES ${PROJECT_DIR}/*.cpp ${CPPSDK_SRC_DIR}/core/*.cpp ${CPPSDK_SRC_DIR}/utils/*.cpp)

add_library(Example SHARED ${_SOURCE_FILES})

set_target_properties(Example PROPERTIES PREFIX "") # 去除 lib 前缀
set_target_properties(Example PROPERTIES SUFFIX ".OQ.dll") # 添加后缀