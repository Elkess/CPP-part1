#include "PhoneBook.hpp"

int main()
{
	str 		input;
	PhoneBook 	phonebook;
	while (1) {
		std::cout << "Enter one of those Actions (ADD | SEARCH | EXIT): ";
		std::getline(std::cin, input);
		if (!strcmp("ADD", input.c_str()))
			add(&phonebook);
		else if (!strcmp("SEARCH", input.c_str()))
			search(&phonebook);
		else if (!strcmp("EXIT", input.c_str()))
			return (0);
		else
			return (err_printer("Invalid Action!"), 1);
	}
}
