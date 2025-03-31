#pragma once
#include "base.h"

template<typename T>
class trie
{
    std::map<T, trie> tries;
public:
    template<typename It>
    void insert(It it, It end_it)
    {
        if (it == end_it) 
        {
            return; 
        }
        tries[*it].insert(next(it), end_it);
    }
    template<typename C>
    void insert(const C &container)
    {
        insert(std::begin(container), std::end(container));
    }
    void insert(const std::initializer_list<T> &il)
    {
        insert(std::begin(il), std::end(il));
    }

    void print(std::vector<T> &v) const 
    {
        if (tries.empty())
        {
            std::copy(std::begin(v), std::end(v), std::ostream_iterator<T>{std::cout, " "});
            std::cout << '\n';
        }
        for (const auto &p : tries)
        {
            v.push_back(p.first);
            p.second.print(v);
            v.pop_back();
        }
    }
    void print() const
    {
        std::vector<T> v;
        print(v);
    }

    template<typename It>
    std::optional<std::reference_wrapper<const trie>>
    subtrie(It it, It end_it) const
    {
        if (it == end_it) { return std::ref(*this); }
        auto found(tries.find(*it));
        if (found == end(tries))
        {
            return {};
        }

        return found->second.subtrie(next(it), end_it);
    }
    template<typename C>
    auto subtrie(const C &c)
    {
        return subtrie(std::begin(c), std::end(c));
    }
};

void _6_1()
{
    trie<std::string> t;
    t.insert({"hi", "how", "are", "you"});
    t.insert({"hi", "i", "am", "great", "thanks"});
    t.insert({"what", "are", "you", "doing"});
    t.insert({ "i", "am", "watching", "a", "movie"});
    std::cout << "recorder sentences:\n";
    std::cout << "\npossible suggestions after \"hi\":\n";
    //t.print();
    if (auto st (t.subtrie(std::initializer_list<std::string>{"hi"})); st)
    {
        st->get().print();
    }
}
