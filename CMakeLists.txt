cmake_minimum_required(VERSION 3.10)

project(test_app)

find_package(fmt REQUIRED)
find_package(spdlog REQUIRED)

add_executable( ${CMAKE_PROJECT_NAME} 
    src/application.cpp
    src/main.cpp)

set_target_properties(${CMAKE_PROJECT_NAME} PROPERTIES
    CXX_STANDARD 20
)

target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE FMT_HEADER_ONLY) 
target_compile_definitions(${CMAKE_PROJECT_NAME} PRIVATE SPDLOG_FMT_EXTERNAL)
target_include_directories(${CMAKE_PROJECT_NAME} 
    PUBLIC
        include
    PRIVATE 
        ${fmt_INCLUDE_DIRS}
        ${spdlog_INCLUDE_DIRS}
    )
target_link_libraries(${CMAKE_PROJECT_NAME} spdlog::spdlog)