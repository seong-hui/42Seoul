#include "AMateria.hpp"

AMateria::AMateria(){
    std::cout << type << " constructor created!" << std::endl;
}

AMateria::AMateria(std::string const & type): type(type){
    std::cout << type << " constructor created!" << std::endl;
}

AMateria:: AMateria(const AMateria &a){
    type = a.getType();
    std::cout << type << "Copy constructor called" << std::endl;
    
}
AMateria& AMateria::operator=(const AMateria &a){
    if(this !=&a){
        type = a.getType();
    }
    std::cout << type << "Copy assignment operator called" << std::endl;
    return *this;
}

AMateria::~AMateria(){
    std::cout << "AMateria Destructor called" << std::endl;
}

std::string const &AMateria::getType() const{
    return type;
}

void AMateria::use(ICharacter& target){
    (void)target;
}
