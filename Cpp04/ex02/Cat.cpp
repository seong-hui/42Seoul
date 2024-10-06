#include "Cat.hpp"

 Cat::Cat(){
    type ="Cat";
    brain = new Brain();
    std::cout << type << " constructor created!" << std::endl;
 }

 Cat::Cat(const Cat &a){
    type = a.getType();
    brain = new Brain(*a.brain);
    std::cout << type << "Copy constructor called" << std::endl;
 }

Cat& Cat::operator=(const Cat &a){
    if(this != &a){
        type = a.getType();
        delete brain;
        brain = new Brain(*a.brain);
    }
    std::cout << type << " copy assignment operator called" << std::endl;
    return *this;

}
Cat::~Cat(){
    delete brain;
    std::cout << type << " Destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat sounds ~~!" << std::endl;
}

Brain* Cat::getBrain() const{
    return this->brain;
}