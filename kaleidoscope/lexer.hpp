#pragma once

#include <cstddef>
#include <iterator>
#include <string>
#include <string_view>
#include <variant>

struct Eof {};
struct Def {};
struct Extern {};
struct Ident {
    std::string name;
};
struct Number {
    double value;
};

using Token = std::variant<Eof, Def, Extern, Ident, Number>;

class Tokenizer {
   public:
    using difference_type = std::ptrdiff_t;
    using value_type = Token;
    // using iterator_concept = std::input_iterator_tag;

    Tokenizer() = default;
    Tokenizer(const Tokenizer&) = default;
    Tokenizer(std::string input);

    Token operator*() const;
    Tokenizer& operator++();
    Tokenizer operator++(int);
    bool operator==(const Tokenizer& other) const;

   private:
    Token current{};
    std::string_view rest{};

    std::pair<Token, std::string_view> tokenize(std::string_view input);
};

static_assert(std::forward_iterator<Tokenizer>);