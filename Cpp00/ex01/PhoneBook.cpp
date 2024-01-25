#include "PhoneBook.hpp"
#include "Contact.hpp"

PhoneBook::PhoneBook() : oldestContactIndex(0) {}

void PhoneBook::addContact(Contact newContact){
        if (oldestContactIndex < MAX_CONTACTS) {
            newContact.index = oldestContactIndex;
            contacts[oldestContactIndex++] = newContact;
        } else {
            int index = oldestContactIndex % MAX_CONTACTS;
            newContact.index = oldestContactIndex; 
            contacts[index] = newContact;
            oldestContactIndex++;
        }
    }

void PhoneBook::displayContacts(){
        if (oldestContactIndex == 0) {
            std::cout << "No contacts available." << std::endl;
            return;
        }

        std::cout << std::setw(10) << "INDEX" << "|" << std::setw(10) << "FIRST NAME" << "|"
                  << std::setw(10) << "LAST NAME" << "|" << std::setw(10) << "NICKNAME" << std::endl;

        int contactsToDisplay = std::min(MAX_CONTACTS, oldestContactIndex);
        for (int i = 0; i < contactsToDisplay; i++) {
            int displayIndex = (oldestContactIndex - contactsToDisplay + i) % MAX_CONTACTS;
        if (displayIndex < 0) {
            displayIndex += MAX_CONTACTS;
        }
            std::cout << std::setw(10) << contacts[displayIndex].index << "|"
                      << std::setw(10) << (contacts[displayIndex].firstName.length() > 10 ? contacts[displayIndex].firstName.substr(0, 9) + "." : contacts[displayIndex].firstName) << "|"
                      << std::setw(10) << (contacts[displayIndex].lastName.length() > 10 ? contacts[displayIndex].lastName.substr(0, 9) + "." : contacts[displayIndex].lastName) << "|"
                      << std::setw(10) << (contacts[displayIndex].nickname.length() > 10 ? contacts[displayIndex].nickname.substr(0, 9) + "." : contacts[displayIndex].nickname) << std::endl;
        }
    }

bool PhoneBook::isNumeric(const std::string& input) {
         if (input.empty()) {
        return false;
    }
    if (std::all_of(input.begin(), input.end(), ::isspace)) {
        return false;
    }
    for (std::string::const_iterator it = input.begin(); it != input.end(); ++it) {
        if (!std::isdigit(*it)) {
            return false;
        }
    }
    return true;
}

void PhoneBook::searchContact(){
        displayContacts();
        if (oldestContactIndex == 0)
            return;

        std::string input;
        int indexToDisplay;
        
         while (true){
            std::cout << "Enter the index to display details: " << std::endl;
            std::getline(std::cin, input);

            if (std::cin.eof())
                exit(0);
                
            if (isNumeric(input)) {
                indexToDisplay = std::atoi(input.c_str());
                
                if (indexToDisplay >= 0 && indexToDisplay >= oldestContactIndex - MAX_CONTACTS && indexToDisplay < oldestContactIndex) {
                    if(indexToDisplay >= MAX_CONTACTS)
                        indexToDisplay = indexToDisplay % 8;
                    const Contact& displayedContact = contacts[indexToDisplay];
                    std::cout << "- First Name: " << displayedContact.firstName << std::endl;
                    std::cout << "- Last Name: " << displayedContact.lastName << std::endl;
                    std::cout << "- Nickname: " << displayedContact.nickname << std::endl;
                    std::cout << "- Phone Number: " << displayedContact.phoneNumber << std::endl;
                    std::cout << "- Darkest Secret: " << displayedContact.darkestSecret << std::endl;
                    break;
            } else {
                std::cout << "[Invalid input] Please enter a valid index." << std::endl;
            }
        } else {
            std::cout << "[Invalid input] Please enter a valid numeric index." << std::endl;
        }}
    }

void PhoneBook::exitProgram(){
    std::cout << "Exit the program" << std::endl;
    exit(0);
}


