//
// Created by sajith on 3/23/21.
//

#include <iostream>
#include <stdexcept>
#include <memory>

class Weapon
{
public:
    virtual ~Weapon() = default;

    virtual void shoot() = 0;
};

class M16 : public Weapon
{
public:
    ~M16() = default;

    void shoot() override
    {
        std::cout << "M16\n";
    }
};


class AK47 : public Weapon
{
public:
    ~AK47() = default;

    void shoot() override
    {
        std::cout << "AK47\n";
    }
};


enum class WeaponType
{
    AK47,
    M16
};


struct WeaponFactory
{
    static std::unique_ptr<Weapon> create(const WeaponType type)
    {
        switch (type)
        {
            case WeaponType::M16:
                return std::make_unique<M16>();

            case WeaponType::AK47:
                return std::make_unique<AK47>();

            default:
                throw std::logic_error{"Invalid type"};
        }
    }
};


int main()
{
    auto weapon = WeaponFactory::create(WeaponType::AK47);
    weapon->shoot();

    return 0;
}