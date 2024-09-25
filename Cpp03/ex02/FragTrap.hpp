#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap{
    public:
        FragTrap();
        FragTrap(std::string name);
        FragTrap(const FragTrap &s);
        FragTrap& operator=(const FragTrap &s);
        ~FragTrap();

        void highFivesGuys(void);
        void attack(ClapTrap& target);
};

#endif