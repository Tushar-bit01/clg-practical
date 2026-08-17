cmake_minimum_required(VERSION 3.20)

project(StudentFeedback)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(
    SFML 3
    REQUIRED
    COMPONENTS
        Graphics
        Window
        System
)

add_executable(
    student_feedback

    src/main.cc
    src/App.cc
    src/Button.cc
    src/Rating.cc
    src/TextInput.cc
    src/UI.cc
    src/Theme.cc
)

target_include_directories(
    student_feedback
    PRIVATE
        ${PROJECT_SOURCE_DIR}/include
)

target_link_libraries(
    student_feedback
    PRIVATE
        SFML::Graphics
        SFML::Window
        SFML::System
)