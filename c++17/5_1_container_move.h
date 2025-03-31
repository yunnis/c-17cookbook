#pragma once
#include "base.h"

using _data = std::pair<int, std::string>;
namespace std
{
    ostream& operator <<(ostream& os, const _data& p)
    {
        return os << std::format("({}, {})", p.first, p.second);
    }
}

void _5_1()
{
    std::vector<_data> v{ {1, "one"}, {2, "two"}, {3, "three"}, {4, "four"}, {5, "five"} };
    std::map<int, std::string> m;

    copy_n(begin(v), 3, inserter(m, begin(m)));
    // copy() 经常用于打印容器
    auto shell_it(std::ostream_iterator<_data>{std::cout, ", " });

    // c++20 lambda 支持模板
    //auto print_container = [&shell_it]<typename Container>(Container c) {
    //    copy(begin(c), end(c), shell_it);
    //};

    auto print_container = [&shell_it](auto c) {
        copy(begin(c), end(c), shell_it);
        std::cout << '\n';
    };
    print_container(m);

    m.clear();
    // 内存还没回收, 但内存上的内容都没了
    move(begin(v), end(v), inserter(m, begin(m)));
    print_container(m);
    print_container(v);
}
