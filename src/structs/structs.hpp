#pragma once
#include <iostream>
#include <vector>

struct Person {
    std::string name;
    int age;

    // Constructor
    Person(const std::string& n, int a) : name(n), age(a) {}
};

std::ostream& operator<<(std::ostream& os, const Person& person);

Person oldest(const std::vector<Person>& persons);

struct Team {
    std::string name;
    std::vector<Person> members;

    // Constructor
    Team(const std::string& n, const std::vector<Person>& ms) : name(n), members(ms) {}
};
std::ostream& operator<<(std::ostream& os, const Team& team);