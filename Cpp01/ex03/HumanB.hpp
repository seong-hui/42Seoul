#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.hpp"
#include <iostream>

class HumanB{
    private:
        std::string name;
        Weapon* weapon;
    public:
        HumanB(void);
        HumanB(const std::string name);
        ~HumanB(void);
        void setWeapon(Weapon& weapon);
        void attack(void) const;
};

#endif