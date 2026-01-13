#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Harl take one argument" << std::endl;
		return (1);
	}
	Harl	harlObj;
	harlObj.complain(av[1]);
	return (0);
}
