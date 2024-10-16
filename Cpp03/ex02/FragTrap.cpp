#include "FragTrap.hpp"

FragTrap::FragTrap(){
    name = "default";
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor created!" << std::endl;

}
FragTrap:: FragTrap(std::string name){
    this->name = name;
    hitPoints = 100;
    energyPoints = 100;
    attackDamage = 30;
    std::cout << "FragTrap " << name << " constructor created!" << std::endl;

}

FragTrap::FragTrap(const FragTrap &s): ClapTrap(s){
    name = s.getName();
	hitPoints = s.hitPoints;
	energyPoints = s.attackDamage;
	attackDamage = s.attackDamage;
    std::cout << "FragTrap " << name << "Copy constructor called" << std::endl;
    
}
FragTrap&  FragTrap::operator=(const FragTrap &s){
    if(this != &s){
          name = s.getName();
          hitPoints = s.hitPoints;
          energyPoints = s.energyPoints;
          attackDamage = s.attackDamage;
     }
     std::cout << "FragTrap " << name <<"Copy assignment operator called" << std::endl;
     return *this;
}

FragTrap::~FragTrap(){
    std::cout << "FragTrap " << name << " Destructor called" << std::endl;
}

void  FragTrap::highFivesGuys(void){
    if (energyPoints > 0 && hitPoints> 0){
          std::cout << "FragTrap " << name << " requests a high five" << std::endl;
    } else{
        std::cout << "FragTrap " << name << " has no energy points or hit points left!!!" << std::endl;
    }
    
}

void FragTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints> 0){
        energyPoints--;
        std::cout << "FragTrap " << name << " attacks " << target 
            << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else{
        std::cout << "FragTrap " << name << " has no energy points or hit points left!!!" << std::endl;
    }
    
}