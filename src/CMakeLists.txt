cmake_minimum_required(VERSION 3.2)

project(homework2 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

add_executable(ip_filter main.cpp)

set_target_properties(
    ip_filter PROPERTIES
    CXX_STANDARD 14
    CXX_STANDARD_REQUIRED ON
)

target_include_directories(
    ip_filter
    PRIVATE
    ${CMAKE_CURRENT_BINARY_DIR}
    ${CMAKE_CURRENT_SOURCE_DIR}/../lib
)

target_link_libraries(
    ip_filter 
    PRIVATE
    ip_address
)

if(MSVC)
    target_compile_options(ip_filter PRIVATE /W4)
else()
    target_compile_options(
        ip_filter PRIVATE
        -Wall -Wextra -pedantic -Werror
    )
endif()

install(TARGETS ip_filter RUNTIME DESTINATION bin)