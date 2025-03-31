//module; // ȫ��ģ��
//export module mybase;
//export import std; // [export] ʹimport mybase �Ŀɼ�std

//template <typename T> ������exportģ��
// module ��֧�ֻ���̫���˷�����
#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <format>
#include <list>
#include <algorithm>
#include <assert.h>
#include <iomanip>
#include <functional>
#include <iterator>
#include <sstream>
#include <initializer_list>
#include <optional>
#include <fstream>
#include <string_view>
#include <iomanip>
#include <locale>
#include <variant>
#include <mutex>
#include <queue>
#include <thread>


void print_vector(std::vector<int> v)
{
    for (auto i : v)
    {
        std::cout << std::format("{}, ", i);
    }
    std::cout << '\n';
}

struct pcout : public std::stringstream
{
    static inline std::mutex cout_mutex;
    ~pcout()
    {
        std::lock_guard<std::mutex> l{ cout_mutex };
        std::cout << rdbuf();
        std::cout.flush();
    }
};


