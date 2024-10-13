#include "Character.hpp"
#include "Ice.hpp"
#include "Cure.hpp"
#include "MateriaSource.hpp"

void checkleak(){
    system("leaks --list -- a.out");
}

int main() {
    
    IMateriaSource* src = new MateriaSource();
    std::cout << std::endl;
    src->learnMateria(new Ice()); 
    std::cout << std::endl;
    src->learnMateria(new Cure());
    std::cout <<"------"<< std::endl;

    ICharacter* me = new Character("me");
    AMateria* tmp;
    std::cout <<"------"<< std::endl;

    tmp = src->createMateria("ice");
    me->equip(tmp);
    std::cout <<"------"<< std::endl;

    tmp = src->createMateria("cure");
    me->equip(tmp);
    std::cout <<"------"<< std::endl;

    ICharacter* bob = new Character("bob"); 
    me->use(0, *bob);
    me->use(1, *bob);
    std::cout <<"------"<< std::endl;

    delete bob; 
    delete me; 
    delete src;
    std::cout <<"------"<< std::endl;

    checkleak();
    return 0; 
}