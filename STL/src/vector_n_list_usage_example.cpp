//
// Created by sajith on 7/14/21.
//

#include <iostream>
#include <vector>
#include <list>
#include <string>
#include <fstream>


using namespace std;

const char *file_name = "../../STL/data/my_guests.txt";

//#define  USE_VECTOR
#define  USE_LIST

class guest
{

public:
    guest() {};

    ~guest() = default;;

    void set_gender(const string &in)
    {
        char c = in.c_str()[0];

        if (c == 'b' || c == 'B' || c == 'm' || c == 'M')
        {
            gender = "Boy";
        } else
        {
            gender = "Girl";
        }
    }

    string gender;
    string name;
    int age{};
};


#ifdef USE_VECTOR
typedef vector<guest> my_container;

#elif defined USE_LIST
typedef list<guest> my_container ;

#endif


void read_file(my_container *my_guests)
{

    string in_str;
    ifstream in_file(file_name);

    if (in_file.is_open())
    {
        guest temp;
        while (getline(in_file, in_str))
        {
            temp.name = in_str;

            getline(in_file, in_str);
            temp.set_gender(in_str);

            getline(in_file, in_str);
            temp.age = stoi(in_str);

            my_guests->push_back(temp);
        }

        in_file.close();
    } else
    {
        cout << "Unable to open file!\n\n";
    }
}

void print_guests(my_container *my_guests)
{
    cout << "-- Container content start --\n";

    for (auto & my_guest : *my_guests)
    {
        cout << "Name: " << my_guest.name << " Gender: " << my_guest.gender << " Age: " << my_guest.age << "\n";
    }

    cout << "-- Container content end  --\n";
}

int main()
{
    my_container *my_guests = new my_container;
    read_file(my_guests);
    print_guests(my_guests);


    return 0;
}
