include(FetchContent)
FetchContent_Declare(
        catch
        GIT_REPOSITORY https://github.com/catchorg/Catch2.git
        GIT_TAG v2.x
)
FetchContent_MakeAvailable(catch)

add_executable(test test.cpp)
target_link_libraries(test Catch2 chatbot)

configure_file(${CMAKE_SOURCE_DIR}/images/chatbot.png
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)