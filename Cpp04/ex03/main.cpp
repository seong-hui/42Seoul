#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void checkLeaks(){
    system("leaks -list -- a.out");
}

int main() {
    // atexit(checkLeaks);
    IMateriaSource* src = new MateriaSource();
    std::cout << std::endl;

    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    src->learnMateria(new Ice()); 
    src->learnMateria(new Cure());
    std::cout <<"------"<< std::endl;

    ICharacter* me = new Character("me");
    std::cout <<"------"<< std::endl;

    AMateria* tmp;
    tmp = src->createMateria("ice");
    me->equip(tmp);
    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout <<"------"<< std::endl;

    ICharacter* bob = new Character("bob"); 
    me->use(0, *bob);
    me->use(1, *bob);

    AMateria* removedMateria = dynamic_cast<Character*>(me)->getMateria(0);
    me->unequip(0);
    delete removedMateria;

    std::cout <<"------"<< std::endl;


    delete bob; 
    delete me; 
    delete src;
    
    std::cout <<"------"<< std::endl;

    return 0; 
}