#include "structs.hpp"

int main() {
    std::vector<Person> persons = {{"Bob", 140}, {"Pete", 10}, {"Alice", 100}};
    Person oldestPerson = oldest(persons);
    std::cout << "Oldest person: " << oldestPerson << std::endl;
    Person pete("Pete", 16);
    std::cout << pete << std::endl;

    Team team("Super Team", persons);
    std::cout << team << std::endl;
}