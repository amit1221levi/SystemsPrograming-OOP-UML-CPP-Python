#ifndef EX4_EXCEPTIONS_H
#define EX4_EXCEPTIONS_H

#include <iostream>
#include <string>

class DeckFileNotFound: public std::logic_error{
public:
    DeckFileNotFound() : std::logic_error("Deck File Error: File Not Found"){}
};

class DeckFileFormatError: public std::runtime_error{
public:
    explicit DeckFileFormatError(int line):
            std::runtime_error("Deck File Error: File format error in line " + std::to_string(line)){}
};

class DeckFileInvalidSize: public std::runtime_error{
public:
    DeckFileInvalidSize(): std::runtime_error("Deck File Error: Deck size is invalid"){}
};


#endif //EX4_EXCEPTIONS_H