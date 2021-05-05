#include <iostream>

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
    return 0;

}