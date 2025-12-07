#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>
# include <string>

class Contact {
    private:
        std::string _firstName;
        std::string _lastName;
        std::string _nickname;
        std::string _phoneNumber;
        std::string _darkestSecret;
    public:
        Contact();
        ~Contact();
      //para asignar valores
      	void    setFirstName(std::string firstName);
        void    setLastName(std::string lastName);
        void    setNickname(std::string nickname);
        void    setPhoneNumber(std::string phoneNumber);
        void    setDarkestSecret(std::string darkestSecret);
     //para leer valores i usamos el const para que estas funciones NO modifiquen la clase Contact 
	std::string getFirstName() const;
        std::string getLastName() const;
        std::string getNickname() const;
        std::string getPhoneNumber() const;
        std::string getDarkestSecret() const;
};

#endif
