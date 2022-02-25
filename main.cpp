

#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

struct A
{
    void disp()
    {
        cout << "Base A\n";
    }
};


struct B : A
{
    void disp()
    {
        cout << "Base B\n";
    }
};

struct C : B
{
    void disp()
    {
        cout << "C child\n";
    }
};


struct D : A
{
    void disp()
    {
        cout << "Base D";
    }
};

struct F : virtual B, virtual D
{
    void disp()
    {
        B::disp();
    }
};

int BinaryGap(int N)
{
    int y = N;
    int i = 0;
    while (y != 0)
    {
        ++i;
        y /= 2;
    }

    int start = 0;
    int end = 0;
    bool flag{false};
    int x = 1;
    int k = 1;
    for (int j = 0; j <= i; ++j)
    {
        y = (N & x);
        if (!flag && y != 0)
        {
            flag = true;
            start = j;
            k = x;
        }

        if (y != 0)
        {
            end = j;
        }

        x *= 2;
    }

    if (start == end) return 0;
    x = k;
    int curr = 0;
    int ans = 0;
    for (int j = start; j <= end; ++j)
    {
        y = (N & x);
        if (y == 0)
        {
            ++curr;
        }
        else
        {
            ans = max(curr, ans);
            curr = 0;
        }

        x *= 2;
    }
    return ans;
}


int missing_number(vector<int> &v)
{
    int N = v.size();
    sort(v.begin(), v.end());
    for (int i = 1; i <= N; ++i)
    {
        if (i != v[i - 1]) return i;
    }

    return N + 1;
}


void ptest(int *pVal)
{
    *pVal = 10;
}

void reftest(int &pVal)
{
    pVal = 50;
}


struct PStruct
{
    int x;
    int y;
};

void pStructTest(PStruct &pStruct)
{
    pStruct.x = 10;
    pStruct.y = 50;
}

PStruct *Get()
{
    PStruct ref{};
    ref.x = 9999;
    ref.y = 66666;
    auto p = make_shared<PStruct>(ref);
    return p.get();
}

class Account
{
    double balance;
public:

    Account(double initBal) : balance{initBal} {}

    double GetBalance() const { return balance; }
};

double Account = 23.999;


struct X
{
    char a; // 1+3
    char _pad1[3];
    int b; // 4
    short c; // 2
    char d; // 1+1
    char _pad2[1];
} bar[3];

class CX
{
    char a;
    int b;
    short c;
    char d;

    int temp() { return 0; }
};

union UX
{
    int b;
    short c;
    double e;
    char d;
};


class Animal
{
    string name;
    string type;

public:
    Animal(string n, string t) : name{move(n)}, type{move(t)} {}

    Animal(Animal &animal) = default;

    Animal &operator=(Animal const &other) = default;

    virtual void Noise()
    {
        cout << "Animal Noise\n";
    };

    virtual ~Animal()
    {
        cout << "Deleted Animal\n";
    }

    string GetName() const { return name; }

    string GetType() const { return type; }
};

class Cat : public Animal
{
    string bread;

public:
    Cat(string b, string n, string t) : Animal(move(n), move(t)), bread{move(b)} {}

    ~Cat()
    {
        cout << "Deleted Cat\n";
    }

    void Noise() override
    {
        cout << "Cat Noise\n";
    }

    string GetBread() const { return bread; }
};


class AnimalBest
{
    string name;
    string type;

public:

    AnimalBest(string n, string t) : name{move(n)}, type{move(t)} {}

    virtual void Noise()
    {
        cout << "Animal Noise\n";
    }

    virtual ~AnimalBest() = default;

    string GetName() const { return name; }

    string GetType() const { return type; }
};

class CatBest : public AnimalBest
{
    string bread;
public:
    CatBest(string b, string n, string t) : AnimalBest(move(n), move(t)), bread{move(b)} {}

    void Noise() override
    {
        cout << "Cat Noise\n";
    }

    string GetBread() const { return bread; }
};

void AnimalBestTestAPI()
{
    unique_ptr<CatBest> cat = make_unique<CatBest>("B", "N", "T");
    cout << cat->GetName() << endl;
    cout << cat->GetType() << endl;
}

class AC
{
    int a; // 4
    char c; // 1
    char ac; // 1
    int d; // 4

};

int main()
{

//    Cat cat("Bengal", "Puffy", "Tiger"); // value
//
//    cout << cat.GetName() << endl;
//    cout << cat.GetType() << endl;
//    cout << cat.GetBread() << endl;


//    Animal *pCat = new Cat("Siberia", "Alex", "Tiger");
//    cout<<pCat->GetName()<<endl;
//    cout<<pCat->GetType()<<endl;
//    delete pCat;

//    unique_ptr<Animal> uptrCat = make_unique<Cat>("Siberia", "Alex", "Tiger");
//    cout<<uptrCat->GetName()<<endl;
//    cout<<uptrCat->GetType()<<endl;

//    unique_ptr<Cat> uptrCat = make_unique<Cat>("Siberia", "Alex", "Tiger");
//    cout<<uptrCat->GetName()<<endl;
//    cout<<uptrCat->GetType()<<endl;
//    cout<<uptrCat->GetBread()<<endl;

//    unique_ptr<Animal> uptrCat = make_unique<Animal>("Alex", "Tiger");
//    cout << uptrCat->GetName() << endl;
//    cout << uptrCat->GetType() << endl;
//    cout << uptrCat->GetBread() << endl;

//    AnimalBestTestAPI();
//    cout << boolalpha;
//    cout << is_standard_layout<CatBest>() << endl;
//    cout << is_trivial<CatBest>() << endl;
//    cout << is_trivial<CX>() << endl;
//    cout << is_standard_layout<CX>() << endl;

//    cout<<sizeof (AC )<<endl;
    cout<<sizeof (string )<<endl;

    cout<< sizeof (string_view)<<endl;

    return 0;

}

// 14 + 13 = 27