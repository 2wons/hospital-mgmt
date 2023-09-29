cmake_minimum_required(VERSION 3.26)
project(Medicare)

set(CMAKE_CXX_STANDARD 17)

include_directories(include)


set(SOURCE_FILES
    src/main.cpp
    src/Console.cpp
    src/entity/Entity.cpp
    src/entity/Patient.cpp
    src/entity/Department.cpp
    src/entity/Record.cpp
    src/entity/Doctor.cpp
    src/entity/Item.cpp
)

add_executable(${PROJECT_NAME} ${SOURCE_FILES})
