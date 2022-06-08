#include <iostream>
#include <string>
#include <nlohmann/json.hpp>

struct Person
{
    std::string name;
    int age;
};

int main()
{
    Person p{ "LX", 20 };
    nlohmann::json j{};
    j["name"] = p.name;
    j["age"] = p.age;
    std::cout << j << std::endl;

    std::string serilizedString = j.dump();
    Person p1{};
    nlohmann::json j1 = nlohmann::json::parse(serilizedString);
    p1.name = j1["name"].get<std::string>();
    p1.age = j1["age"].get<int>();
}
