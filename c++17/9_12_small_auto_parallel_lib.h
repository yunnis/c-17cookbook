#pragma once
#include "base.h"

using namespace std::chrono_literals;

static std::string create(const char* s)
{
    //pcout{} << "3s CREATE " << std::quoted(s) << '\n';
    pcout{} << std::format("3s CREATE \"{}\"\n", s);  // 手动加引号
    std::this_thread::sleep_for(3s);
    return { s };
}
static std::string concat(const std::string& a, const std::string & b)
{
    pcout{} << std::format("3s CREATE \"{}\" \"{}\"\n", (a), (b));
    std::this_thread::sleep_for(5s);
    return a + b;
}
static std::string twice(const std::string& s)
{
    pcout{} << "3s TWICE " << quoted(s) << '\n';
    std::this_thread::sleep_for(3s);
    return s + s;
}

template<typename F>
static auto asynchronize(F f)
{
    return [f](auto ... xs) {
        return [=]() {
            return std::async(std::launch::async, f, xs...);
            };
        };
}
template<typename F>
auto asynchronize_ds(F&& f)
{ // 改用万能引用
    return [f = std::forward<F>(f)](auto&&... xs) {
        return std::async(std::launch::async, f, std::forward<decltype(xs)>(xs)...);
        };
}

template <typename F>
static auto fut_unwrap(F f)
{
    return [f](auto ... xs) {
        return f(xs.get()...);
        };
}
template<typename F>
auto fut_unwrap_ds(F&& f) 
{ // 改用万能引用
    return [f = std::forward<F>(f)](auto&&... futures) {
        // 使用折叠表达式展开get()
        return std::invoke(f, (futures.get())...);
        };
}

template <typename F>
static auto async_adapter(F f)
{
    return [f](auto ... xs) {
        return [=]() {
            return std::async(std::launch::async, fut_unwrap(f), xs()...);
            };
        };
}
template<typename F>
auto async_adapter_ds(F&& f) {
    return [f = std::forward<F>(f)](auto&&... async_callables) -> std::future<decltype(f(async_callables.get()...))> {
            return std::async(std::launch::async,
                [f = std::move(f), ...callables = std::forward<decltype(async_callables)>(async_callables)]() mutable {
                    return std::invoke(f, callables.get()...);
                }
            );
        };
}
void _9_12()
{
    // 编译有问题, async_adapter编不了
    //auto pcreate(asynchronize(create));
    //auto pconcat(async_adapter(concat));
    //auto ptwice(async_adapter(twice));

    //auto result(
    //    pconcat(
    //        ptwice(
    //            pconcat(
    //                pcreate("foo "),
    //                pcreate("bar "))),
    //        pconcat(
    //            pcreate("this "),
    //            pcreate("that "))));
    //std::cout << "Setup done. Nothing executed yet.\n";
    //std::cout << result().get() << '\n';

    //auto pcreate_ds(asynchronize_ds(create));
    //auto pconcat_ds(async_adapter_ds(concat));
    //auto ptwice_ds(async_adapter_ds(twice));
    //auto result_ds(
    //    pconcat_ds(
    //        ptwice_ds(
    //            pconcat_ds(
    //                pcreate_ds("foo "),
    //                pcreate_ds("bar "))),
    //        pconcat_ds(
    //            pcreate_ds("this "),
    //            pcreate_ds("that "))));
    //std::cout << "DeepSeek version: Setup done. Nothing executed yet.\n";
    //std::cout << result_ds().get() << '\n';

}
