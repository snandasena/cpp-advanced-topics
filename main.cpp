

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>
#include <memory>

using namespace std;

//class Contact
//{
//public:
//    Contact(const char *name, const char *address, const char *tel);
//
//    ~Contact();
//
//    const char *Name() const { return name; }
//
//    const char *Address() const { return address; }
//
//    const char *Tel() const { return tel; }
//
//    friend std::ostream &operator<<(std::ostream &os, Contact &c);
//
//private:
//
//    char *name;
//    char *address;
//    char *tel;
//};
//
//class ContactDir
//{
//public:
//    ContactDir(const int max_size);
//
//    ~ContactDir();
//
//    void Insert(const Contact &);
//
//    void Delete(const char *name);
//
//    Contact *Find(const char *name);
//
//    friend std::ostream &operator<<(std::ostream &, ContactDir &);
//
//private:
//    int LookUp(const char *name);
//
//    Contact **contacts;
//    int dir_size;
//    int max_size;
//};
//
//Contact::Contact(const char *name, const char *address, const char *tel)
//{
//    Contact::name = new char[strlen(name) + 1];
//    Contact::address = new char[strlen(address) + 1];
//    Contact::tel = new char[strlen(tel) + 1];
//    strcpy(Contact::name, name);
//    strcpy(Contact::address, address);
//    strcpy(Contact::tel, tel);
//}
//
//Contact::~Contact()
//{
//    delete name;
//    delete address;
//    delete tel;
//}
//
//std::ostream &operator<<(std::ostream &os, Contact &c)
//{
//    os << "( " << c.name << " , " << c.address << " , " << c.tel << " )\n";
//    return os;
//}
//
//ContactDir::ContactDir(const int mx)
//{
//    typedef Contact *ContactPtr;
//    dir_size = 0;
//    max_size = mx;
//    contacts = new ContactPtr[max_size];
//}
//
//ContactDir::~ContactDir()
//{
//    for (int i = 0; i < dir_size; ++i)
//    {
//        delete contacts[i];
//    }
//    delete[] contacts;
//}
//
//void ContactDir::Insert(const Contact &c)
//{
//    if (dir_size < max_size)
//    {
//        int idx = LookUp(c.Name());
//        if (idx > 0 && strcmp(c.Name(), contacts[idx]->Name()) == 0)
//        {
//            delete contacts[idx];
//        }
//        else
//        {
//            for (int i = dir_size; i > idx; --i)
//            {
//                contacts[i] = contacts[i - 1];
//            }
//            ++dir_size;
//        }
//        contacts[idx] = new Contact(c.Name(), c.Address(), c.Tel());
//    }
//}
//
//void ContactDir::Delete(const char *name)
//{
//    int idx = LookUp(name);
//    if (idx < dir_size)
//    {
//        delete contacts[idx];
//        --dir_size;
//        for (int i = idx; i < dir_size; ++i)
//        {
//            contacts[i] = contacts[i + 1];
//        }
//    }
//}
//
//Contact *ContactDir::Find(const char *name)
//{
//    int idx = LookUp(name);
//    return (idx < dir_size && strcmp(contacts[idx]->Name(), name) == 0) ? contacts[idx] : nullptr;
//}
//
//int ContactDir::LookUp(const char *name)
//{
//    for (int i = 0; i < dir_size; ++i)
//    {
//        if (strcmp(contacts[i]->Name(), name) == 0) return i;
//    }
//    return dir_size;
//}
//
//
//std::ostream &operator<<(std::ostream &os, ContactDir &c)
//{
//    for (int i = 0; i < c.dir_size; ++i)
//    {
//        os << *(c.contacts[i]) << '\n';
//    }
//    return os;
//}
//
//
//class SmartDir : public ContactDir
//{
//public:
//    SmartDir(const int mx) : ContactDir(mx) {}
//
//    Contact *Recent();
//
//    Contact *Find(const char *name);
//
//private:
//
//    char *recent = nullptr;
//};
//
//
//Contact *SmartDir::Recent()
//{
//    return recent == nullptr ? nullptr : ContactDir::Find(recent);
//}
//
//Contact *SmartDir::Find(const char *name)
//{
//    Contact *c = ContactDir::Find(name);
//    if (c != nullptr)
//    {
//        recent = (char *)c->Name();
//    }
//    return c;
//}


class A
{
private:
    int x{10};

    void Fx() {};
protected:
    int y{20};

    void Fy() {}

public:
    int z{30};

    void Fz() {}

public:

    A()
    {
        printf("A called\n");
    }

    ~A()
    {
        printf("A deleted\n");
    }
};

class B : public A
{
public:
    B()
    {
        printf("%d\n", A::z);
        printf("B called\n");
    }

    ~B()
    {
        printf("B deleted\n");
    }
};

class C : protected A
{
public:
    C()
    {
        printf("%d\n", A::z);
        printf("C called\n");
    }

    ~C()
    {
        printf("C deleted\n");
    }
};

class D : private A
{

public:


    D()
    {
        printf("%d\n", A::z);
        printf("D called");
    }


};

int main()
{

    {
        C *c = new C();
    }

    return 0;
}
