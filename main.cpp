#include <iostream>

using namespace std;
//
//void swap(int a, int b)
//{
//    int temp = a;
//    a = b;
//    b = temp;
//}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int factorial(int n)
{
    int res = 1;
    for (int i = 1; i <= n; ++i)
    {
        res *= i;
    }

    return res;
}


class Test
{

public:
    int x{};
    int y{};
    int z{};
};

int main()
{

    int a = 10;
    printf("%d\n", a);

    int *p = &a;
    printf("%d\n", *p);
    printf("%d\n", p);
    printf("%d\n", &a);
    cout << &p << "\n";

    int arr[3] = {1, 2, 3};
    printf("%d\n", *arr);
    printf("%d\n", *(arr + 2));
    printf("%d\n", *arr + 3);

    *p = 1000;
    printf("%d\n", a);

    int x = 10;
    int y = 20;

    swap(x, y);
    printf("%d, %d\n", x, y);
    swap(&x, &y);
    printf("%d, %d\n", x, y);

    cout << factorial(5) << "\n";

    Test t{1, 2, 3};
    cout << "X: " << t.x << " Y: " << t.y << " Z: " << t.z << '\n';

    Test t2{.x = 1,
            .y = 2,
            .z = 3};

    cout << "X: " << t2.x << " Y: " << t2.y << " Z: " << t2.z << '\n';

    return 0;
}