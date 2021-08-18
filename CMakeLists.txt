cmake_minimum_required(VERSION 3.19)
project(CotecchioPlayer)

set(CMAKE_CXX_STANDARD 17)

file(GLOB_RECURSE common "common/*.cpp" "common/*.hpp")
file(GLOB_RECURSE lib "lib/*.cpp" "lib/*.hpp")
file(GLOB_RECURSE math "math/*.cpp" "math/*.hpp")
file(GLOB_RECURSE network "network/*.cpp" "network/*.hpp")
file(GLOB_RECURSE xml "xml/*.cpp" "xml/*.hpp")
file(GLOB root "*.hpp" "*.cpp")

add_executable(${PROJECT_NAME}
        ${common}
        ${lib}
        ${math}
        ${network}
        ${xml}
        ${root}
)

target_include_directories(${PROJECT_NAME} PUBLIC "./lib")
target_include_directories(${PROJECT_NAME} PUBLIC "math/matrix")
target_include_directories(${PROJECT_NAME} PUBLIC "math/vector")

if (WIN32)
    target_link_libraries(${PROJECT_NAME} ws2_32)

    if (MSVC)
        # TODO to be tested
        add_compile_definitions(__PRETTY_FUNCTION__=__FUNCSIG__)
    endif()
endif()

file(COPY "settings.xml" DESTINATION "${CMAKE_BINARY_DIR}")
file(COPY "languages" DESTINATION "${CMAKE_BINARY_DIR}")