#include "Cat.hpp"

 Cat::Cat(){
    type ="Cat";
    std::cout << type << " constructor created!" << std::endl;
 }

 Cat::Cat(const Cat &a){
    *this = a;
    std::cout << type << "Copy constructor called" << std::endl;
 }

Cat& Cat::operator=(const Cat &a){
    if(this != &a){
        type = a.getType();
    }
    std::cout << type << " copy assignment operator called" << std::endl;
    return *this;

}
Cat::~Cat(){
    std::cout << type << " Destructor called" << std::endl;
}

void Cat::makeSound() const{
    std::cout << "Cat Cat" << std::endl;
}