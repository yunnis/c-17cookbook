#pragma once
#include "base.h"

void _5_4()
{
    std::vector<int> v{ 1,2,3,4,5 };
    std::transform(begin(v), end(v), std::ostream_iterator<int>{std::cout, ", "}, [](int i) {return i* i; });
    std::cout << '\n';

    std::vector<std::string> vs;

    auto int_to_string([](int i) {
        std::stringstream ss;
        ss << std::format("{}^2 = {}", i, i * i);
        return ss.str();
        });
    std::transform(begin(v), end(v), back_inserter(vs), int_to_string);
    copy(begin(vs), end(vs), std::ostream_iterator<std::string>{std::cout, "\n"});
}
