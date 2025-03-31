#pragma once
#include "base.h"

std::queue<size_t> q;
std::mutex mut;
std::condition_variable cv;
bool finished{false};

static void producer(size_t items)
{
    using namespace std::chrono_literals;
    
    for (size_t i{0}; i < items; ++i)
    {
        std::this_thread::sleep_for(100ms);
        {
            std::lock_guard<std::mutex> lk(mut);
            q.push(i);
        }
        cv.notify_all();
    }
    {
        std::lock_guard<std::mutex> lk(mut);
        finished = true;
    }
    cv.notify_all();
}

static void consumer()
{
    while (!finished)
    {
        std::unique_lock<std::mutex> l{mut};

        cv.wait(l, []{return !q.empty() || finished;});
        while (!q.empty())
        {
            std::cout << "Got " <<q.front() << " from queue.\n";
            q.pop();
        }
    }
}

void _9_9()
{
    std::thread t1{producer, 10};
    std::thread t99{consumer};
    t1.join();
    t99.join();
    std::cout <<"finished !!!!!!!!!\n";
}

