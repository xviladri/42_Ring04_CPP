/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:21:18 by xviladri          #+#    #+#             */
/*   Updated: 2026/01/05 19:21:31 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {
    private:
        Contact _contacts[8];
        int     _index;
    public:
        PhoneBook();
        ~PhoneBook();
        void    addContact();
        void    searchContact();
};
#endif
