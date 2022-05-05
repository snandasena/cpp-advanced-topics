
#include "main.h"

const int bin_size = 16;
using namespace std;

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

int main()
{
    RawBook r1("%AA. Peters\0%TBlue Earth\0%PPhedra\0%CSydney\0%Y1981\0\n");
    RawBook r2("%TPregnancy\0%AF. Jackson\0%Y1987\0%PMiles\0\n");

    printf("%s\n", r2->title);
    Book *bk = &r2;
    printf("%s\n", bk->title);
    return 0;
}
