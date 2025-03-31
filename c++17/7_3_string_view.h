#pragma once
#include "base.h"


void _print(std::string_view v)
{
    const auto words_begin(v.find_first_not_of(" \t\n"));
    v.remove_prefix(std::min(words_begin, v.size()));
    const auto words_end(v.find_last_not_of(" \t\n"));
    if (words_end != std::string_view::npos)
    {
        v.remove_suffix(v.size() - words_end - 1);
    }

    std::cout << std::format("length: {} [{}]\n", v.length(), v);
}

void _7_3()
{


    // 否则字面值操作符报错
    using namespace std::string_literals;
    using namespace std::string_view_literals;

    //print(argv[0]);
    _print({});
    _print("a const char * array");
    _print("an std::string_view literal"sv);
    _print("an std::string instance"s);
    _print(" \t\n foobar \n \t ");
    // 可是不需要终止符
    char cstr[]{ 'a', 'b', 'c' };
    _print(std::string_view(cstr, sizeof(cstr)));
}
