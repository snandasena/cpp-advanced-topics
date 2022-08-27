//
// Created by sajith on 8/27/22.
//

#include "base.h"

struct CoroType
{
    struct promise_type
    {
        CoroType get_return_object()
        {
            return CoroType(this);
        }

        std::suspend_always initial_suspend()
        {
            return {};
        }

        std::suspend_always final_suspend() noexcept
        {
            return {};
        }

        void unhandled_exception() noexcept
        {
            std::rethrow_exception(std::current_exception());
        }

        void return_void()
        {

        }
    };

    CoroType(promise_type *p) : m_handle(std::coroutine_handle<promise_type>::from_promise(*p))
    {}

    ~CoroType()
    {
        std::cout << "Handle destroyed...\n";
        m_handle.destroy();
    }

    std::coroutine_handle<promise_type> m_handle;
};

CoroType do_work()
{
    std::cout << "Doing first thing...\n";
    co_await std::suspend_always{};
    std::cout << "Doing second thing...\n";
    co_await std::suspend_always{};
    std::cout << "Doing third thing...\n";
}

int main()
{
    auto task = do_work();
    task.m_handle();

//    if(!task.m_handle.done())
//    {
//        task.m_handle();
//    }
    task.m_handle.resume();
    task.m_handle.resume();

    if(!task.m_handle.done())
    {
        task.m_handle.resume();
    }
    return 0;
}