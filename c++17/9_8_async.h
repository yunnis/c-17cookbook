#pragma once
#include <future>
#include <thread>
#include <chrono>

#include "base.h"

using charCounts = std::map<char, size_t>;
static charCounts histogram(const std::string& s)
{
    charCounts m;
    for (char c : s)
    {
        m[c] += 1;
    }
    return m;
}
static std::string sorted(std::string s)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(3000));
    sort(begin(s), end(s));
    return s;
}
static size_t vowels(const std::string& s)
{
    return count_if(begin(s), end(s), [](char c) -> bool {
        char vowels[]{ "aeiou" };
        return std::end(vowels) != std::find(std::begin(vowels), std::end(vowels), c);
        });
}

// $ echo "foo bar baz foobazinga" | ./async
void _9_8()
{
    std::cin.unsetf(std::ios::skipws);
    std::string input{ std::istream_iterator<char>{std::cin}, {} };
    input.pop_back();

    auto hist(std::async(std::launch::async, histogram, input));
    auto sorted_str(std::async(std::launch::async, sorted, input));
    auto vowel_count(std::async(std::launch::async, vowels, input));

    for (const auto& [c, count] : hist.get()) {
        std::cout << c << ": " << count << '\n';
    }
    // 执行到sorted_str会等待睡眠时间再打印
    std::cout << "Sorted string: "
        << quoted(sorted_str.get()) << '\n'
        << "Total vowels: "
        << vowel_count.get() << '\n';
}
