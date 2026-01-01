#include "Harl.hpp"
#include <iostream>

int main(int ac, char **av)
{
    if (ac != 2)
    {
        std::cerr << "Usage: ./harl2 <LEVEL>" << std::endl;
        return 1;
    }
    Harl h;
    h.complain(av[1]);
    return 0;
}
