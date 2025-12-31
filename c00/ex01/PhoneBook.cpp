#include "PhoneBook.hpp"

PhoneBook::PhoneBook()
{
    count = 0;
}

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

int	is_made_of_numbers(str string)
{
	size_t	i = 0;
	while (string[i] >= '0' && string[i] <= '9')
		i++;
	if (!i || string.length() != i)
		return (1);
	return (0);
}

int	one_number_with_zeros_ahead(str line)
{
	size_t	i = 0;
	size_t	len = line.length();
	while(line[i]=='0')
		i++;
	if (len - i == 1 || len - i == 0)
		return (line[len-1] - 48);
	else
		return (-1);

}

int	parse_index(str line, size_t *index)
{
	int	holder = 0;
	if (is_made_of_numbers(line))
		return (1);
	holder = one_number_with_zeros_ahead(line);
	if (holder >= 0 && holder <= 7)
	{
		*index = holder;
		return (0);
	}
	return (1);
}

bool	PhoneBook::is_empty()
{
    return contacts[0].get_first_name().empty();
}

void	search(PhoneBook 	*phonebook)
{
	if (phonebook->is_empty())
	{
		err_printer("PhoneBook is empty! Add some contacts first.");
        return;
	}
	phonebook->display();
	size_t	index = 0;
	str		line;

	int	flag = 1;
	while (flag) {
		printer("Search by index: ", 0);
		std::getline(std::cin, line);
		if (check_end_of_file())
			std::exit(0);
		if ((flag = parse_index(line, &index)))
			err_printer(str("Invalid Index [0-9]!"));
	}
	phonebook->find(index);
}

void	PhoneBook::find(size_t index)
{
	Contact	target = contacts[index];
	if (target.get_first_name().empty())
	{
		err_printer(str("This contact does not exist yet!"));
		return ;
	}
	printer("First Name: " + target.get_first_name(), 1);
	printer("Last Name: " + target.get_last_name(), 1);
	printer("Nickname: " + target.get_nickname(), 1);
	printer("Phone Number: " + target.get_phone_number(), 1);
	printer("Darkest Secret: " + target.get_darkest_secret(), 1);
}

str	truncate(str field)
{
	if (field.length() > 10)
		field = field.substr(0, 9) + '.';
	return (field);
}

void	row_printer(str index, str first_name, str last_name, str nickname)
{
	std::cout << "|" << std::setw(10) << index << "|"
					 << std::setw(10) << truncate(first_name) << "|"
					 << std::setw(10) << truncate(last_name) << "|"
					 << std::setw(10) << truncate(nickname) << "|" 
			  << "\n";
}

void	PhoneBook::display()
{
	row_printer("index", "First Name",
		"Last Name", "Nick name");
	for(size_t i=0; i < count; i++) {
		Contact ele = contacts[i];
		std::ostringstream oss;
		oss << ele.get_index();
		row_printer(oss.str(), ele.get_first_name(),
			ele.get_last_name(), ele.get_nickname());
	}
}

int	parse_phone_number(str field)
{
	if (!is_made_of_numbers(field) && field.length() == 10)
		return (0);
	return (err_printer(str("Re-enter it's not valid")), 1);
}

int	parse_txt_field(str field)
{
	size_t	i = 0;
	size_t	space_count = 0;
	while (field[i]) {
		if (std::isalpha(field[i]))
			i++;
		else if(std::isspace(field[i])) {
			space_count++;
			i++;
		} else {
			err_printer(str("Re-enter it's not valid"));
			return (1);
		}
	}
	if (space_count == field.length())
		return (err_printer(str("Re-enter it's not valid")), 1);
	return (0);
}

str	trim(str field)
{
	str trimed;
	size_t	i = 0;

	while (std::isspace(field[i])) {
		i++;
	}
	while (field[i]) {
		if (!std::isspace(field[i]))
			trimed += field[i];
		else if (std::isspace(field[i]) && std::isalpha(field[i+1]))
			trimed += " ";
		i++;
	}
	return (trimed);
}

void	add(PhoneBook 	*phonebook)
{
	Contact ele;
	str field;

	int	flag = 1;
	while (flag) {
		printer("First Name: ", 0);
		std::getline(std::cin, field);
		if (check_end_of_file())
			std::exit(0);

		flag = parse_txt_field(field);
	}
	field = trim(field);
	ele.set_first_name(field);
	flag = 1;
	while (flag) {
		printer("Last Name: ", 0);
		std::getline(std::cin, field);
		if (check_end_of_file())
			std::exit(0);

		flag = parse_txt_field(field);
	}
	field = trim(field);
	ele.set_last_name(field);

	flag = 1;
	while (flag) {
		printer("Nickname: ", 0);
		std::getline(std::cin, field);
		if (check_end_of_file())
			std::exit(0);

		flag = parse_txt_field(field);
	}
	field = trim(field);
	ele.set_nickname(field);
	flag = 1;
	while (flag) {
		printer("Phone Number: ", 0);
		std::getline(std::cin, field);
		if (check_end_of_file())
			std::exit(0);

		flag = parse_phone_number(field);
	}
	ele.set_phone_number(field);

	flag = 1;
	while (flag) {
		printer("Darkest Secret: ", 0);
		std::getline(std::cin, field);
		if (check_end_of_file())
			std::exit(0);

		flag = parse_txt_field(field);
	}
	field = trim(field);
	ele.set_darkest_secret(field);
	phonebook->save(ele);
}

void	PhoneBook::save(Contact element)
{
	static size_t index;
	element.set_index(index % 8);
	contacts[element.get_index()] = element;
	index++;
	if (count < 8)
		count++;
}

