#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <cstdlib>

class PhoneBook {
private:
	Contact contacts[8];
public:
	void save(Contact element);
	void find(size_t index);
	void display();
};

void	printer(str s, int flag);
void	err_printer(str s);
void	add(PhoneBook *phonebook);
void	search(PhoneBook *phonebook);
void	row_printer(str index, str first_name, str last_name, str nickname);
int		check_end_of_file();

#endif
