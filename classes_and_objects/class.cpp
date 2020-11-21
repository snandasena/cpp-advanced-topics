
#include <cstdio>

using namespace std;

class c1 {
    int i = 0;

public:
//    void setValue(const int &value) { i = value; }
    void setValue(const int &);

    int getValue() const;
//    int getValue() const { return i; }

};

void c1::setValue(const int &value) {
    i = value;
}

int c1::getValue() const {
    return i;
}


int main() {
    const int i = 43;
    c1 o1;
    o1.setValue(i);
    printf("value is %d\n", o1.getValue());
    return 0;
}