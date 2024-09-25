#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap : public ClapTrap{
    public:
        ScavTrap();
        ScavTrap(std::string name);
        ScavTrap(const ScavTrap &s);
        ScavTrap& operator=(const ScavTrap &s);
        ~ScavTrap();

        void attack(ClapTrap& target);
        void guardGate();
};

#endif