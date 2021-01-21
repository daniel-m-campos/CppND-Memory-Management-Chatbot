cmake_minimum_required(VERSION 3.11.3)

set(CMAKE_CXX_STANDARD 17)

project(Membot)

find_package(wxWidgets REQUIRED COMPONENTS core base)
include(${wxWidgets_USE_FILE})
include_directories(include)
file(GLOB project_SRCS src/*.cpp)

add_library(
        chatbot
        src/chatbot.cpp
        src/chatlogic.cpp
        src/graphnode.cpp
        src/graphedge.cpp
        src/chatgui.cpp
)
target_link_libraries(chatbot ${wxWidgets_LIBRARIES})
target_include_directories(chatbot PRIVATE ${wxWidgets_INCLUDE_DIRS})

set(BUILD_TESTS NO CACHE BOOL "Build test target")
if (BUILD_TESTS)
    add_subdirectory(tests)
endif ()

add_executable(membot src/main.cpp)
target_link_libraries(membot ${wxWidgets_LIBRARIES} chatbot)
target_include_directories(membot PRIVATE ${wxWidgets_INCLUDE_DIRS})
