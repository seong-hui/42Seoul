#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>

class Contact {
private:
    std::string firstName;
    std::string lastName;
    std::string nickname;
    std::string phoneNumber;
    std::string darkestSecret;
    int index;

public:
    Contact();
    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getNickname() const;
    std::string getPhoneNumber() const;
    std::string getDarkestSecret() const;
    void setIndex(int newIndex);
    int getIndex() const;
    void setFirstName(const std::string& newFirstName);
    void setLastName(const std::string& newLastName);
    void setNickname(const std::string& newNickname);
    void setPhoneNumber(const std::string& newPhoneNumber);
    void setDarkestSecret(const std::string& newDarkestSecret);
};

#endif
