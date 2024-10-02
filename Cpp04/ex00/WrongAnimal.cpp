#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal():type("Wrong Animal"){
    std::cout << type << " constructor created!" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &a){
    type = a.getType();
    std::cout << type << "Copy constructor called" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &a){
    if(this !=&a){
        type = a.getType();
    }
    std::cout << type << "Copy assignment operator called" << std::endl;
    return *this;
}

WrongAnimal::~WrongAnimal(){
    std::cout << "Wrong Animal Destructor called" << std::endl;
}

void WrongAnimal::makeSound() const{
    std::cout << "Wrong Animal sounds ~~!" << std::endl;
}

std::string WrongAnimal::getType() const{
    return type;
}