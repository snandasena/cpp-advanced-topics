#include <cstdio>

using namespace std;

struct A {
    int ia;
    const char *sb = "";
    int ic;
};


int main() {
    A a;
    a.ia = 1;
    a.sb = "two";
    a.ic = 4;
    printf("ia is %d, sb is %s, ic is %d\n", a.ia, a.sb, a.ic);
    return 0;
}