#pragma once
#include "base.h"

static void prompt()
{
    std::cout << "Next input please:\n > ";
}

void _6_2()
{
    trie<std::string> t;
    std::fstream infile{"db.txt"};
    for (std::string line; getline(infile, line);) 
    {
        std::istringstream iss(line);
        t.insert(std::istream_iterator<std::string>{iss}, {});
    }
    prompt();
    for (std::string line; std::getline(std::cin, line);)
    {
        std::istringstream iss {line};
        if (auto st(t.subtrie(std::istream_iterator<std::string>{iss}, {})); st)
        {
            std::cout << "suggestions:\n";
            st->get().print();
        }
        else
        {
            std::cout << "No suggestions found.\n";
        }
        std::cout << "---------------\n";
        prompt();
    }
}
