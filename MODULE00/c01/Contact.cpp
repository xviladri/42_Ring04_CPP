#include "Contact.hpp"

//Constructor: inicializa el objecto
Contact::Contact() {
}
//Destructor: Limpia cuando el objeto se destruye
Contact::~Contact() {
}
/*--------------------------------------------------
 **SETTERS (Modificadores) - no llevan 'const' pq SI cambian al objeto
-----------------------------------------------------*/
void    Contact::setFirstName(std::string firstName) {
    _firstName = firstName;
}

void    Contact::setLastName(std::string lastName) {
    _lastName = lastName;
}

void    Contact::setNickname(std::string nickname) {
    _nickname = nickname;
}

void    Contact::setPhoneNumber(std::string phoneNumber) {
    _phoneNumber = phoneNumber;
}

void    Contact::setDarkestSecret(std::string darkestSecret) {
    _darkestSecret = darkestSecret;
}
/*----------------------------------------------------
 **GETTERS (Accesores) - llevan 'const' pq prometemos NO cambiar nada, versión de solo lectura
 -----------------------------------------------------*/
std::string Contact::getFirstName() const {
    return _firstName;
}

std::string Contact::getLastName() const {
    return _lastName;
}

std::string Contact::getNickname() const {
    return _nickname;
}

std::string Contact::getPhoneNumber() const {
    return _phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return _darkestSecret;
}
