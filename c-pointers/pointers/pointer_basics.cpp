//
// Created by sajith on 7/12/21.
//

#include <iostream>

using namespace std;

double average(const double *values, const int &count);

int main()
{
    int arr[10];
    printf("%p", arr);

    for (int i = 0; i < 10; ++i)
    {
        printf("Position: %d, Pointer %p\n", i, arr + i);
    }

    char initial = 'p';
    char *pInitial = &initial;
    cout << "Memory address for initial p: " << pInitial << endl;
    cout << "Memory address for initial p: " << (void *) pInitial << endl;
    cout << "Memory address for initial p: " << static_cast<void *>(pInitial) << endl << endl;

    int num = 10;
    int *pNum = &num;
    int **p2Num = &pNum;

    cout << "Address of num " << &num << endl;
    cout << "Address stored in pNum " << pNum << endl;
    cout << "Address of pNum " << &pNum << endl;
    cout << "Address stored in p2Num " << p2Num << endl;


    int testScores[5]{100, 95, 99, 85, 83};
    int *pointerArray[5];

    for (int i = 0; i < 5; ++i)
    {
        pointerArray[i] = &(testScores[i]);
        cout << **(pointerArray + i) << endl;
    }


    double values[5]{5.00, 4.50, 3.75, 3.10, 6.75};

    cout << average(values, 5) << endl;

    return 0;
}


double average(const double *values, const int &count)
{

    double sum = 0.0;
    for (int i = 0; i < count; ++i)
    {
        sum += *(values + i);
    }

    return sum / count;
}