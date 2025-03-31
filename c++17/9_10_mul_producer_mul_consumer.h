#pragma once
#include "base.h"


using namespace std::chrono_literals;


//std::queue<size_t> q;
std::mutex q_mutex;
static std::atomic<bool> production_stopped{ false };
std::condition_variable go_produce;
std::condition_variable go_consume;

static void m_producer(size_t id, size_t items, size_t stock)
{
    for (size_t i = 0; i < items; ++i)
    {
        std::unique_lock<std::mutex> lock(q_mutex);
        pcout{} << "[锁获取] P 线程" << id << "于" << std::chrono::system_clock::now() << "\n";
        go_produce.wait(lock, [&] {return q.size() < stock; });

        q.push(id * 100 + i);
        pcout{} << std::format(" Produce {} --> item {:03}\n", id, q.back());
        go_consume.notify_all();
        std::this_thread::sleep_for(90ms);
    }

    pcout{} << std::format(" EXIT: Produce {} \n", id);
}

static void m_consumer(size_t id)
{
    // 退出标记&没有未处理数据
    while (!production_stopped || !q.empty())
    {
        std::unique_lock<std::mutex> l(q_mutex);
        pcout{} << "[锁获取] C 线程" << id << "于" << std::chrono::system_clock::now() << "\n";
        //if (go_consume.wait_for(l, 1s, [] {return !q.empty(); }))
        // 条件变量必须用while 防假唤醒 唤醒丢失
        while (go_consume.wait_for(l, 1s, [] {return !q.empty(); }))
        {
            pcout{} << std::format(" item {:03} --> Consumer {}\n", q.front(), id);
            q.pop();
            go_produce.notify_all();
            std::this_thread::sleep_for(130ms);
        }
    }

    pcout{} << std::format(" EXIT: Consumer {} \n", id);
}

void _9_10()
{
    std::vector<std::thread> workers;
    std::vector<std::thread> consumers;
    for (size_t i = 0; i < 3; ++i)
    {
        workers.emplace_back(m_producer, i, 15, 5);
    }
    for (size_t i = 0; i < 5; ++i)
    {
        consumers.emplace_back(m_consumer, i);
    }
    for (auto& t : workers) { t.join(); }
    production_stopped = true;
    for (auto& t : consumers) { t.join(); }
}

