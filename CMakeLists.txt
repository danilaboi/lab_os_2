cmake_minimum_required(VERSION 3.10)
project(lab_os_2 CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ОБЯЗАТЕЛЬНО указываем режим линковки, чтобы избежать ошибок CRT
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")  # Используем /MDd

# Подключаем GoogleTest через FetchContent (автоматическая загрузка)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # Для устранения проблем CRT
FetchContent_MakeAvailable(googletest)

# Добавляем include, чтобы CMake видел functions.h
include_directories(src)

# Создаём исполняемый файл для основной программы
add_executable(laba_os_2 src/main.cpp src/functions.cpp)

# Подключаем папку с тестами
add_subdirectory(tests)
enable_testing()
add_test(NAME AllTests COMMAND tests)