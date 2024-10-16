#include "ScavTrap.hpp"

ScavTrap::ScavTrap(){
     name = "default";
     hitPoints = 100;
     energyPoints = 50;
     attackDamage = 20;
     std::cout << "ScavTrap " << name << " constructor created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name){
     this->name = name;
     hitPoints = 100;
     energyPoints = 50;
     attackDamage = 20;
     std::cout << "ScavTrap " << name << " constructor created!" << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &s){
     name = s.getName();
	hitPoints = s.hitPoints;
	energyPoints = s.attackDamage;
	attackDamage = s.attackDamage;
     std::cout << name << "Copy constructor called" << std::endl;

}
ScavTrap& ScavTrap::operator=(const ScavTrap &s){
     if(this != &s){
          name = s.getName();
          hitPoints = s.hitPoints;
          energyPoints = s.energyPoints;
          attackDamage = s.attackDamage;
     }
     std::cout << "Copy assignment operator called" << std::endl;
     return *this;

}
ScavTrap::~ScavTrap(){
     std::cout << "ScavTrap " << name << " Destructor called" << std::endl;
}

void ScavTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints> 0){
        energyPoints--;
        std::cout << "ScavTrap " << name << " attacks " << target 
            << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else{
        std::cout << "ScavTrap " << name << " has no energy points or hit points left!!!" << std::endl;
    }
    
}

void ScavTrap::guardGate(){
     if (energyPoints > 0 && hitPoints> 0){
          std::cout << "ScavTrap " << name << " is now in Gate keeper mode." << std::endl;
    } else{
        std::cout << "ScavTrap " << name << " has no energy points or hit points left!!!" << std::endl;
    }
}