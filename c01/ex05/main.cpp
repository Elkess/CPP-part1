#include "Harl.hpp"

int main()
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	Harl	harlObj;
	for(int i = 0; i < 4; i++)
	{
		harlObj.complain(levels[i]);
	}
	return (0);
}
