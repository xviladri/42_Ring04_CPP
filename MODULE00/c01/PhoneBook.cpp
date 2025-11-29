#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>

PhoneBook::PhoneBook() {
    _index = 0;
}

PhoneBook::~PhoneBook() {
}

void PhoneBook::addContact() {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    std::cout << "First name: ";
    std::getline(std::cin, firstName);
    std::cout << "Last name: ";
    std::getline(std::cin, lastName);
    std::cout << "Nickname: ";
    std::getline(std::cin, nickname);
    std::cout << "Phone number: ";
    std::getline(std::cin, phoneNumber);
    std::cout << "Darkest secret: ";
    std::getline(std::cin, darkestSecret);

    if (firstName.empty() || lastName.empty() || nickname.empty() || phoneNumber.empty() || darkestSecret.empty()) {
        std::cout << "All fields must be filled." << std::endl;
        return;
    }

    _contacts[_index].setFirstName(firstName);
    _contacts[_index].setLastName(lastName);
    _contacts[_index].setNickname(nickname);
    _contacts[_index].setPhoneNumber(phoneNumber);
    _contacts[_index].setDarkestSecret(darkestSecret);

    _index = (_index + 1) % 8;
}

void PhoneBook::searchContact() {
    std::cout << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << std::endl;

    for (int i = 0; i < 8; i++) {
        std::cout << std::setw(10) << i << "|";
        std::string firstName = _contacts[i].getFirstName();
        if (firstName.length() > 10)
            firstName = firstName.substr(0, 9) + ".";
        std::cout << std::setw(10) << firstName << "|";
        std::string lastName = _contacts[i].getLastName();
        if (lastName.length() > 10)
            lastName = lastName.substr(0, 9) + ".";
        std::cout << std::setw(10) << lastName << "|";
        std::string nickname = _contacts[i].getNickname();
        if (nickname.length() > 10)
            nickname = nickname.substr(0, 9) + ".";
        std::cout << std::setw(10) << nickname << std::endl;
    }

    std::cout << "Enter index: ";
    int index;
    std::cin >> index;
    if (std::cin.fail() || index < 0 || index > 7) {
        std::cout << "Invalid index." << std::endl;
        std::cin.clear();
        std::cin.ignore(10000, '\n');
        return;
    }
    std::cin.ignore(10000, '\n');

    std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
    std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
    std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
    std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
    std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
}
