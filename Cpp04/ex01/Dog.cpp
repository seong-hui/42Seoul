#include "Dog.hpp"

 Dog::Dog(){
    type ="Dog";
    brain = new Brain();
    std::cout << type << " constructor created!" << std::endl;
 }

 Dog::Dog(const Dog &a){
    type = a.getType();
    brain = new Brain(*a.brain);
    std::cout << type << "Copy constructor called" << std::endl;
 }

Dog& Dog::operator=(const Dog &a){
    if(this != &a){
        type = a.getType();
        delete brain;
        brain = new Brain(*a.brain);
    }
    std::cout << type << " copy assignment operator called" << std::endl;
    return *this;

}
Dog::~Dog(){
    delete brain;
    std::cout << type << " Destructor called" << std::endl;
}

void Dog::makeSound() const{
    std::cout << "Dog sounds: " << std::endl;
}