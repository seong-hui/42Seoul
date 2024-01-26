#include "Contact.hpp"

Contact::Contact() : index(0) {}

std::string Contact::getFirstName() const {
    return firstName;
}

std::string Contact::getLastName() const {
    return lastName;
}

std::string Contact::getNickname() const {
    return nickname;
}

std::string Contact::getPhoneNumber() const {
    return phoneNumber;
}

std::string Contact::getDarkestSecret() const {
    return darkestSecret;
}

int Contact::getIndex() const {
    return index;
}

void Contact::setIndex(int newIndex) {
        index = newIndex;
}

void Contact::setFirstName(const std::string& newFirstName) {
    firstName = newFirstName;
}

void Contact::setLastName(const std::string& newLastName) {
    lastName = newLastName;
}

void Contact::setNickname(const std::string& newNickname) {
    nickname = newNickname;
}

void Contact::setPhoneNumber(const std::string& newPhoneNumber) {
    phoneNumber = newPhoneNumber;
}

void Contact::setDarkestSecret(const std::string& newDarkestSecret) {
    darkestSecret = newDarkestSecret;
}
