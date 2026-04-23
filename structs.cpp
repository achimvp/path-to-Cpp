#include <iostream>
#include <string>
#include <vector>

#include "utils.hpp"

utils::Person oldest(const std::vector<utils::Person>& persons) {
    utils::Person oldest = persons.front();
    for(const auto& person:persons){
        if(person.age > oldest.age){
            oldest = person;
        }
    }
    return oldest;
}


int main(){
    std::vector<utils::Person> persons = {{"Bob", 140},{"Pete", 10},{"Alice", 100}};
    utils::Person oldestPerson = oldest(persons);
    std::cout << "Oldest person: " << oldestPerson << std::endl;
    utils::printVector(persons);
    utils::Person pete("Pete", 16);
    std::cout << pete << std::endl;

    utils::Team team("Super Team", persons);
    std::cout << team << std::endl;
}
