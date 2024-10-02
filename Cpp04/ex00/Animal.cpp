#include "Animal.hpp"

Animal::Animal():type("Animal"){
    std::cout << type << " constructor created!" << std::endl;
}

Animal::Animal(const Animal &a){
    type = a.getType();
    std::cout << type << "Copy constructor called" << std::endl;
}

Animal& Animal::operator=(const Animal &a){
    if(this !=&a){
        type = a.getType();
    }
    std::cout << type << "Copy assignment operator called" << std::endl;
    return *this;
}

Animal::~Animal(){
    std::cout << "Animal Destructor called" << std::endl;
}

void Animal::makeSound() const{
    std::cout << "Animal sound" << std::endl;
}

std::string Animal::getType() const{
    return type;
}