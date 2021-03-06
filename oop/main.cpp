//
// Created by sajith on 3/28/21.
//

#include <iostream>
#include <string>
#include <memory>
#include "constructor_destructor.h"
#include "ball.h"
#include "employee.h"
#include "rectangle.h"
#include "pointer_reference.h"
#include "virtual_func.h"
#include "virtualconstructor.h"

void BallRun()
{
    Ball b{};
    b.Print();

    Ball b1{"blue"};
    b1.Print();

    Ball b2{5.0};
    b2.Print();

    Ball b3{"green", 19.0};
    b3.Print();

}

void EmployeeRun()
{
    Employee e{};
    Employee e2{"Tom"};

}

void SimpleRun()
{
    Simple simple{1};
    std::cout << simple.getID() << "\n";

    Simple *pSimple{new Simple{2}};
    std::cout << pSimple->getID() << "\n";

    delete pSimple;
}

void PointerReferenceRun()
{
    Derived derived{5};
    Base &rBase{derived};
    Base *pBase{&derived};

    std::cout << "derived is a " << derived.getName() << " and has a  value " << derived.getValue() << "\n";
    std::cout << "rBase is a " << rBase.getName() << " and has a  value " << rBase.getValue() << "\n";
    std::cout << "pBase is a " << pBase->getName() << " and has a  value " << pBase->getValue() << "\n";
}

void VirtualFunc()
{
    C c;
    A &rBase{c};

    std::cout << "rBase is a " << rBase.getName() << '\n';
}

void VirtualConstructor()
{
    Player player1{std::make_unique<M16>()};
    player1.shoot();
    Player player2(player1);

    player1.shoot();
    player1.shoot();
    player1.shoot();
    player1.shoot();
    player2.shoot();
    player2.shoot();
    player2.shoot();
    player2.shoot();
}

int main()
{
//    Rectange rectange{}; // not compile
//    BallRun();
//    EmployeeRun();
//    SimpleRun();
//    PointerReferenceRun();
//    VirtualFunc();

    VirtualConstructor();
    return 0;
}