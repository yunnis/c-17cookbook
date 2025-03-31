#pragma once
#include "base.h"

struct city 
{
    std::string name;
    size_t population;
    double latitude;
    double longitude;
};

// 要通过流读city, 只需要重写 operator >>
std::istream& operator>> (std::istream& is, city &c)
{
    is>>std::ws;
    std::getline(is, c.name);
    is >> c.population >> c.latitude>>c.longitude;
    return is;
}

//$ cat cities.txt| ./initialize_complex_objects
void _7_7()
{
    std::vector<city> l;
    std::copy(std::istream_iterator<city>{std::cin}, {}, std::back_inserter(l));
    for (const auto &[name, pop, lat, lon] : l)
    {
        std::cout << std::left << std::setw(15)
            << std::format("{} population={} lat={} lon={}",
                    name, pop, lat, lon);

    }
}
