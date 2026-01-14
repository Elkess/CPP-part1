#include "Harl.hpp"

void	printer(std::string str)
{
	std::cout << str << std::endl;
}

void Harl::debug(void)
{
	printer("[ DEBUG ]");
	printer("I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I really do!\n");
}

void Harl::info(void)
{
	printer("[ INFO ]");
	printer("I cannot believe adding extra bacon costs more money. You didn't put enough bacon in my burger! If you did, I wouldn't be asking for more!\n");
}

void Harl::warning(void)
{
	printer("[ WARNING ]");
	printer("I think I deserve to have some extra bacon for free.\nI've been coming for years, whereas you started working here just last month.\n");
}

void Harl::error(void)
{
	printer("[ ERROR ]");
	printer("This is unacceptable! I want to speak to the manager now.\n");
}

int	string_to_level(std::string &level)
{

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	for (int i = 0; i < 4; i++) {
		if (levels[i] == level)
			return (i);
	}
	return (INVALID);
}

void Harl::filter(std::string level)
{
	switch (string_to_level(level)) 
	{
		case DEBUG:
			debug();
			/* fallthrough */
		case INFO:
			info();
			/* fallthrough */
		case WARNING:
			warning();
			/* fallthrough */
		case ERROR:
			error();
			break;
		default:
			printer("[ Probably complaining about insignificant problems ]");
	}
}
