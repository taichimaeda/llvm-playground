enable_testing()

add_executable(lexer_test lexer_test.cpp ../lexer.cpp)

add_dependencies(lexer_test main)
target_link_libraries(lexer_test GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(lexer_test)