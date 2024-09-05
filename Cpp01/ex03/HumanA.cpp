#include "HumanA.hpp"

HumanA::HumanA(std::string name, Weapon& weapon): name(name),weapon(weapon){}

HumanA::~HumanA(void){
    std::cout << this->name << " is destroyed." << std::endl;
}

void HumanA::attack(void) const{
    std::cout << this->name << " attacks with their " << this->weapon.getType() << std::endl;
}