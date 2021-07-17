//
// Created by sajith on 7/17/21.
//

#include <iostream>
#include <thread>
#include <chrono>
#include "Input.h"
#include "Keyboard.h"
#include "AccelAdataper.h"

void Game(Input *pInput)
{
    int count{5};

    while (count != 0)
    {
        std::cout << "========================================\n";

        if (pInput->Up())
        {
            std::cout << "Pitch Up\n";
        } else if (pInput->Down())
        {
            std::cout << "Pitch Down\n";
        } else
        {
            std::cout << "Plane is level\n";
        }

        if (pInput->Left())
        {
            std::cout << "Plane is turning left\n";
        } else if (pInput->Right())
        {
            std::cout << "Plane is turining right\n";
        } else
        {
            std::cout << "Plane is flying straight\n";
        }

        std::cout << "\n";
        std::this_thread::sleep_for(std::chrono::seconds(1));
        --count;
    }
}

int main()
{
//    Keyboard k;
//    Game(&k);

    AccelAdapter a;
    Game(&a);


    return 0;
}