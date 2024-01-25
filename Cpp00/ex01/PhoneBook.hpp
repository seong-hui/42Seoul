#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include <iomanip>
#include "Contact.hpp"

const int MAX_CONTACTS = 8;

class PhoneBook {
private:
    Contact contacts[MAX_CONTACTS];
    int oldestContactIndex;
    bool isNumeric(const std::string& input);  

public:
    PhoneBook();
    void addContact(Contact newContact);
    void displayContacts();
    void searchContact();
    void exitProgram();
};

#endif
