#include "PhoneBook.hpp"

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
	// parse Index 
	index = std::atoll(line.c_str());
	phonebook->find(index);
}

void	PhoneBook::display()
{
	row_printer("index", "First Name", "Last Name", "Nick name");
	for(size_t i=0; i<8; i++) {
		Contact ele = contacts[i];
		std::ostringstream oss;
		oss << ele.index;
		row_printer(oss.str(), ele.fname, ele.lname, ele.nname);
	}
}

void	PhoneBook::find(size_t index)
{
	Contact	target = contacts[index];
	printer("First Name: "+target.fname, 1);
	printer("Last Name: "+target.lname, 1);
	printer("Nickname: "+target.nname, 1);
	printer("Phone Number: "+target.phnumber, 1);
	printer("Darkest Secret: "+target.ds, 1);
}

void	add(PhoneBook 	*phonebook)
{
	Contact ele;
	str field;

	printer("First Name: ", 0);
	std::getline(std::cin, field);
	// parse fields
	ele.fname = field;

	printer("Last Name: ", 0);
	std::getline(std::cin, field);
	// parse fields
	ele.lname = field;

	printer("Nickname: ", 0);
	std::getline(std::cin, field);
	// parse fields
	ele.nname = field;

	printer("Phone Number: ", 0);
	std::getline(std::cin, field);
	// parse fields
	ele.phnumber = field;

	printer("Darkest Secret: ", 0);
	std::getline(std::cin, field);
	// parse fields
	ele.ds = field;
	phonebook->save(ele);
}

void	PhoneBook::save(Contact element)
{

	static size_t index;
	element.index = index % 8;
	contacts[element.index] = element;
	index++;
}

void	row_printer(str index, str fname, str lname, str nname)
{
	// parse fields
	std::cout << "|" << std::setw(10) << index << "|"
					 << std::setw(10) << fname << "|"
					 << std::setw(10) << lname << "|"
					 << std::setw(10) << nname << "|" 
			  << "\n";
}
