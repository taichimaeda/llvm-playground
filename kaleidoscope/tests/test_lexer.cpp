#include <stdexcept>

#include "../lexer.hpp"
#include "acutest.h"

void test_hello() {
    TEST_ASSERT(1 == 1);
    // TEST_EXCEPTION(h.hello(nullptr), std::runtime_error);
    // TEST_ASSERT(h.hello() == "empty");
    // TEST_ASSERT(h.hello("") == "empty");
    // TEST_ASSERT(h.hello("John Doe") == "Hello John Doe");
}

TEST_LIST = {
    {"hello", test_hello},
    {nullptr, nullptr}};
