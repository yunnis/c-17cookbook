#pragma once
#include "base.h"

template <typename M>
void print(const M& m)
{
    std::cout << std::format("Race placement:\n");
    for (auto& [placement, driver] : m)
    {
        std::cout << std::format("{} : {}\n", placement, driver);
    }
}

void _2_7()
{
    std::map<int, std::string> race_placement{
    {1, "Mario"}, {2, "Luigi"}, {3, "Bowser"},
    {4, "Peach"}, {5, "Yoshi"}, {6, "Koopa"},
    {7, "Toad"}, {8, "Donkey Kong Jr."}
    };
    print(race_placement);

    // c++17 ɾ��Ԫ�� û���ڴ��ط���
    auto a(race_placement.extract(3));
    auto b(race_placement.extract(8));
    // ��Ҫ�п�, Ҳ���Խ��ý�������map
    assert(!a.empty() && !b.empty());
    std::swap(a.key(), b.key());
    // c++17  ������ȡ�Ľ��, ��������ڴ�
    race_placement.insert(move(a));
    race_placement.insert(move(b));
    print(race_placement);
}
