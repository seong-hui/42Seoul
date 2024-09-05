#include "HumanB.hpp"

HumanB::HumanB(void): name("Unnamed"), weapon(NULL){}

HumanB::HumanB(const std::string name): name(name), weapon(NULL){}

HumanB::~HumanB(void){
    std::cout << this->name << " is destroyed." << std::endl;
}

void HumanB::setWeapon(Weapon& weapon){
    this->weapon = &weapon;
}

void HumanB::attack(void) const{
    if(this->weapon)
        std::cout << this->name << " attacks with their " << this->weapon->getType() << std::endl;
    else
        std::cout << this->name << " has no weapon" << std::endl;
}