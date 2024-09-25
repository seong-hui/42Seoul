#include "ClapTrap.hpp"

ClapTrap::ClapTrap(): name("defalut"), hitPoints(10), energyPoints(10), attackDamage(0){
     std::cout << name << " constructor created!" << std::endl;
}

ClapTrap::ClapTrap(const std::string name): name(name), hitPoints(10), energyPoints(10), attackDamage(0){
    std::cout << name << " constructor created!" << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &c): 
    name(c.name), hitPoints(c.hitPoints), energyPoints(c.energyPoints), attackDamage(c.attackDamage){
        std::cout << name << "Copy constructor called" << std::endl;
}

ClapTrap& ClapTrap::operator=(const ClapTrap &c){
    std::cout << "Copy assignment operator called" << std::endl;
    if(this != &c){
        name = c.name;
        hitPoints = c.hitPoints;
        energyPoints = c.energyPoints;
        attackDamage = c.attackDamage;
    }
    return *this;
}

ClapTrap::~ClapTrap(){
    std::cout << name << " Destructor called" << std::endl;
}

void ClapTrap::attack(const std::string& target){
    if (energyPoints > 0 && hitPoints> 0){
        energyPoints--;
        std::cout << "ClapTrap " << name << " attacks " << target 
            << ", causing " << attackDamage << " points of damage!" << std::endl;
    } else{
        std::cout << "ClapTrap " << name << " has no energy points or hit points left!!!" << std::endl;
    }
    
}

void ClapTrap::takeDamage(unsigned int amount){
    if(hitPoints <= amount){
        hitPoints = 0;
        std::cout << name << " has no hit points left!!!" << std::endl;
    }
    else{
        hitPoints -= amount;
        std::cout << name << " takes " << amount << " damage"<<std::endl;
    }
}

 void ClapTrap::beRepaired(unsigned int amount){
    if (energyPoints > 0 && hitPoints> 0){
        hitPoints += amount;
        energyPoints--;
        std::cout << name << " hit points are repaired by " << amount << std::endl;
        
    } else{
        std::cout << name << " has no energy points or hit points left!!!" << std::endl;
    }

 }

 std::string ClapTrap::getName() const{
    return name;
 }