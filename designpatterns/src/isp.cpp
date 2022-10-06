//
// Created by sajith on 10/3/22.
//

#include <bits/stdc++.h>

using namespace std;

struct Document
{
};

struct IPrinter
{
    virtual ~IPrinter() = default;

    virtual void print(Document &doc) = 0;
};

struct IScanner
{
    virtual ~IScanner() = default;

    virtual void scan(Document &doc) = 0;
};

struct IFax
{
    virtual void fax(Document &doc) = 0;
};

struct Printer : IPrinter
{
    void print(Document &doc) override
    {
        cout << "Printing...\n";
    }
};

struct Scanner : IScanner
{
    void scan(Document &doc) override
    {
        cout << "Scanning...\n";
    }
};

struct IMachine : IPrinter, IScanner
{
};

struct Machine : IMachine
{
    IScanner &scanner;
    IPrinter &printer;

    Machine(IScanner &s, IPrinter &p) : scanner{s}, printer{p}
    {}

    void print(Document &doc) override
    {
        printer.print(doc);
    }

    void scan(Document &doc) override
    {
        scanner.scan(doc);
    }
};

void api(Machine &machine)
{
    Document d;
    machine.print(d);
    machine.scan(d);

}

int main()
{
    Scanner scanner;
    Printer printer;

    Machine m(scanner, printer);
    api(m);
    return 0;
}