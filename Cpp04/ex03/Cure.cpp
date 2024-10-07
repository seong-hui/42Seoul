#include "Cure.hpp"

Cure::Cure(){
    type = "Cure";
    std::cout << type << " constructor created!" << std::endl;
}

Cure::Cure(const Cure &a){
    type = a.getType();
    std::cout << type << "Copy constructor called" << std::endl;
}

Cure& Cure::operator=(const Cure &a){
    if(this != &a){
        type = a.getType();
    }
    std::cout << type << "Copy assignment operator called" << std::endl;

    return *this;
}

Cure::~Cure(){
    std::cout << "Cure Destructor called" << std::endl;
}

AMateria* Cure::clone() const{
    return new Cure();
    std::cout << "Cure constructor cloned" << std::endl;
}

void Cure::use(ICharacter& target){
    std::cout << "* heals " << target.getName() << "'s wounds *"<< std::endl;
}