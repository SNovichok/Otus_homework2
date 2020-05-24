cmake_minimum_required(VERSION 3.2)

#project(homework2 VERSION 0.0.$ENV{TRAVIS_BUILD_NUMBER})

if("$ENV{TRAVIS_BUILD_NUMBER}" STREQUAL "")
set(VERSION_NUMBER "0.0.42")
else()
set(VERSION_NUMBER "0.0.$ENV{TRAVIS_BUILD_NUMBER}")
endif()

project(ip_filter VERSION ${VERSION_NUMBER})

add_subdirectory(src)
add_subdirectory(lib)
add_subdirectory(test)

set(CPACK_GENERATOR DEB)
set(CPACK_PACKAGE_VERSION_MAJOR "${PROJECT_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${PROJECT_VERSION_MINOR}")
set(CPACK_PACKAGE_VERSION_PATCH "${PROJECT_VERSION_PATCH}")
set(CPACK_PACKAGE_CONTACT example@example.com)
include(CPack)

enable_testing()

add_test(test_sort ${CMAKE_BINARY_DIR}/test/test_sort)

