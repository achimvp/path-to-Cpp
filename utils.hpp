#pragma once
#include <iostream>
#include <vector>

namespace utils
{

template <typename T>
void printVector(const std::vector<T>& elements){
    for(const auto& element:elements){
        std::cout << element << " ";
    }
    std::cout << std::endl;
}

struct Person
{
    std::string name;
    int age;

    // Constructor
    Person(const std::string& n, int a) : name(n), age(a) {}
};

std::ostream& operator<<(std::ostream& os, const Person& person){
    os << "Name: " << person.name << "\tAge: " << person.age;
    return os;
}

struct Team
{
    std::string name;
    std::vector<Person> members;

    // Constructor
    Team(const std::string& n, const std::vector<Person>& ms) : name(n), members(ms) {}
};
std::ostream& operator<<(std::ostream& os, const Team& team){
    os << "Teamname: " << team.name << "\n";
    for (const auto& member: team.members){
        os << " " << member << "\n";
    }
    return os;
}
    
} // namespace utils

