// Aufgabe 1
#include <iostream>
#include <string>
#include <vector>
#include "utils.hpp"

void aufgabe1() {
    std::cout << "Aufgabe 1: Auto Keyword" << std::endl;
    auto number = 42;
    auto floatNumber = 3.14;
    auto booleanValue = true;
    std::cout << "Integer: " << number << std::endl;
    std::cout << "Float: " << floatNumber << std::endl;
    std::cout << "Boolean: " << booleanValue << std::endl;
}

void aufgabe2() {
    std::cout << "Aufgabe 2: Auto Keywords mit Strings" << std::endl;
    auto str1 = "Hello";
    auto str2 = std::string("World");
    std::cout << typeid(str1).name() << ": " << str1 << std::endl;
    std::cout << typeid(str2).name() << ": " << str2 << std::endl;
}



void aufgabe3() {
    std::cout << "Aufgabe 3: Auto Keyword with Range-Based For Loop" << std::endl;
    std::vector<std::string> names = {"alice", "bob", "charlie", "david", "eve"};

    std::cout << "Names before modification:" << std::endl;
    for (const auto name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;

    for (auto& name : names) {
        for (auto& c : name) {
            c = std::toupper(c);
        }
    }

    std::cout << "Names after modification:" << std::endl;
    for (const auto name : names) {
        std::cout << name << " ";
    }
    std::cout << std::endl;
}

void capitalize(std::vector<std::string>& words){
    for(auto& word:words){
        word[0] = std::toupper(word[0]);
    }
}

std::vector<std::string> capitalized(const std::vector<std::string>& words){
    std::vector<std::string> capitalizedWords {};
    for(const auto& word:words){
        capitalizedWords.push_back(word);
        capitalizedWords.back()[0] = std::toupper(capitalizedWords.back()[0]);
    }    
    return capitalizedWords;
}

template <typename T>
T maximum(T a, T b){
    if(a > b){
        return a;
    } else {
        return b;
    }
}

int main() {
    aufgabe1();
    aufgabe2();
    aufgabe3();
    std::vector<std::string> words = {"one", "alice", "test", "pawn"};
    // capitalize(words);
    auto capitalizedWords = capitalized(words);
    utils::printVector(capitalizedWords);
    std::vector<int> numbers = {1,2,3,4,5};
    utils::printVector(numbers);

    int a = 1, b = 2;
    std::cout << "Maximum von " << a << " und " << b << " ist: " << maximum(a,b) << std::endl;

    float c = 1.3, d = 4.6;
    std::cout << "Maximum von " << c << " und " << d << " ist: " << maximum(c,d) << std::endl;

    return 0;
}
