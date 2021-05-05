#include <iostream>
#include <vector>

using namespace std;


int *getpointer()
{

//    int *i = new int (10);
    int *i = (int *) malloc(sizeof(int) * 1);
    *i = 100000;
    return i;
}


int main()
{
    int *j = getpointer();
    cout << *j << endl;
    free(j);
    vector<int *> v;
    int a = 10;
    int b = 20;
    int c = 30;

    v.push_back(&a);
    v.push_back(&b);
    v.push_back(&c);

    for (int i = 0; i < 3; ++i)
    {
        cout << *v[i] << endl;
    }

    return 0;

}