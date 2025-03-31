#pragma once
#include "base.h"

template <typename T, typename ...Ts>
auto concat(T t, Ts ...ts)
{
    if constexpr (sizeof...(ts) > 0)
    {
        return [=](auto ...parameters)
            {
                return t(concat(ts...)(parameters...));
            };
    }
    else
    {
        return t;
    }
}

void _4_3()
{
    auto twice([](int i) {return i * 2; });
    auto thrice([](int i) {return i * 3; });

    auto combined(concat(twice, thrice, std::plus<int>{}));
    std::cout << combined(2, 3);
}
