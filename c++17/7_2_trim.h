#pragma once
#include "base.h"
#include <cstddef>
#include <string>

std::string trim_rl(const std::string& s)
{
    const char whitespace[] {" \t\n"};
    const size_t first(s.find_first_not_of(whitespace));
    if (std::string::npos == first)
    {
        return {};
    }

    const size_t last(s.find_last_not_of(whitespace));
    return s.substr(first, last - first + 1);
}


void _7_2() 
{
    std::string s {" \t\n  string surrounded by ugly"
                    " whitespace \t\n  "};
    // format out put { : {{
    std::cout << std::format("{{{}}}\n{{{}}}", s, trim_rl(s));
}

