cmake_minimum_required(VERSION 3.10...4.0)
project(nive C)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

file(GLOB_RECURSE SOURCES CONFIGURE_DEPENDS
    "${CMAKE_SOURCE_DIR}/src/*.c"
    "${CMAKE_SOURCE_DIR}/src/*.h"
)

add_executable(nive ${SOURCES})

target_include_directories(nive PRIVATE "${CMAKE_SOURCE_DIR}/src")

if(MSVC)
    target_compile_options(nive PRIVATE
        /W4
        /permissive-
    )
    target_compile_options(nive PRIVATE $<$<CONFIG:Release>:/O2 /Oi /Ot>)
else()
    target_compile_options(nive PRIVATE
        -Wextra -Wpedantic
        -Wshadow
        -Wdouble-promotion
        -Wformat=2
    )
    target_compile_options(nive PRIVATE 
        $<$<CONFIG:Release>:
            -O3
            -march=native
            -funroll-loops
            -fno-plt
        >
    )
    target_link_options(nive PRIVATE $<$<CONFIG:Release>:-flto>)
    target_compile_options(nive PRIVATE $<$<CONFIG:Release>:-flto>)
    target_compile_options(nive PRIVATE 
        $<$<CONFIG:Debug>:
            -O0 -g3
            -fstack-protector-strong
            # -fsanitize=address
            # -fsanitize=undefined
            -fno-omit-frame-pointer
        >
    )
    # target_link_options(nive PRIVATE 
        # $<$<CONFIG:Debug>:-fsanitize=address,undefined>
    # )
endif()