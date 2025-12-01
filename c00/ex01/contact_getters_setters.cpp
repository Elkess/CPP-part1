#include "Contact.hpp"

size_t	Contact::get_index()
{
    return (index);
}

void	Contact::set_index(size_t val)
{
    index = val;
}

str	Contact::get_first_name()
{
    return (first_name);
}

void	Contact::set_first_name(str val)
{
    first_name = val;
}

str	Contact::get_last_name()
{
    return (last_name);
}

void	Contact::set_last_name(str val)
{
    last_name = val;
}

str	Contact::get_nickname()
{
    return (nickname);
}

void	Contact::set_nickname(str val)
{
    nickname = val;
}

str	Contact::get_phone_number()
{
    return (phone_number);
}

void	Contact::set_phone_number(str val)
{
    phone_number = val;
}

str	Contact::get_darkest_secret()
{
    return (darkest_secret);
}

void	Contact::set_darkest_secret(str val)
{
    darkest_secret = val;
}
