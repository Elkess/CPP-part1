#include "Harl.hpp"

void	printer(std::string str)
{
	std::cout << str << std::endl;
}

void Harl::debug(void)
{
	printer("DEBUG: I love having extra bacon for my 7XL-double-cheese-triple-pickle-specialketchup burger. I really do!");
}

void Harl::info(void)
{
	printer("INFO: I cannot believe adding extra bacon costs more money. You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!");
}

void Harl::warning(void)
{
	printer("WARNING: I think I deserve to have some extra bacon for free. I’ve been coming for years, whereas you started working here just last month.");
}

void Harl::error(void)
{
	printer("ERROR: This is unacceptable! I want to speak to the manager now.");
}

void Harl::complain(std::string level)
{
	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};
	HarlMem funcs[4] = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};
	for (int i = 0; i < 4; ++i)
	{
		if (levels[i] == level)
		{
			(this->*funcs[i])();
			return ;
		}
	}
	std::cerr << "Use a valid level please: DEBUG | INFO | WARNING | ERROR" << std::endl;
}
