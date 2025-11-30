#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <string>

typedef std::string	str;

class Contact{
    public:
        size_t  index;
        str     fname; // First Name
        str     lname; // Last Name
        str     nname; // NickName
        str     phnumber; // Phone Number
        str     ds; // Darkest Secret
    // public:
    //     get_fname();
    //     set_fname();
};

#endif