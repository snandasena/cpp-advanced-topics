//
// Created by sajith-csi on 6/1/2022.
//

#include "base.h"

void OutputStreamTest()
{
    ofstream file{"temp.txt", ios::app};
    if (!file)
    {
        cerr << "ERROR\n";
        return;
    }

    file << "Added a text\n";
    file.close();
}

void InputStreamTest()
{
    ifstream file{"temp.txt"};
    if (!file)
    {
        cerr << "ERROR!\n";
        return;
    }

}

struct Date
{
    int d;
    int m;
    int y;
};

void OutputBinTest()
{
    Date dt{10, 12, 2000};
    ofstream file{"data.dat", ios::binary};
    file.write((char *) &dt, sizeof(dt));
    file.close();
}

void CountTest()
{
    time_t tm{time(nullptr) + 10};
    cout << "Please wait..." << endl;
    while (time(nullptr) < tm);
    cout << "\nAll done\n";
}

void TestOutManipulation()
{
    cout << "Regular " << '\033' << '[' << "Boldface" << endl;
}

int main()
{
//    OutputStreamTest();
//    OutputBinTest();
//        CountTest();
//    TestOutManipulation();

    int  t;
    cin>>t;

    cout<<"INPUT "<<t<<'\n';

    return 0;
}