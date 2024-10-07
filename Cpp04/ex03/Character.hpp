#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter{
    private: 
        std::string name;
        AMateria *inven[4];
        
    public:
        Character();
        Character(std::string name);
        Character(const Character &a);
        Character& operator=(const Character &a);
        ~Character();

        void equip(AMateria* m);
        void use(int idx, ICharacter& target);
        void unequip(int idx);
        std::string const & getName() const;

};

#endif