#include <iostream>
#include <string>
#include <vector>
#include <nlohmann/json.hpp>

struct Person
{
    std::string name;
    int age;
};

struct myAnswer
{
    int everything;
};

struct myObject
{
    std::string currency;
    double value;
};

struct myStruct
{
    float pi;
    bool happy;
    std::string name;
    void* nothing;
    myAnswer answer;
    std::vector<int> list;
    myObject object;
};

//void to_json(nlohmann::json& j, const Person& p)
//{
//    j = nlohmann::json{ {"name", p.name}, {"age", p.age} };
//}
//
//void from_json(const nlohmann::json& j, const Person& p)
//{
//    j.at("name").get_to(p.name);
//    j.at("age").get_to(p.age);
//}

int main()
{
    // #1
    //Person p{ "LX", 20 };
    //nlohmann::json j{};
    //j["name"] = p.name;
    //j["age"] = p.age;
    //std::cout << j << std::endl;

    //std::string serilizedString = j.dump();
    //Person p1{};
    //nlohmann::json j1 = nlohmann::json::parse(serilizedString);
    //p1.name = j1["name"].get<std::string>();
    //p1.age = j1["age"].get<int>();
    //Person p{};
    //nlohmann::json j = p;


    // #2
    /*
    {
        "pi": 3.141,
            "happy" : true,
            "name" : "Niels",
            "nothing" : null,
            "answer" : {
            "everything": 42
        },
            "list" : [1, 0, 2] ,
                "object" : {
                "currency": "USD",
                    "value" : 42.99
            }
    }
    */

    nlohmann::json j{};
    j["pi"] = 3.141;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42;
    j["list"] = { 1,0,2 };
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };

    myStruct obj{};
    obj.pi = j["pi"].get<float>();
    obj.happy = j["happy"].get<bool>();
    obj.name = j["name"].get<std::string>();
    obj.nothing = j["nothing"].get_ptr<nlohmann::json::object_t*>();
    obj.answer = myAnswer{ j["answer"]["everything"].get<int>() };
    j["list"].get_to<std::vector<int>>(obj.list);
    obj.object = myObject{ j["object"]["currency"].get<std::string>(), j["object"]["value"].get<double>() };
}