#include "PhoneBook.hpp"

int	check_end_of_file()
{
	if (std::cin.eof())
		return (err_printer(str("\nPlease do not use Ctrl-D to exit from the program!")), 1);
	return (0);
}

int main()
{
	str 		input;
	PhoneBook 	phonebook;
	while (1)
	{
		std::cout << "Enter one of those Actions (ADD | SEARCH | EXIT): ";
		std::getline(std::cin, input);
		if (check_end_of_file())
			return (0);
		if (!strcmp("ADD", input.c_str()))
			add(&phonebook);
		else if (!strcmp("SEARCH", input.c_str()))
			search(&phonebook);
		else if (!strcmp("EXIT", input.c_str()))
			return (0);
	}
}
