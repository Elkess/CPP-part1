#include <iostream>

int	main(int ac, char **av)
{
	if (ac != 3)
	{

		return (0);
	}
	std::cerr << "Only three parameters required, plz!" 
			<< std::endl;
	return (1);
}
