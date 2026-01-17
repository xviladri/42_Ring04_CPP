/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xviladri <xviladri@student.42barcelon      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/05 19:21:38 by xviladri          #+#    #+#             */
/*   Updated: 2026/01/17 18:38:08 by xviladri         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "PhoneBook.hpp"
#include <iostream>
#include <iomanip>
#include <cctype>

PhoneBook::PhoneBook() {
    _index = 0;
    _size = 0;
}

PhoneBook::~PhoneBook() {
}

std::string PhoneBook::_readInput(std::string prompt) {
    std::string input;
    while (true) {
        std::cout << prompt;
        if (!std::getline(std::cin, input))
            return "";
        if (!input.empty())
            return input;
        std::cout << "Field cannot be empty. Please try again." << std::endl;
    }
}

void PhoneBook::addContact() {
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;

    firstName = _readInput("First name: ");
    if (std::cin.eof()) return;
    lastName = _readInput("Last name: ");
    if (std::cin.eof()) return;
    nickname = _readInput("Nickname: ");
    if (std::cin.eof()) return;
    phoneNumber = _readInput("Phone number: ");
    if (std::cin.eof()) return;
    darkestSecret = _readInput("Darkest secret: ");
    if (std::cin.eof()) return;

    _contacts[_index].setFirstName(firstName);
    _contacts[_index].setLastName(lastName);
    _contacts[_index].setNickname(nickname);
    _contacts[_index].setPhoneNumber(phoneNumber);
    _contacts[_index].setDarkestSecret(darkestSecret);

    _index = (_index + 1) % 8;
    if (_size < 8)
        _size++;
}

std::string PhoneBook::_truncate(std::string str) {
    if (str.length() > 10)
        return str.substr(0, 9) + ".";
    return str;
}

void PhoneBook::searchContact() {
    if (_size == 0) {
        std::cout << "Phonebook is empty." << std::endl;
        return;
    }
    std::cout << "|" << std::setw(10) << "index" << "|";
    std::cout << std::setw(10) << "first name" << "|";
    std::cout << std::setw(10) << "last name" << "|";
    std::cout << std::setw(10) << "nickname" << "|" << std::endl;

    for (int i = 0; i < 8; i++) {
        std::cout << "|" << std::setw(10) << i + 1 << "|";
        std::cout << std::setw(10) << _truncate(_contacts[i].getFirstName()) << "|";
        std::cout << std::setw(10) << _truncate(_contacts[i].getLastName()) << "|";
        std::cout << std::setw(10) << _truncate(_contacts[i].getNickname()) << "|" << std::endl;
    }

    std::string input;
    int index;

    while (true) {
        std::cout << "Enter index: ";
        if (!std::getline(std::cin, input))
            break;
        if (input.length() == 1 && isdigit(input[0])) {
            index = input[0] - '0';
            if (index >= 1 && index <= 8) {
                if ((index - 1) >= _size) {
                    std::cout << "No contact registered at index " << index << "." << std::endl;
                    continue;
                }
                index--;
                std::cout << "First name: " << _contacts[index].getFirstName() << std::endl;
                std::cout << "Last name: " << _contacts[index].getLastName() << std::endl;
                std::cout << "Nickname: " << _contacts[index].getNickname() << std::endl;
                std::cout << "Phone number: " << _contacts[index].getPhoneNumber() << std::endl;
                std::cout << "Darkest secret: " << _contacts[index].getDarkestSecret() << std::endl;
                return;
            }
        }
        std::cout << "Invalid index. Please enter a number between 1 and 8." << std::endl;
    }
}
