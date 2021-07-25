//
// Created by sajith on 3/17/21.
//


#include <iostream>
#include <array>

template<typename T>
class Stack
{
    size_t index = 0;
    std::array<T, 100> elements{};

public:
    Stack() = default;

    void Push(T item)
    {
        if (index > 99)
        {
            throw std::logic_error{"Overflow error!"};
        }
        else
        {
            elements[++index] = item;
        }
    }

    void Pop()
    {
        if (index < 0)
        {
            throw std::logic_error{"Stack is empty!"};
        }
        else
        {
            --index;
        }
    }

    T Top()
    {
        return elements[index];
    }
};


int main()
{

    Stack<int> iStack;
    iStack.Push(10);
    iStack.Push(11);
    iStack.Push(12);
    iStack.Push(13);

    std::cout << iStack.Top() << '\n';
    iStack.Pop();
    std::cout << iStack.Top() << '\n';
    return 0;

}