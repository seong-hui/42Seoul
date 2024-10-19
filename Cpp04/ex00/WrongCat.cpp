
#include "WrongCat.hpp"

 WrongCat::WrongCat(){
    type ="WrongCat";
    std::cout << type << " constructor created!" << std::endl;
 }

 WrongCat::WrongCat(const WrongCat &a){
    *this = a;
    std::cout << type << "Copy constructor called" << std::endl;
 }

WrongCat& WrongCat::operator=(const WrongCat &a){
    if(this != &a){
        type = a.getType();
    }
    std::cout << type << " copy assignment operator called" << std::endl;
    return *this;

}
WrongCat::~WrongCat(){
    std::cout << type << " Destructor called" << std::endl;
}

void WrongCat::makeSound() const{
    std::cout << "Wrong Cat sounds ~~!" << std::endl;
}