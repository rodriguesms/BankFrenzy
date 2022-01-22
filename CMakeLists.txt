cmake_minimum_required(VERSION 3.21)
project(BankFrenzy)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt6 COMPONENTS
        Core
        REQUIRED)

add_executable(BankFrenzy main.cpp src/dice_management.h)
target_link_libraries(BankFrenzy
        Qt::Core
        )

