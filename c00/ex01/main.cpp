#include "PhoneBook.hpp"

int	check_end_of_file()
{
	if (std::cin.eof())
		return (err_printer(str("\nPlease do not use Ctrl-D to exit from the program!")), 1);
	return (0);
}

int	main()
{
	str 		input;
	PhoneBook	phonebook;
	while (1)
	{
		std::cout << "Enter one of those Actions (ADD | SEARCH | EXIT): ";
		std::getline(std::cin, input);
		if (check_end_of_file())
			return (0);
		if ("ADD" == input)
			add(&phonebook);
		else if ("SEARCH" == input)
			search(&phonebook);
		else if ("EXIT" == input)
			return (0);
	}
}
