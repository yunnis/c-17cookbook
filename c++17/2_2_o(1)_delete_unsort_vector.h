#include "base.h"

template <typename T>
void quick_remove_at(std::vector<T>& v, std::size_t idx)
{
    if (idx < v.size())
    {
        v[idx] = std::move(v.back());
        v.pop_back();
    }
}

template <typename T>
void quick_remove_at(std::vector<T>& v, typename std::vector<T>::iterator it)
{
    if (it != std::end(v))
    {
        *it = std::move(v.back());
        v.pop_back();
    }
}

void _2_2()
{
    std::vector<int> v{123, 456, 789, 100, 200};

    quick_remove_at(v, 2);
    print_vector(v);

    quick_remove_at(v, std::find(std::begin(v), std::end(v), 123));
    print_vector(v);
}