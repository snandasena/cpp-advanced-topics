//
// Created by sajith on 3/28/21.
//

#include <iostream>
#include <string>

using std::string;

class Rectange
{

private:
    double m_length{1.0};
    double m_width{1.0};

public:
    Rectange(double lenth, double width) : m_length{lenth}, m_width{width} {}

    void Print()
    {
        std::cout << "length: " << m_length << ", width: " << m_width << "\n";
    }
};

class Ball
{
    string m_color;
    double m_radius;

public:
    Ball()
    {
        m_color = "black";
        m_radius = 10.0;
    }

    Ball(const string &color)
    {
        m_color = color;
        m_radius = 10.0;
    }

    Ball(double radius)
    {
        m_color = "black";
        m_radius = radius;
    }

    Ball(const string &color, double radius)
    {
        m_color = color;
        m_radius = radius;
    }

    void Print()
    {
        std::cout << "color: " << m_color << ", radius: " << m_radius << '\n';
    }

};

// delegating constructors

class Employee
{
private:
    int m_id{};
    string m_name{};

public:
    Employee(int id = 0, const string &name = "") : m_id{}, m_name{name}
    {
        std::cout << "Employee: " << m_name << " created\n";
    }

    Employee(const string &name) : Employee{0, name} {};
};



int main()
{
//    Rectange rectange{}; // not compile

    Ball b{};
    b.Print();

    Ball b1{"blue"};
    b1.Print();

    Ball b2{5.0};
    b2.Print();

    Ball b3{"green", 19.0};
    b3.Print();


    Employee e{};
    Employee e2{"Tom"};
    return 0;
}