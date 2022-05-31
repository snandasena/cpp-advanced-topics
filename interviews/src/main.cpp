//
// Created by sajith on 5/24/22.
//

#include <iostream>
#include <memory>
#include <vector>
#include <list>
#include <algorithm>

using std::vector;
using std::list;

//
//class A
//{
//    int i;
//public:
//    A(int x = 0) : i{x} {}
//
//    void show()
//    {
//        printf("i = %d\n", i);
//    }
//};
//
//class B
//{
//    int x;
//public:
//    B(int i) : x{i} {}
//
//    operator A() const
//    {
//        return A(x);
//    }
//};
//
//void func(A a)
//{
//    a.show();
//}
//
//void test1()
//{
//    B b(10);
//    func(b);
//    func(20);
//}
//
//class Base
//{
//    int arr[10];
//};
//
//class D1 : public Base
//{
//};
//
//class D2 : public Base
//{
//};
//
//class Derived : public D1, public D2
//{
//};
//
//void test2()
//{
//    printf("%ld", sizeof(Derived));
//}
//
//
//class B1 : virtual public Base
//{
//};
//
//class B2 : virtual public Base
//{
//
//};
//
//class Derived1 : public B1, public B2
//{
//
//};
//
//void test3()
//{
//    printf("%ld\n", sizeof(Derived1));
//}


//class Base
//{
//public:
//    Base()
//    {
////        fun();
//    }
//
//    virtual void fun()
//    {
//        printf("Base class func\n");
//    }
//
//    virtual ~Base() = default;
//};
//
//class Derived : public Base
//{
//public:
//    Derived()
//    {
//
//    }
//
//    virtual void fun()
//    {
//        printf("Derived class func\n");
//    }
//};
//
//void test4()
//{
//    Base *b = new Derived;
//    delete b;
//}

//
//class Test
//{
//public:
//    Test();
//};
//
//Test::Test()
//{
//    printf("Constructor called\n");
//}
//
//void test5()
//{
//    printf("Started\n");
//    Test t1();
//    Test t2{};
//    printf("End\n");
//}

//class Test
//{
//    int val;
//public:
//    Test(int v = 0) { val = v; }
//
//    int getVal() const { return val; }
//};
//
//void test6()
//{
//    const Test t;
//    printf("%d", t.getVal());
//}

//class Test
//{
//    int &t;
//public:
//    Test(int &x) : t{x} {}
//};
//
//class Test1
//{
//    int y;
//};
//
//class Test2
//{
//    int x;
//    Test1 t1;
//
//public:
//
//    operator Test1()
//    {
//        return t1;
//    }
//
//    operator int()
//    {
//        return x;
//    }
//};
//
//void func(int x)
//{
//}
//
//void func(Test1 t)
//{
//
//}
//
//void test6()
//{
//    Test2 t;
//    func(t);
//}
//
//class AA
//{
//public:
//
//    ~AA()
//    {
//        printf("~A\n");
//    }
//};
//
//class BB : public AA
//{
//public:
//    ~BB()
//    {
//        printf("~B\n");
//    }
//};

//void test7()
//{
//    auto b = std::shared_ptr<AA>(new BB());
//    b.reset();
//
//    for (vector<int> v{1, 3, 4, 5, 6}; auto &i: v)
//    {
//        printf("%d\t", i);
//    }
//}

//namespace text_editor
//{
//    using Line = vector<char>;
//
//    class Text_iterator;
//
//    class Text_iterator
//    {
//        list<Line>::iterator itr;
//        Line::iterator pos;
//
//    public:
//
//        Text_iterator(list<Line>::iterator it, Line::iterator pp) : itr{it}, pos{pp} {}
//
//        char &operator*() { return *pos; }
//
//        Text_iterator &operator++();
//
//        bool operator==(const Text_iterator &other) const
//        {
//            return (itr == other.itr && pos == other.pos);
//        }
//
//        bool operator!=(const Text_iterator &other) const
//        {
//            return !(*this == other);
//        }
//    };
//
//    Text_iterator &Text_iterator::operator++()
//    {
//        ++pos;
//        if (pos == (*itr).end())
//        {
//            ++itr;
//            pos = (*itr).begin();
//        }
//        return *this;
//    }
//
//    struct Document
//    {
//        list<Line> line;
//
//        Document()
//        {
//            line.push_back(Line{});
//        }
//
//        Text_iterator begin()
//        {
//            return {line.begin(), (*line.begin()).begin()};
//        }
//
//        Text_iterator end()
//        {
//            auto last = line.end();
//            --last;
//            return {last, (*last).end()};
//        }
//    };
//
//}
//
//std::istream &operator>>(std::istream &is, text_editor::Document &doc)
//{
//    for (char ch; is.get(ch);)
//    {
//        doc.line.back().push_back(ch);
//        if (ch == '\n')
//        {
//            doc.line.push_back(text_editor::Line{});
//        }
//
//        if (doc.line.back().size())
//        {
//            doc.line.push_back(text_editor::Line{});
//        }
//    }
//
//    return is;
//}
//
//
//std::ostream &operator<<(std::ostream &out, text_editor::Document &doc)
//{
//    return out;
//}
//
//void print(text_editor::Document &doc)
//{
//    for (auto p: doc)
//    {
//        std::cout << &p;
//    }
//}
//
//template<typename T, int N>
//struct Array
//{
//    using value_t = T;
//    using iterator = T *;
//    using const_itearor = const T *;
//    using size_type = unsigned int;
//
//    T elem[N];
//
//    iterator begin() { return elem; }
//
//    const_itearor begin() const { return elem; }
//
//    iterator end() { return elem + N; }
//
//    const_itearor end() const { return elem + N; }
//
//    size_type size() const;
//
//    T &operator[](int n) { return elem[n]; }
//
//    const T &operator[](int n) const { return elem[n]; }
//
//    const T &at(int n) const;
//
//    T &at(int n);
//
//    T *data() { return elem; }
//
//    const T *data() const { return elem; }
//};

class Larger_than
{
    int v;

public:
    Larger_than(int vv) : v{vv} {}

    bool operator()(int x) const { return x > v; }
};

int main()
{
    Larger_than lt{10};

    std::vector<int> v{10,20,30,1,2,2,4};
    auto res = std::find_if(v.begin(), v.end(), Larger_than(21));

    printf("%d", Larger_than(lt))  ;
    return 0;
}