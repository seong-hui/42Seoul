#include "AAnimal.hpp"

AAnimal::AAnimal():type("AAnimal"){
    std::cout << type << " constructor created!" << std::endl;
}

AAnimal::AAnimal(const AAnimal &a){
    type = a.getType();
    std::cout << type << "Copy constructor called" << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal &a){
    if(this !=&a){
        type = a.getType();
    }
    std::cout << type << "Copy assignment operator called" << std::endl;
    return *this;
}

AAnimal::~AAnimal(){
    std::cout << "AAnimal Destructor called" << std::endl;
}

std::string AAnimal::getType() const{
    return type;
}