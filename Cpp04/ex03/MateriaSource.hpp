#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource{
    private:
        AMateria *inven[4];

    public:
        MateriaSource();
        MateriaSource(const MateriaSource &a);
        MateriaSource& operator=(const MateriaSource &a);
        ~MateriaSource();

        void learnMateria(AMateria* m);
        AMateria* createMateria(std::string const & type);
} ;

#endif