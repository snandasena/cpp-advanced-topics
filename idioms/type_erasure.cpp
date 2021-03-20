//
// Created by sajith on 3/16/21.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <memory>

using namespace std;

namespace example
    {

            // 1. Type erasure using void* (like in C)
            void qsort(void *base, size_t num, size_t size, int(*compar)(const void *, const void *));

            int compare(const void *a, const void *b)
            {
                const int arg1 = *static_cast<const int *>(a);
                const int arg2 = *static_cast<const int *>(b);

                if (arg1 < arg2) return -1;
                if (arg1 > arg2) return 1;
                return 0;
            }

            // Drawback: not safe

            //2. Type erasure using template
            template<class RandomAccessIterator>
            void sort(RandomAccessIterator first, RandomAccessIterator last);

            // Drawback: may lead to many function template instantions
            // and longer compilation time

            // 3. Type erasure using polymorphism

            struct A
            {
                virtual ~A() = default;

                virtual void foo() =0;
            };

            struct B : A
            {
                ~B() = default;

                void foo() override
                {
                    std::cout << "B\n";
                }
            };

            struct C : A
            {
                ~C() = default;

                void foo() override
                {
                    std::cout << "C\n";
                }
            };


            void call(A *p)
            {
                p->foo();
            }

            // Drawback: run-time cost (dynamic dispatch, indirection, vtable, etc.)


            // 4.  Type erasure using Union(special class that can hold only one of its non static data member at a time)

            struct Data
            {
            };

            union U
            {
                Data data;
                std::int32_t n;
                char c;

                ~U() {}
            };

            // Drawback: not safe
    }


int main()
{

    std::vector<int> v = {3, 1, 2};
//    std::vector<double > v = {33, 11, 22};
    std::qsort(v.data(), v.size(), sizeof(int), &example::compare);


    for (auto &i: v)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";


    std::vector<int> v2 = {3, 2, 1};
    std::sort(v2.begin(), v2.end());
    for (auto &i: v2)
    {
        std::cout << i << " ";
    }
    std::cout << "\n";


    std::unique_ptr<example::A> ap1 = std::make_unique<example::B>();
    std::unique_ptr<example::A> ap2 = std::make_unique<example::C>();

    example::call(ap1.get());
    example::call(ap2.get());


    example::U u;
    u.n = 100;
    u.c = 'X';
    new(&u.data) example::Data();

    return 0;
}