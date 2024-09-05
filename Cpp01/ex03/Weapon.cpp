#include "Weapon.hpp"

Weapon::Weapon(void): type("default type weapon"){}

Weapon::Weapon(const std::string &type) : type(type){}

Weapon::~Weapon(void){
    std::cout << this->type << " is destroyed." << std::endl;
}

const std::string &Weapon::getType(void) const{
    return this->type;
}

void Weapon::setType(const std::string &type){
    this->type = type;
}