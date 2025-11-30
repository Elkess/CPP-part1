#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>

class PhoneBook {
	private:
		Contact	contacts[8];
	public:
		void	save(Contact element);
		void	find(size_t index);
		void	display();
};

typedef std::string	str;

void	printer(str s, int flag);
void	err_printer(str s);
void	add(PhoneBook 	*phonebook);
void	search(PhoneBook 	*phonebook);
void	row_printer(str index, str fname, str lname, str nname);
#endif