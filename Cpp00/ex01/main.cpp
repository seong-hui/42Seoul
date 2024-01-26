#include "PhoneBook.hpp"

bool isWhitespace(const std::string& str){
    return std::all_of(str.begin(), str.end(), ::isspace);
}

std::string getNonEmptyInput(const std::string& prompt){
    std::string input;
    while (true){
        std::cout << prompt << std::endl;
        std::getline(std::cin, input);

        if (!input.empty()&& !isWhitespace(input))
            break;
        else if(std::cin.eof())
            exit(0);
    }
    return input;
}

int main() {
    PhoneBook phoneBook;

    while (true) {
        std::cout << "---------------------------" << std::endl;
        std::cout << "  ADD  |  SEARCH  |  EXIT  " << std::endl;
        std::cout << "---------------------------" << std::endl;
        std::cout << "Please enter the desired action: " << std::endl;;

        std::string choice;
        std::getline(std::cin, choice);

        if (std::cin.eof())
            exit(0);

        if (choice == "ADD") {
            Contact newContact;
            newContact.setFirstName(getNonEmptyInput("- Please enter your first name:"));
            newContact.setLastName(getNonEmptyInput("- Please enter your last name:"));
            newContact.setNickname(getNonEmptyInput("- Please enter your nickname:"));
            newContact.setPhoneNumber(getNonEmptyInput("- Please enter your phone number:"));
            newContact.setDarkestSecret(getNonEmptyInput("- Please enter your darkest secret:"));
            phoneBook.addContact(newContact);
        } else if (choice == "SEARCH") {
            phoneBook.searchContact();
        } else if (choice == "EXIT") {
            phoneBook.exitProgram();
        } else {
            std::cout << "[Invalid input] Please try again." << std::endl;
        }
    }

    return 0;
}