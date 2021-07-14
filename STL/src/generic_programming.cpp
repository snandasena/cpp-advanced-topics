//
// Created by sajith on 7/13/21.
//

#include <iostream>

using namespace std;


template<typename T>
int size_in_bits(const T &t)
{
    return sizeof(t) * 8;
}

int main()
{
    cout<<size_in_bits(10)<<endl;
    cout<<size_in_bits(10.04)<<endl;
    cout<<size_in_bits(10.f)<<endl;
    cout<<size_in_bits('a')<<endl;




    return 0;
}