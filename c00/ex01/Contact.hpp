#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

typedef std::string	str;

class Contact{
	private:
		size_t  index;
		str     first_name;
		str     last_name;
		str     nickname;
		str     phone_number;
		str     darkest_secret;
	public:
		Contact() {
			index = 0,
			first_name = "";
			last_name = "";
			nickname = "";
			phone_number = "";
			darkest_secret = "";
		}
		size_t	get_index();
		void	set_index(size_t val);
		str		get_first_name();
		void	set_first_name(str val);
		str		get_last_name();
		void	set_last_name(str val);
		str		get_nickname();
		void	set_nickname(str val);
		str		get_phone_number();
		void	set_phone_number(str val);
		str		get_darkest_secret();
		void	set_darkest_secret(str val);
};

#endif