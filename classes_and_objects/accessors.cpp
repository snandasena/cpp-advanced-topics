#include <cstdio>

using namespace std;

class A {
    int ia = 0;
    const char *sb = "";
    int ic = 0;


public:
    A(const int a, const char *b, const int c) : ia(a), sb(b), ic(c) {};

    void seta(const int a) { ia = a; }

    void setb(const char *b) { sb = b; }

    void setc(const int c) { ic = c; }

    int geta() const { return ia; }

    const char *getb() const { return sb; }

    int getc() const { return ic; }

};


int main() {
    A a1(1, "two", 3);
    printf("ia is %d, sb is %s, ic is %d\n", a1.geta(), a1.getb(), a1.getc());
    return 0;

}