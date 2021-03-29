//
// Created by sajith on 3/29/21.
//

#pragma once

#include <iostream>
#include <memory>
#include <stdexcept>


class Weapon
{
public:
    virtual ~Weapon() = default;
    virtual void shoot() = 0;
};


class AK47 : public Weapon
{
    unsigned bullets = 30;

public:
    ~AK47() = default;

    void shoot() override
    {
        if (bullets)
        {
            std::cout << "AK-47 shot, bullets: " << --bullets << "\n";
        }
    }
};


class M16 : public Weapon
{
    unsigned bullets = 30;

public:
    ~M16() = default;

    void shoot() override
    {
        if (bullets)
        {
            std::cout << "M16 shot, bullets: " << --bullets << "\n";
        }
    }
};


class Player
{
    std::unique_ptr<Weapon> _weapon;

public:

    Player(std::unique_ptr<Weapon> weapon) : _weapon{std::move(weapon)}
    {
        if (not _weapon)
        {
            throw std::runtime_error{"null weapon"};
        }
    }

    Player(const Player &rhs) = default; // copy constructor
    Player(Player &&other) = default; // move constructor;

    void shoot()
    {
        _weapon->shoot();
    }
};

