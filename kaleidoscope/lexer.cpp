#include "lexer.hpp"

Tokenizer::Tokenizer(std::string input) : rest{input} {
    std::tie(current, rest) = tokenize(rest);
}

Token Tokenizer::operator*() const {
    return current;
}

Tokenizer& Tokenizer::operator++() {
    std::tie(current, rest) = tokenize(rest);
    return *this;
}

Tokenizer Tokenizer::operator++(int n) {
    for (int i = 0; i < n; ++i) {
        ++(*this);
    }
    return *this;
}

std::pair<Token, std::string_view> Tokenizer::tokenize(std::string_view input) {
    if (input.empty()) {
        return {Eof{}, input};
    }

    if (isspace(input[0])) {
        auto it = std::find_if_not(input.begin(), input.end(), isspace);
        auto pos = static_cast<size_t>(it - input.begin());
        return tokenize(input.substr(pos));
    }

    if (isalpha(input[0])) {
        auto it = std::find_if_not(input.begin(), input.end(), isalpha);
        auto pos = static_cast<size_t>(it - input.begin());
        auto str = input.substr(0, pos);
        if (str == "def") {
            return {Def{}, input.substr(pos)};
        }
        if (str == "extern") {
            return {Extern{}, input.substr(pos)};
        }
        return {Ident{std::string{str}}, input.substr(pos)};
    }
}