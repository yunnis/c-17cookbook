#pragma once
#include "base.h"
#include <iostream>
#include <string>

class cat
{
    std::string name;
public:
    cat(std::string n) :name(n) {}
    void meow() const
    {
        std::cout << name << " says Meow!\n";
    }
};

class dog
{
    std::string name;
public:
    dog(std::string n) :name{ n } {}
    void woof() const
    {
        std::cout << name << " says Woof!\n";
    }
};

using animal = std::variant<dog, cat>;

template<typename T>
bool is_type(const animal& a)
{
    return holds_alternative<T>(a);
}

struct animal_voice
{
    void operator()(const dog& d) const { d.woof(); }
    void operator()(const cat& c) const { c.meow(); }
};

void _8_7()
{
    std::list<animal> l{ cat("Tuba"), dog{"Balou"}, cat{"Bobby"} };
    // 1
    for (const animal& a : l)
    {
        switch (a.index())
        {
        case 0:
            get<dog>(a).woof();
            break;
        case 1:
            get<cat>(a).meow();
            break;
        default:
            break;
        }
    }
    std::cout << "_______________\n";
    for (const animal& a : l)
    {
        if (const auto d(get_if<dog>(&a)); d)
        {
            d->woof();
        }
        else if (const auto c(get_if<cat>(&a)); c)
        {
            c->meow();
        }
    }
    std::cout << "_______________\n";
    // need operator()
    for (const animal& a : l)
    {
        visit(animal_voice{}, a);
    }
    std::cout << "_______________\n";
    std::cout << "There are "
        << count_if(begin(l), end(l), is_type<cat>)
        << " cats and "
        << count_if(begin(l), end(l), is_type<dog>)
        << " dogs in the list.\n";
    std::cout << "_______________\n";
}
