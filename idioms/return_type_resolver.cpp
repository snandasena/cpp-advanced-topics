//
// Created by sajith on 3/16/21.
//

#include <iostream>
#include <vector>
//
//template<typename SequenceContainer>
//SequenceContainer range(const size_t from, const size_t to)
//{
//    SequenceContainer container;
//    for (size_t i = from; i < to; ++i)
//    {
//        container.insert(container.end(), i);
//    }
//    return container;
//}

class Range
{
    size_t from, to;
public:
    Range(size_t from, size_t to) : from(from), to(to)
    {
        if (from > to) throw std::logic_error{"Invalid args"};
    }

    template<typename SequenceContainer>
    operator SequenceContainer()
    {
        SequenceContainer container;
        for (size_t i = from; i < to; ++i)
        {
            container.insert(container.end(), i);
        }
        return container;
    };
};

class String
{
    const std::string &s;

public:
    String(const std::string &s) : s(s)
    {

    }

    operator int()
    {
        return std::stoi(s);
    }

    operator double()
    {
        return std::stod(s);
    }
};

int main()
{

//    std::vector<int> r = range<std::vector<int >>(0, 5);

    std::vector<int> r = Range(0, 5);
    for (auto i: r)
        std::cout << i << std::endl;

    std::string s = "124";

    int x = String(s);
    std::cout << x << '\n';
    double y = String("3.14");
    std::cout << y << '\n';
    return 0;
}