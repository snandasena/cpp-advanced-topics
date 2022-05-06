
#include "main.h"

const int bin_size = 16;


class Binary
{
public:
    Binary(const char *);

    Binary(unsigned int);

    operator int(); // type convertion

    friend Binary operator+(const Binary &, const Binary &);

    void Print();

    friend Binary operator++(Binary &);

    friend Binary operator++(Binary &, int);

private:
    char bits[bin_size];
};

Binary::Binary(const char *num)
{
    int iSrc = strlen(num) - 1;
    int iDes = bin_size - 1;

    while (iSrc >= 0 && iDes >= 0)
    {
        bits[iDes--] == (num[iSrc--] == '0' ? '0' : '1');
    }

    while (iDes >= 0)
    {
        bits[iDes--] = '0';
    }
}

Binary::Binary(unsigned int num)
{
    for (int i = bin_size - 1; i >= 0; --i)
    {
        bits[i] = (num % 2 == 0 ? '0' : '1');
        num >>= 1;
    }
}

Binary operator+(const Binary &n1, const Binary &n2)
{
    unsigned carry = 0;
    unsigned value;
    Binary res = "0";

    for (int i = bin_size - 1; i >= 0; --i)
    {
        value = (n1.bits[i] == '0' ? 0 : 1) + (n2.bits[i] == '0' ? 0 : 1) + carry;
        res.bits[i] = (value % 2 == 0 ? '0' : '1');
        carry = value >> 1;
    }
    return res;
}

Binary::operator int()
{
    unsigned value = 0;
    for (int i = bin_size - 1; i >= 0; --i)
    {
        value = (value << 1) + (bits[i] == '0' ? 0 : 1);
    }
    return value;
}

void Binary::Print()
{
    char str[bin_size + 1];
    strncpy(str, bits, bin_size);
    str[bin_size] = '\0';
    printf("%s\n", str);
}

Binary operator++(Binary &b)
{
    return b = b + Binary(1);
}

Binary operator++(Binary &b, int)
{
    Binary m = b;
    b = b + Binary(1);
    return m;
}

class B;

class Point;

class A
{
public:

    B &operator->(void);
};

class B
{
public:
    Point *operator->(void);

};

class Point
{
public:

    int x;
    int y;
};

struct Book
{
    char *raw;
    char *author;
    char *title;
    char *publisher;
    char *city;
    short vol;
    short year;
};

Book defBook = {
        "raw", "Author?", "Title?", "Publisher?", "City?", 0, 0
};

const int cache_size = 10;

class RawBook
{
public:

    RawBook(char *str) : data(str) {}

    Book *operator->();

    Book &operator*();

    Book *operator&();

private:
    Book *RawToBook();

    char *data;
    static Book *cache;
    static short curr;
    static short used;
};

Book *RawBook::cache = new Book[cache_size];
short RawBook::curr = 0;
short RawBook::used = 0;

Book *RawBook::RawToBook()
{
    char *str = data;
    for (int i = 0; i < used; ++i)
    {
        if (data == cache[i].raw)
        {
            return cache + i;
        }
    }

    curr = used < cache_size ? used++ : (curr < 9 ? ++curr : 0);
    Book *bk = cache + curr;
    *bk = defBook;

    bk->raw = data;

    for (;;)
    {
        while (*str++ != '%');

        switch (*str++)
        {
            case 'A':
                bk->author = str;
                break;
            case 'T':
                bk->title = str;
                break;
            case 'P':
                bk->publisher = str;
                break;
            case 'C':
                bk->city = str;
                break;
            case 'V':
                bk->vol = atoi(str);
                break;
            case 'Y':
                bk->year = atoi(str);
                break;
        }

        while (*str++ != '\0');
        if (*str == '\n')break;
    }
    return bk;
}

Book *RawBook::operator->() { return RawToBook(); }

Book &RawBook::operator*() { return *RawToBook(); }

Book *RawBook::operator&() { return RawToBook(); }


#include <bits/stdc++.h>

using namespace std;


int solution(vector<int> &nums)
{
    // write your code in C++14 (g++ 6.2.0)
    vector<int> a(10000001, 0);
    for (const auto &item: nums)
    {
        if (item > 0)
        {
            a[item] = 1;
        }
    }
    size_t i = 1;
    for (; i <= a.size(); ++i)
    {
        if (a[i] == 0) return i;
    }
    return i + 1;
}

int main()
{
    ContactDir dir(10);
    dir.Insert(Contact("Mary", "11 South Rd", "282 1324"));
    dir.Insert(Contact("Peter", "9 Port Rd", "678 9862"));
    dir.Insert(Contact("Jane", "321 Yara Ln", "982 6252"));
    dir.Insert(Contact("Jack", "42 Wayne St", "663 2989"));
    dir.Insert(Contact("Fred", "2 High St", "458 2324"));
    cout << dir;
    cout << "Find Jane: " << *dir.Find("Jane") << '\n';
    dir.Delete("Jack");
    cout << "Deleted Jack\n";
    cout << dir;

    return 0;
}
