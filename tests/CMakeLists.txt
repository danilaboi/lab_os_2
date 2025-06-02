add_executable(tests test_functions.cpp)

# Добавляем functions.cpp, чтобы тесты знали о его реализации
target_sources(tests PRIVATE ../src/functions.cpp)

target_link_libraries(tests gtest gtest_main)

include(GoogleTest)
gtest_discover_tests(tests)
