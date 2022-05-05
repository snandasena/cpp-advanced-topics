//
// Created by sajith-csi on 5/5/2022.
//

#ifndef ADVANCED_TOPICS_MAIN_H
#define ADVANCED_TOPICS_MAIN_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <iostream>

class Contact
{
public:
    Contact(const char *name, const char *address, const char *tel);

    ~Contact();

    const char *Name() const { return name; }

    const char *Address() const { return address; }

    const char *Tel() const { return tel; }

    friend std::ostream &operator<<(std::ostream &os, Contact &c);

private:

    char *name;
    char *address;
    char *tel;
};

class ContactDir
{
public:
    ContactDir(const int max_size);
    ~ContactDir();

    void Insert(const Contact &);
    void Delete(const char *name);
    Contact *Find(const char *name);

    friend std::ostream &operator<<(std::ostream &, ContactDir &);

private:
    int LookUp(const char *name);
    Contact *contacts;
    int dir_size;
    int max_size;
};

Contact::Contact(const char *name, const char *address, const char *tel)
{
    Contact::name = new char[strlen(name)] + 1;
    Contact::address = new char[strlen(address)] + 1;
    Contact::tel = new char[strlen(tel)] + 1;
    strcpy(Contact::name, name);
    strcpy(Contact::address, address);
    strcpy(Contact::tel, tel);
}

Contact::~Contact()
{
    delete name;
    delete address;
    delete tel;
}

std::ostream &operator<<(std::ostream &os, Contact &c)
{
    os << "( " << c.name << " , " << c.address << " , " << c.tel << " )\n";
    return os;
}




#endif //ADVANCED_TOPICS_MAIN_H
