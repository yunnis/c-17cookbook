#include "base.h"

void _2_1()
{
    std::vector<int> v{ 1,2,3,2,5,6,2,4,8 };
    const auto new_end(remove(begin(v), end(v), 2));
    std::cout << std::format("remove cap: {}, size: {}\n", v.capacity(), v.size());
    print_vector(v);

    v.erase(new_end, end(v));
    
    // c++20
    std::cout << std::format("erase cap: {}, size: {}\n", v.capacity(), v.size());
    print_vector(v);
    // c++ 23
    //std::print("{1}ok", 23);
    //std::println("{1}ok", 23);

    const auto odd([](int i) {return i % 2 != 0; });
    // 如果不用变量, erase会触发越界异常
    auto n_ned = (remove_if(begin(v), end(v), odd));
    std::cout << std::format("remove_if & erase cap: {}, size: {}\n", v.capacity(), v.size());
    print_vector(v);
    v.erase(n_ned, end(v));

    std::cout << std::format("remove_if & erase cap: {}, size: {}\n", v.capacity(), v.size());
    print_vector(v);

    v.shrink_to_fit();
    std::cout << std::format("after shrink cap: {}, size: {}\n", v.capacity(), v.size());
}
