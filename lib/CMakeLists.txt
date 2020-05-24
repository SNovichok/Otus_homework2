cmake_minimum_required(VERSION 3.2)

project(ip_address_lib VERSION 0.0.1)

add_library(ip_address ip_address.cpp ip_address.h)

set_target_properties(
    ip_address PROPERTIES
    CXX_STANDARD 17
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    ip_address
    PUBLIC
    ${CURRENT_BINARY_DIR}
)

if(MSVC)
    target_compile_options(ip_address PRIVATE /W4)
else()
    target_compile_options(
        ip_address
        PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()