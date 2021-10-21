//
// Created by sajith on 10/20/21.
//

#include <iostream>

#define SQRT(x) (x*x)
#define MSG(x) #x

#define MAX(x, y) ((x>y) ? x: y)

class A
{

public:
    ~A()
    {
        throw 32;
    }
};

using namespace std;

int main()
{
    cout << SQRT(10) << endl;
    cout << SQRT(10 + 10 + 10) << endl;
    cout << MSG(Hello) << endl;

    cout << MAX(10, 20) << endl;
    cout << MAX(10 + 10, 20 + 10) << endl;

//    try
//    {
//        A a;
//        throw 43;
//    }catch (int e){
//        cout<< e<< endl;
//    }

    int arr[] = {1,2,3,4,5,6};
    cout<< sizeof(arr)/ sizeof(arr[0])<< endl;

    cout<<(1+3)[arr] << endl;
    cout<<(arr+1)[2] << endl;
    cout<<(arr)[2] << endl;


//    unsigned char  limit = 150;
//
//    for(unsigned  char i = 0; i< 2 * limit; ++i)
//    {
//        cout<< i<< endl;
//    }

    int *p = arr;
    for (int i = 0; i < 6; ++i)
    {
        cout<< i[p]<<" " << i[arr]<< endl;
    }
    return 0;
}