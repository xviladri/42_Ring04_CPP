#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int     _index;
	std::string	_getInput(std::string const prompt) const;
    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    searchContact();
};

#endif
