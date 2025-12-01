#include "PhoneBook.hpp"
#include <iostream>

void	err_printer(str s)
{
	std::cerr << s << "\n";
}

void	printer(str s, int flag)
{
	if (flag)
		std::cout << s << "\n";
	else
		std::cout << s;
}

void	search(PhoneBook 	*phonebook)
{
	phonebook->display();
	size_t	index;
	str		line;

	printer("Search by index: ", 0);
	std::getline(std::cin, line);

	index = std::atoll(line.c_str());
	if (index >=0 && index <=7)
		err_printer(str("Invalid Index [0-9]!"));
	else
		phonebook->find(index);
}

void	PhoneBook::display()
{
	row_printer("index", "First Name", "Last Name", "Nick name");
	for(size_t i=0; i<8; i++) {
		Contact ele = contacts[i];
		std::ostringstream oss;
		oss << ele.get_index();
		row_printer(oss.str(), ele.get_first_name(), ele.get_last_name(), ele.get_nickname());
	}
}

void	PhoneBook::find(size_t index)
{
	Contact	target = contacts[index];
	printer("First Name: "+target.get_first_name(), 1);
	printer("Last Name: "+target.get_last_name(), 1);
	printer("Nickname: "+target.get_nickname(), 1);
	printer("Phone Number: "+target.get_phone_number(), 1);
	printer("Darkest Secret: "+target.get_darkest_secret(), 1);
}

void	add(PhoneBook 	*phonebook)
{
	Contact ele;
	str field;

	printer("First Name: ", 0);
	std::getline(std::cin, field);
	// parse fieldarkest_secret
	ele.set_first_name(field);

	printer("Last Name: ", 0);
	std::getline(std::cin, field);
	// parse fieldarkest_secret
	ele.set_last_name(field);

	printer("Nickname: ", 0);
	std::getline(std::cin, field);
	// parse fieldarkest_secret
	ele.set_nickname(field);

	printer("Phone Number: ", 0);
	std::getline(std::cin, field);
	// parse fieldarkest_secret
	ele.set_phone_number(field);

	printer("Darkest Secret: ", 0);
	std::getline(std::cin, field);
	// parse fieldarkest_secret
	ele.set_darkest_secret(field);
	phonebook->save(ele);
}

void	PhoneBook::save(Contact element)
{

	static size_t index;
	element.set_index(index % 8);
	contacts[element.get_index()] = element;
	index++;
}

void	row_printer(str index, str first_name, str last_name, str nickname)
{
	// parse fieldarkest_secret
	std::cout << "|" << std::setw(10) << index << "|"
					 << std::setw(10) << first_name << "|"
					 << std::setw(10) << last_name << "|"
					 << std::setw(10) << nickname << "|" 
			  << "\n";
}
