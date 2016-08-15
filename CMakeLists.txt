cmake_minimum_required(VERSION 3.3)
project(Snake)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES
    intern/compiler/main.cpp
    intern/src/application/app_game_state.cpp
    intern/src/application/app_main.cpp
    intern/src/application/app_startup_state.cpp
    intern/src/application/app_state.cpp
    intern/src/application/main.cpp
    Field.cpp
    Game.cpp
    main.cpp
    Snake.cpp
    View.cpp)

add_executable(Snake ${SOURCE_FILES})