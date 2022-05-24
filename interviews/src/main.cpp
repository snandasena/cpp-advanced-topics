//
// Created by sajith on 5/24/22.
//

#include <iostream>
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

class Test1
{
    int y;
};

class Test2
{
    int x;
    Test1 t1;

public:

    operator Test1()
    {
        return t1;
    }

    operator int()
    {
        return x;
    }
};

void func(int x)
{
}

void func(Test1 t)
{

}

void test6()
{
    Test2 t;
    func(t);
}

int main()
{
//    test1();
//    test2();
//    test3();
//    test4();
//    test5();
    test6();

    return 0;
}