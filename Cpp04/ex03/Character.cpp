#include "Character.hpp"

Character::Character():name("defalut"){
    for(int i=0; i<4; i++){
        inven[i] = NULL;
    }
    std::cout << this->name <<" Character constructor created!" << std::endl;
}

Character::Character(std::string name):name(name){
    for(int i=0; i<4; i++){
        inven[i] = NULL;
    }
    std::cout << this->name << " Character constructor created!" << std::endl;
}

Character::Character(const Character &a){
    name = a.getName();
    for(int i=0;i<4;i++){
        if(a.inven[i])
            inven[i] = a.inven[i]->clone();
        else
            inven[i] = NULL;
        }
    std::cout << name << "Copy constructor called" << std::endl;
}

Character& Character::operator=(const Character &a){
    if(this !=&a){
        name = a.getName();
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
    std::cout << name << "Copy assignment operator called" << std::endl;
    return *this;
}

Character::~Character(){
    for(int i =0;i <4;i++){
        if(inven[i]!=NULL){
            delete inven[i];
            inven[i] = NULL;
        }
    }
    std::cout << "Character Destructor called" << std::endl;
}

void Character::equip(AMateria* m){
    if(m==NULL)
        return;

    for(int i =0;i<4;i++){
        if(inven[i] == NULL){
            inven[i] = m;
            std::cout << name <<" equipped " << m->getType() <<" in inventory "<< i << std::endl;
            return;
        }
    }
    std::cout<< name <<" inventory is full" << std::endl;
    return;
}

void Character::use(int idx, ICharacter& target){
    if(inven[idx] !=NULL){
        inven[idx]-> use(target);
    }
}

void Character::unequip(int idx){
    if(inven[idx]!= NULL){
        inven[idx] = NULL;
        std::cout << name << " unequipped in "<<idx << "th inventory"<< std::endl;
    }
    std::cout << "There is nothing to unequip."<< std::endl;
}

std::string const &Character::getName() const{
    return name;
}

AMateria* Character::getMateria(int idx) const {
    if (idx >= 0 && idx < 4) {
        return inven[idx];
    }
    return NULL;
}