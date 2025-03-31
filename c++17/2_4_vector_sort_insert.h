#include "base.h"

void insert_sorted(std::vector<int>& v, int i)
{
    const auto pos(lower_bound(begin(v), end(v), i));
    v.insert(pos, i);
}

void _2_4()
{
    std::vector<int> v{ 5,1,3,2,6 };
    // 怀疑import不能引入define
    //assert(false == is_sorted(begin(v), end(v)));
    std::sort(begin(v), end(v));
    //assert(true == is_sorted(begin(v), end(v)));
    insert_sorted(v, 0);
    insert_sorted(v, 4);
    print_vector(v);
}