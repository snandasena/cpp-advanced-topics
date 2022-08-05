//
// Created by sajith on 5/24/22.
//

#include "base.h"
//
//
//void constCastTest1()
//{
//    const int a = 10;
//    const int *b = &a;
////    *b = 30; // read only assigment
//    int *c = const_cast<int *>(b);
//    *c = 40;
//    cout << a << endl; // 10
//    cout << *c << endl; // 40
//}
//
//void constCastTest2()
//{
//    int a = 10;
//    const int *b = &a;
////    *b = 30;
//    int *c = const_cast<int *> (b);
//    *c = 40;
//
//    cout << a << endl;
//    cout << *c << endl;
//}
//
//template<typename T1, typename T2>
//auto add(T1 a, T2 b) -> decltype(a + b)
//{
//    return a + b;
//}
//
//class Base
//{
//
//    virtual void print()
//    {
//        cout << "Base\n";
//    }
//};
//
//class D1 : public Base
//{
//    void print()
//    {
//        cout << "D1\n";
//    }
//};
//
//class D2 : public Base
//{
//    void print()
//    {
//        cout << "D2\n";
//    }
//};
//
//
//int add(int a, int b)
//{
//    return a + b;
//}
//
//
//int gt(int a, int b)
//{ return a > b ? 1 : -1; }
//
//int lt(int a, int b)
//{
//    return a < b ? 1 : -1;
//}
//
//using matFunc = int (*)(int, int);
//
//matFunc fun(int t)
//{
//    if (t > 10) return &gt;
//    return &lt;
//}
//
////int compare(int a, int b, matFunc func)
//int compare(int a, int b, std::function<int(int, int)> &func)
//{
//    return func(a, b);
//}
//
//class AC
//{
//    static int i;
//public:
//    AC()
//    {
//        ++i;
//        cout << i << '\t';
//    }
//
//    ~AC()
//    {
//        cout << i << '\t';
//        --i;
//    }
//};
//
//int AC::i = 0;
//
//
//template<typename T>
//class AB
//{
//    static int x;
//public:
//    AB() = default;
//
//    void print()
//    {
//        cout << x << endl;
//    }
//};
//
//template<typename T>
//int AB<T>::x = 10;
//
////int main()
////{
////    AB<int> a;
////    a.print();
////
////    AB<double> b;
////    b.print();
////
////    return 0;
////}
//
//class AA
//{
//    int x;
//
//public:
//    explicit AA() = default;
//
//    explicit AA(int i) : x{i}
//    {}
//
//    operator int() const
//    {
//        return x;
//    }
//};
//
//
////int main()
////{
////    AA a(200);
////
////    int b = a;
////    cout << b << endl;
////
////    return 0;
////}
//
//
//class MyInt
//{
//    int ele;
//public:
//    MyInt() = default;
//
//    MyInt(int i) : ele{i}
//    {}
//    MyInt &operator++()
//    {
//        ++ele;
//        return *this;
//    }
//
//    MyInt operator++(int)
//    {
//        MyInt temp = *this;
//        ++(*this);
//        return temp;
//    }
//
//    void print()
//    {
//        cout << ele << endl;
//    }
//};


//int main()
//{
//    MyInt i{10};
//    (i++).print();
//    i.print();
//
//}
//class StopCopy
//{
//public:
//    StopCopy()
//    {}
//private:
//    StopCopy(const StopCopy &)
//    {}
//    StopCopy &operator=(const StopCopy &)
//    {
//
//    }
//};
//
//
//class Base : public StopCopy
//{
//    int x;
//public:
//    Base()
//    {}
//    Base(int _x) : x{_x}
//    {}
//
//};
//
//
//int main()
//{
//
//    Base b1;
//    Base b2 = b1;
//    Base b3{b1};
//
//}

//
//class Base
//{
//    int x;
//
//public:
//    Base()
//    {}
//    Base(int _x) : x{_x}
//    {}
////
////private:
////    Base *operator&()
////    {
////        return this;}
//
//    Base *operator&() = delete;
//};
//
//int main()
//{
//    Base b;
//    Base *b2 = &b;
//
//}

//class Base final
//{
//    int x;
//public:
//    Base()
//    {}
//    Base(int _x) : x{_x}
//    {}
//};
//
//class Derived: public Base
//{
//
//};

//class Base
//{
//public:
//    Base()
//    {
//        cout << "Constructor called\n";
//    }
//
//    ~Base()
//    {
//        cout << "Destructor called\n";
//    }
//};
//
//int main()
//{
//    Base();
//    Base b;
//    b.~Base();
//
//    Base obj;
//    cout << "Something called\n";
//    return 0;
//}
//
//
//class Base
//{
//public:
//    Base() = default;
//
//    virtual void func()
//    {
//        cout << "Base func\n";
//    }
//
//    virtual ~Base() = default;
//};
//
//class Derived : public Base
//{
//public:
//
//    void func() override
//    {
//        cout << "Derived func\n";
//    }
//};
//
//class Derived2 : public Derived
//{
//public:
//    void func() override
//    {
//        cout << "Derived2 func\n";
//    }
//};
//
//int main()
//{
//    Base *base = new Derived;
//
//    delete base;
//
//    return 0;
//}

//class Base
//{
//    int a = 10;
//public:
//    Base()
//    {
//        cout << "Constructor called\n";
//    }
//
//    ~Base()
//    {
//        cout << "Destructor called\n";
//    }
//};
//
//
//int main()
//{
//
//    char *memory = new char[10 * sizeof(Base)];
//
//    Base *obj1 = new(&memory[0]) Base;
//    Base *obj2 = new(&memory[4]) Base;
//    Base *obj3 = new(&memory[8]) Base;
//
//    obj1->~Base();
//    obj2->~Base();
//    obj3->~Base();
//    delete[] memory;
//}

//class Mango
//{
//public:
//    void funM()
//    {
//        cout << "Mango\n";
//    }
//};
//
//class Banana
//{
//public:
//    void funcB()
//    {
//        cout << "Banana\n";
//    }
//};
//
//
//int main()
//{
//    Banana *b = new Banana;
//    Mango *m = new Mango;
//
//    Banana *bm = reinterpret_cast<Banana *>(m);
//    bm->funcB();
//
//    return 0;
//}
//
//struct MyStruct
//{
//    int x;
//    int y;
//    char c;
//    bool b;
//};
//
//int main()
//{
//    MyStruct s;
//    s.x = 10;
//    s.y = 20;
//    s.c = 'Base1';
//    s.b = true;
//
//    int *p = reinterpret_cast<int *>(&s);
//    cout << *p << endl;
//    *p = 50;
//    cout << s.x << endl;
//
//    ++p;
//    cout << *p << endl;
//    ++p;
//    char *c = reinterpret_cast<char *> (p);
//    cout << *c << endl;
//
//    cout <<boolalpha<< *(reinterpret_cast<bool *>(++c)) << endl;
//
//    return 0;
//}

//class Int
//{
//    int x;
//public:
//
//    Int(int i = 0) : x{i}
//    {
//        cout << "conversion constructor\n";
//    }
//
//    operator string()
//    {
//        cout << "conversion operator\n";
//        return to_string(x);
//    }
//};
//
//
//int main()
//{
//    Int obj(10);
//    string str = obj;
//    obj = 200;
//    string str2 = static_cast<string>(obj);
//    obj = static_cast<Int >(30);
//    return 0;
//}

//
//int main()
//{
//    char c;
//    int *p = (int *) &c;
//    *p = 10;
//
////    int *ip = static_cast<int *>(&c);
//    return 0;
//}
//
//int main()
//{
//    int i = 10;
//    void *v = static_cast<void *>(&i);
//    int *ip = static_cast<int *>(v);
//
//    return 0;
//}

//struct Base1
//{
//    double b;
//    int a;
//};
//
//
//struct B
//{
//    Base1 a;
//    int c;
//};
//
//int main()
//{
//    cout<<sizeof(Base1)<<endl;
//    cout<<sizeof(B)<<endl;
//}


//enum Color
//{
//    red =10, green, blue
//};
//
//Color c = red;
//
//enum class Color2
//{
//    red,
//    green1,
//    blue1
//};
//
//Color2 c2 = Color2::red;
//
//int main()
//{
//    cout<<red<<endl;
//    cout<<green<<endl;
//
////    cout<< Color2::red<<endl;
//
//    return 0;
//}
//
//tuple<int, double, char> func()
//{
//    return {10, 22.222, 'Base1'};
//}
//
//
//int main()
//{
//
//    int a;
//    double d;
//    char c;
//
//    tie(a, d, c) = func();
//
//    cout << a << '\t' << d << '\t' << c << '\n';
//
//
//    cout<< a<<endl;
//    return 0;
//}

//class Base1
//{
//    int x;
//public:
//
//    Base1(int i) : x{i}
//    {}
//};
//
//
//class B
//{
//    Base1 a;
//public:
//    B(Base1 _a) : a{_a}
//    {
//    }
//};
//
//int main()
//{
//    B b(10);
//    return 0;
//}

//void *operator new(size_t size)
//{
//    cout << "Allocating " << size << " bytes\n";
//    return malloc(size);
//}
//
//void operator delete(void *memory, size_t size)
//{
//    cout << "Freeing " << size << " bytes\n";
//    free(memory);
//}

//class Base
//{
//    int x;
//    int y;
//public:
//    virtual void func()
//    {
//        cout << "Base\n";
//    }
//};
//
//class Derived : public Base
//{
//    int z;
//public:
//
//    void func()
//    {
//        cout << "Derived\n";
//    }
//};
//
//
//int main()
//{
//    shared_ptr<Base> pb = make_shared<Derived>();
//    pb->func();
//    return 0;
//}

//class Base
//{
//    int _x;
//public:
//
//    Base()
//    {
//        cout<<"Base default\n";
//    }
//    Base(int x) : _x{x}
//    {
//        cout << "Base with params\n";
//    }
//
//    Base(const Base &other)
//    {
//        this->_x = other._x;
//        cout << "Base copy constructor\n";
//    }
//
//    Base &operator=(const Base &rhs)
//    {
//        this->_x = rhs._x;
//        cout << "Base copy assigment\n";
//        return *this;
//    }
//
//};
//
//class MyClass
//{
//    Base b;
//public:
//    MyClass()
//    {
//        cout << "my class constructor\n";
//    }
//    MyClass(Base a):b{a}
//    {
//        cout << "my class parameter\n";
//    }
//};
//
//int main()
//{
//    Base b(10);
//    MyClass m(b);
//
//    return 0;
//}

//class Foo
//{
//    int x;
//
//public:
//    Foo(int _x) : x{_x}
//    {
//        cout << "Foo\n";
//    }
//
//    ~Foo()
//    {
//        cout << "~Foo\n";
//    }
//
//    int getX() const
//    { return x; }
//
//    void setX(int newX)
//    {
//        x = newX;
//    }
//};
//
//void func(const shared_ptr<Foo> &sp)
//{
//    cout << "use count " << sp.use_count() << endl;
//    sp->setX(100);
//}
//
//int main()
//{
//    auto sp = make_shared<Foo>(10);
//    cout << "Value " << sp->getX() << endl;
//    cout << "use count " << sp.use_count() << endl;
//    func(sp);
//    cout << "use count " << sp.use_count() << endl;
//    cout << "Value " << sp->getX() << endl;
//    return 0;
//}

//
//class Storable
//{
//public:
//
//    virtual void read() = 0;
//
//    virtual void write();
//
//    virtual ~Storable() = default;
//
//};
//
//class Transmitter : public virtual Storable
//{
//public:
//
//    void read()
//    {
//        cout << "Transmitter read()\n";
//    }
//};
//
//class Receiver : public virtual Storable
//{
//public:
//
//    void write()
//    {
//        cout << "Receiver write()\n";
//    }
//};
//
//class Radio : public Transmitter, public Receiver
//{
//public:
//
//};
//
//int main()
//{
//    Radio *rad = new Radio;
//
//    Receiver *receiv = rad;
//    Transmitter *trans = rad;
//
//    rad->Receiver::write();
//    rad->Storable::write();
//    receiv->write();
//    trans->write();
//
//    return 0;
//}

//class Base1
//{
//public:
//    Base1()
//    {
//        cout << "Base1()\n";
//    }
//    void func()
//    {
//        cout << "Base1 func()\n";
//    }
//};
//
//class B : public virtual Base1
//{
//public:
//    B()
//    {
//        cout << "B()\n";
//    }
//};
//
//class C : public virtual Base1
//{
//public:
//    C()
//    {
//        cout << "C()\n";
//    }
//};
//
//class D : public  B, public  C
//{
//public:
//    D()
//    {
//        cout << "D()\n";
//    }
//};
//
//int main()
//{
//    D d;
//    d.B::func();
//    return 0;
//}

//class Base1
//{
//    int _x;
//public:
//    Base1(int x) : _x{x}
//    {
//        cout << "Base1()\n";
//    }
//
//    void func()
//    {
//        cout << "Base1 func()\n";
//    }
//
//    void funcB1()
//    {
//        cout << "Base1 funcB1()\n";
//    }
//};
//
//class Base2
//{
//    int _y;
//public:
//    Base2(int y) : _y{y}
//    {
//        cout << "Base2()\n";
//    }
//
//    void func()
//    {
//        cout << "Base2 func()\n";
//    }
//
//    void funcB2()
//    {
//        cout << "Base2 funcB2()\n";
//    }
//};
//
//class Derived : public Base1, public Base2
//{
//public:
//    Derived(int x, int y) : Base1{x}, Base2{y}
//    {
//        cout << "Derived()\n";
//    }
//};
//
//int main()
//{
//    Derived d{10, 20};
////    d.Base1::func();
////    d.Base2::func();
////
////
////    Base2 b2 = d;
////    b2.func();
////
////    static_cast<Base2>(d).func();
//
//    d.funcB1();
//    d.funcB2();
//    return 0;
//}


//class Base
//{
//public:
//
//    Base()
//    {
//        cout << "Base()\n";
//    }
//
//    void func()
//    {
//        cout << "Base func()\n";
//    }
//
//};
//
//class A : public Base
//{
//public:
//
//    A()
//    {
//        cout << "A()\n";
//    }
//
//    void func()
//    {
//        cout << "A func()\n";
//    }
//};
//
//
//class B : public Base
//{
//public:
//    B()
//    {
//        cout << "B()\n";
//    }
//
//    void func()
//    {
//        cout << "B func()\n";
//    }
//};
//
//
//class C : public Base
//{
//public:
//
//    C()
//    {
//        cout << "C()\n";
//    }
//
//    void func()
//    {
//        cout << "C func()\n";
//    }
//};
//
//void API(Base &b)
//{
//    b.func();
//}
//
//int main()
//{
////    Base b;
////    API(b);
//
//    A a;
//    API(a);
//    return 0;
//}

//class Base
//{
//    int *ptrI = nullptr;
//    int x;
//public:
//
//    Base(int _x = 0, int _y = 0) : ptrI{new int{_y}}, x{_x}
//    {
//        cout << "Base::Base()\n";
//    }
//
//    virtual void func()
//    {
//        cout << "Base::func()\n";
//    }
//
//    virtual  ~Base()
//    {
//        cout << "Base::~Base()\n";
//        delete ptrI;
//
//    };
//
//    Base(const Base &other);
//
//    Base &operator=(const Base &other);
//
//    Base(Base &&other) noexcept;
//
//    Base &operator=(Base &&other) noexcept;
//};
//
//Base::Base(const Base &other)
//{
//    this->x = other.x;
//    this->ptrI = new int{*other.ptrI};
//}
//
//Base &Base::operator=(const Base &other)
//{
//    this->ptrI = new int{*other.ptrI};
//    this->x = other.x;
//    return *this;
//}
//Base::Base(Base &&other) noexcept: ptrI{other.ptrI}, x{other.x}
//{
//    other.ptrI = nullptr;
//    other.x = 0;
//}
//Base &Base::operator=(Base &&other) noexcept
//{
//    ptrI = other.ptrI;
//    x = other.x;
//
//    other.ptrI = nullptr;
//    other.x = 0;
//    return *this;
//}
//
//class Derived : public Base
//{
//public:
//
//    Derived(int x, int y) : Base(x, y)
//    {
//        cout << "Derived::Derived()\n";
//    }
//    void func() override
//    {
//        cout << "Derived::func()\n";
//    }
//
//    void base_func()
//    {
//        cout << "Derived::base_func()\n";
//    }
//
//};
//
//struct AB
//{
//    int x;
//    int y;
//};
//
//struct A : AB
//{
//    int a;
//    int b;
//
//    A(int x) : a{x}, b{x}
//    {}
//};
//
//int main()
//{
////    Derived d;
////    d.func();
////    d.base_func();
////
////    Base &b = d;
////    b.func();
////
////    Derived *pD = new Derived;
////    pD->func();
////
////    delete pD;
//
////    Derived d{10, 20};
////
////    Derived d2 = d;
//
//    if (std::is_standard_layout_v<A>)
//    {
//        cout << "TRUE";
//    }
//
//    return 0;
//}