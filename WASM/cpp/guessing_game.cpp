//
// Created by sajith on 6/18/21.
//

#include <cstdlib>
#include <iostream>

#include <emscripten.h>


void guessGame(void *_guess)
{
    const auto guess = static_cast<unsigned int *>(_guess);
    unsigned int userGuess = 0;
    std::cout << "Please enter a guess (1:100) \n";

    std::cin >> userGuess;
    std::cout << "User input: " << userGuess << "\n";
    if (userGuess > 100 || userGuess < 1)
    {
        std::cerr << "Invalid input\n";
        delete guess;
        emscripten_cancel_main_loop();
    }
    else if (userGuess > *guess)
    {
        std::cout << "Too high\n";
    }
    else if (userGuess < *guess)
    {
        std::cout << "Too low\n";
    }
    else
    {
        std::cout << "Correct!\n";
        emscripten_cancel_main_loop();
    }

}

int main()
{
    srand(time(nullptr));
    unsigned int *guess = new unsigned int(rand() % 100 + 1);
    std::cout << "Guessed: " << *guess << "\n";

    emscripten_set_main_loop_arg(guessGame, guess, 0, false);

    return 0;
}