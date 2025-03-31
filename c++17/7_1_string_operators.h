#pragma once
#include "base.h"

void _7_1()
{
    // 否则字面值操作符报错
    using namespace std::string_literals; 
    using namespace std::string_view_literals; 
    std::string a{"a"};
    auto b ("b"s);
    std::string_view c {"c"};
    auto d("d"sv);
    std::cout << a << ", " << b << '\n';
    std::cout << c << ", " << d << '\n';
    std::cout << a + b << '\n';
    std::cout << a + std::string{ c } << '\n';

    // concat
    std::ostringstream o;
    o << std::format("{} {} {} {}", a, b, c, d);
    auto concatenated(o.str());
    std::cout << concatenated << '\n';
    transform(begin(concatenated), end(concatenated),
        begin(concatenated), ::toupper);
    std::cout << concatenated << '\n';
}
