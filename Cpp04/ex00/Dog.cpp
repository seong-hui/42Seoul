#include "Dog.hpp"

 Dog::Dog(){
    type ="Dog";
    std::cout << type << " constructor created!" << std::endl;
 }

 Dog::Dog(const Dog &a){
    *this = a;
    std::cout << type << "Copy constructor called" << std::endl;
 }

Dog& Dog::operator=(const Dog &a){
    if(this != &a){
        type = a.getType();
    }
    std::cout << type << " copy assignment operator called" << std::endl;
    return *this;

}
Dog::~Dog(){
    std::cout << type << " Destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog Dog" << std::endl;
}