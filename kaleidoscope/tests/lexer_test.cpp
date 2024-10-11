#include "../lexer.hpp"

#include <gtest/gtest.h>

#include <iostream>
#include <stdexcept>
#include <string>
#include <variant>

// Demonstrate some basic assertions.
TEST(LexerTest, BasicAssertions) {
    std::string input{"def foo 42"};

    for (Tokenizer it{input}; !std::holds_alternative<Eof>(*it); ++it) {
        Token token = *it;
        if (auto def = std::get_if<Def>(&token)) {
            std::cout << "Def" << std::endl;
            continue;
        } else if (auto ident = std::get_if<Ident>(&token)) {
            std::cout << "Ident: " << ident->name << std::endl;
            continue;
        } else if (auto number = std::get_if<Number>(&token)) {
            std::cout << "Number: " << number->value << std::endl;
            continue;
        }
        FAIL() << "Unexpected character";
    }
}