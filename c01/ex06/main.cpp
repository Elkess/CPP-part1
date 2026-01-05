#include "Harl.hpp"

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cerr << "Harl take one argument" << std::endl;
		return (1);
	}
	Harl	harlObj;
	harlObj.filter(av[1]);
	return (0);
}
