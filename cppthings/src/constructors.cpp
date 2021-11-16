//
// Created by sajith on 11/16/21.
//

#include <bits/stdc++.h>

using namespace std;

struct Point
{
    int x;
    int y;
};


class PointConsumer
{
public:
    void set_point(Point p) {}

    void set_points(initializer_list<Point> my_list) {}
};


void testPointConsumer()
{
    PointConsumer pc{};
    pc.set_point({});
    pc.set_point({1, 3});
    pc.set_points({{1, 2},
                   {3, 4}});
}


class Box
{
public:
    Box()
    {
        cout << "Default constructor\n";
    }

    Box(int width, int height, int length) : m_width{width}, m_height{height}, m_length{length}
    {
        cout << "int, int, int\n";
    }

    Box(Box &other) : m_width{other.m_width}, m_height{other.m_height}, m_length{other.m_length}
    {
        cout << "copy\n";
    }

    Box(Box &&other) : m_width{other.m_width}, m_height{other.m_height}, m_length{other.m_length}
    {
        m_contents = move(other.m_contents);
        cout << "move\n";
    }

    int Volume() { return m_width * m_height * m_length; }

    void Add_Item(string item) { m_contents.push_back(item); }

    void Print_Contents()
    {
        for (const auto &item : m_contents)
        {
            cout << item << " ";
        }
    }


private:
    int m_width{0};
    int m_height{0};
    int m_length{0};
    vector<string> m_contents;
//    unique_ptr<int> ptr{nullptr};
};

Box get_Box()
{
    Box b(5, 10, 18); // "int,int,int"
    b.Add_Item("Toupee");
    b.Add_Item("Megaphone");
    b.Add_Item("Suit");

    return b;
}


int main()
{
    Box b1;
    Box b2(b1);
    Box b3(get_Box());
    return 0;
}