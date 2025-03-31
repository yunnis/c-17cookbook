#pragma once
#include "base.h"

template <typename ...Ts>
static auto multicall(Ts ...functions)
{
    //return [=](auto x) {
    //    (void)std::initializer_list<int>{ // 包含一系列可调用函数
    //        ((void)functions(x), 0)...
    //    };
    //};
    // c++17 折叠表达式
    // 完美转发避免不必要的拷贝
    // 逗号运算符天然保证执行顺序
    // 消除临时initializer_list的内存开销
    return [=](auto&& x) {
        (functions(std::forward<decltype(x)>(x)), ...);
        };
}

template <typename F, typename ... Ts>
static auto for_each(F f, Ts ...xs)
{
    //(void)std::initializer_list<int>{
    //    ((void)f(xs), 0)... // xs 中的每个参数都传入 f 调用
    //};
    // c++17 折叠表达式

    (f(xs), ...);
}

static auto brace_print(char a, char b)
{
    return [=](auto x) {
        std::cout << std::format("{}{}{},", a, x, b);
        };
}

void _4_5()
{
    auto f(brace_print('(', ')'));
    auto g(brace_print('[', ']'));
    auto h(brace_print('{', '}'));
    auto nl([](auto) { std::cout << '\n'; });
    auto call_fgh(multicall(f, g, h, nl));
    for_each(call_fgh, 1,2,3,4,5);
}
