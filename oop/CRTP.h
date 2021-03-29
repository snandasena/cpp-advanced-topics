//
// Created by sajith on 3/29/21.
//

#pragma once

#include <iostream>

template<typename SpecificWeapon>
class Weapon
{
public:
    void shoot()
    {
        implementation().shoot();
    }

private:
    SpecificWeapon &implementation()
    {
        return *static_cast<SpecificWeapon *>(this);
    }
};

class M16 : public Weapon<M16>
{
public:
    void shoot()
    {
        std::cout << "M16\n";
    }
};

class AK47 : public Weapon<AK47>
{
public:
    void shoot()
    {
        std::cout << "AK-47\n";
    }
};


template<typename SpeficiWeapon>
void run(Weapon<SpeficiWeapon> &weapon)
{
    weapon.shoot();
}


