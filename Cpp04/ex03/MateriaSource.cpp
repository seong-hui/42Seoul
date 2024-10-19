#include "MateriaSource.hpp"

MateriaSource::MateriaSource(){
    for(int i=0; i<4; i++){
        inven[i] = NULL;
    }
    std::cout << "MateriaSource constructor created" << std::endl;
}

MateriaSource::MateriaSource(const MateriaSource &a){
    for(int i=0;i<4;i++){
        if(a.inven[i])
            inven[i] = a.inven[i]->clone();
        else
            inven[i] = NULL;
        }
    std::cout << "MateriaSource Copy constructor called" << std::endl;
}

MateriaSource& MateriaSource::operator=(const MateriaSource &a){
    if(this !=&a){
        for(int i=0;i<4;i++){
            delete inven[i];
        }

        for(int i=0;i<4;i++){
            if(a.inven[i])
                inven[i] = a.inven[i]->clone();
            else
                inven[i] = NULL;
        }
    }
    std::cout << "MateriaSource Copy assignment operator called" << std::endl;
    return *this;
}

MateriaSource::~MateriaSource(){
    for(int i =0;i <4;i++){
        if (inven[i] !=NULL){
            delete inven[i];
            inven[i] = NULL;
        }
    }
    std::cout << "MateriaSource Destructor called" << std::endl;
}


void MateriaSource::learnMateria(AMateria* m){
    for(int i =0;i<4;i++){
        if(inven[i]== NULL){
            inven[i] = m;
            std::cout <<"MateriaSource learend " << m->getType() <<" in inventory "<< i << std::endl;
            return;
        }
        
    }
    std::cout<< "MateriaSource inventory is full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type){
    for (int i = 0; i < 4; i++) {
		if (inven[i] && inven[i]->getType()== type){
            std::cout <<"MateriaSource create "<< type << std::endl;
            return this->inven[i]->clone();
		}
	}
    std::cout <<type<<" type is unknown" << std::endl;
	return 0;
}
