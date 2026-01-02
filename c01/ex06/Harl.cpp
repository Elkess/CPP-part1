#include "Harl.hpp"
#include <iostream>

Harl::Harl() {}

void Harl::debug(void)
{
    std::cout << "[ DEBUG ]" << std::endl;
    std::cout << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!" << std::endl << std::endl;
}

void Harl::info(void)
{
    std::cout << "[ INFO ]" << std::endl;
    std::cout << "I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!" << std::endl << std::endl;
}

void Harl::warning(void)
{
    std::cout << "[ WARNING ]" << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I've been coming for years, whereas you started working here just last month." << std::endl << std::endl;
}

void Harl::error(void)
{
    std::cout << "[ ERROR ]" << std::endl;
    std::cout << "This is unacceptable! I want to speak to the manager now." << std::endl << std::endl;
}

void Harl::filter(std::string level)
{
    std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
    HarlMem funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
    int idx = -1;
    for (int i = 0; i < 4; ++i)
    {
        if (levels[i] == level)
        {
            idx = i;
            break;
        }
    }
    switch (idx)
    {
        case 0:
        case 1:
        case 2:
        case 3:
            break; // idx is valid (0..3)
        default:
            std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
            return;
    }
    for (int j = idx; j < 4; ++j)
    {
        (this->*funcs[j])();
    }
}
