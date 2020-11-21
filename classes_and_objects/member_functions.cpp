#include <cstdio>

using namespace std;

class A {
    int _value = 0;

public:
    void setA(const int a) { _value = a; }

    int getA() const { return _value; }
};

int main() {

    A a;
    a.setA(100);

    printf("a is %d\n", a.getA());

//    A b = a;
    const A b = a;
    printf("b is %d\n", b.getA());
    return 0;
}