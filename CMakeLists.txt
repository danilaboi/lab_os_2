cmake_minimum_required(VERSION 3.10)
project(lab_os_2 CXX)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# ����������� ��������� ����� ��������, ����� �������� ������ CRT
set(CMAKE_MSVC_RUNTIME_LIBRARY "MultiThreadedDebugDLL")  # ���������� /MDd

# ���������� GoogleTest ����� FetchContent (�������������� ��������)
include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/release-1.12.1.zip
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)  # ��� ���������� ������� CRT
FetchContent_MakeAvailable(googletest)

# ��������� include, ����� CMake ����� functions.h
include_directories(src)

# ������ ����������� ���� ��� �������� ���������
add_executable(laba_os_2 src/main.cpp src/functions.cpp)

# ���������� ����� � �������
add_subdirectory(tests)
enable_testing()
add_test(NAME AllTests COMMAND tests)