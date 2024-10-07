#include "Ice.hpp"

Ice::Ice(){
    type = "ice";
    std::cout << type << " constructor created!" << std::endl;
}

Ice::Ice(const Ice &a){
    type = a.getType();
    std::cout << type << "Copy constructor called" << std::endl;
}

Ice& Ice::operator=(const Ice &a){
    if(this != &a){
        type = a.getType();
    }
    std::cout << type << "Copy assignment operator called" << std::endl;

    return *this;
}

Ice::~Ice(){
    std::cout << "Ice Destructor called" << std::endl;
}

AMateria* Ice::clone() const{
    return new Ice();
    std::cout << "Ice constructor cloned" << std::endl;
}

void Ice::use(ICharacter& target){
    std::cout << "* shoots an ice bolt at " << target.getName() << " *"<< std::endl;
}