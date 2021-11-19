//
// Created by sajith on 11/18/21.
//

#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <algorithm>

using namespace std;

class Employee
{
    string m_firstname;
    string m_lastname;
    int m_salary{0};

public:

    Employee(string fname, string lname, int sal) : m_firstname(std::move(fname)), m_lastname(std::move(lname)),
                                                    m_salary(sal) {}

    friend bool operator<(Employee const &e1, Employee const &e2)
    {
        return tie(e1.m_firstname, e1.m_lastname) < tie(e2.m_firstname, e2.m_lastname);
    }

    int GetSalary() const { return m_salary; }
};

int gcd_custom(int a, int b)
{
    return (b == 0) ? abs(a) : gcd_custom(b, a % b);
}

bool emp_comp(Employee const &e1, Employee const &e2)
{
    return e1.GetSalary() > e2.GetSalary();
};

int main()
{
    vector<Employee> staff{{"FName2",  "LName2", 3000},
                           {"FName 1", "LName1", 2000},
                           {"FName4",  "LName4", 10000},
                           {"FName3",  "LName3", 2000},
                           {"FName5",  "LName5", 5000}};

    sort(staff.begin(), staff.end());
    auto comp = [](Employee const &e1, Employee const &e2)
    {
        return e1.GetSalary() > e2.GetSalary();
    };
    auto maxEmp = *max_element(staff.begin(), staff.end(), comp);

    stable_sort(staff.begin(), staff.end(), emp_comp);

    vector<int> v{1, 3, 4, 5, 6, 7, 7, 1, 4, 5, 6, -1, -4, 5 - 9};
    sort(v.begin(), v.end());

    int positive = *upper_bound(v.begin(), v.end(), 4);
    cout << positive << endl;

    int negative = *lower_bound(v.begin(), v.end(), 0);
    cout << negative << endl;

    random_device rdevice;
    mt19937 generator(rdevice());
    shuffle(v.begin(), v.end(), generator);

//    partial_sort(v.begin(), v.end(), v.begin() + 4);

    partial_sort(v.begin(), find(v.begin(), v.end(), 4), v.end());

    auto issorted_until = is_sorted_until(v.begin(), v.end());
    cout << *issorted_until << endl;

    vector<int> vcopy(4);
    partial_sort_copy(v.begin(), v.end(), vcopy.begin(), vcopy.end());

    shuffle(v.begin(), v.end(), generator);

    cout<< *(v.begin()+4)<<endl;
    nth_element(v.begin(), v.begin()+4, v.end());
    auto nthelement = (v.begin()+4);
    cout<<*nthelement<<endl;
    return 0;
}

