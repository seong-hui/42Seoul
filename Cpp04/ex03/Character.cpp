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
        delete inven[i];
    }
    std::cout << "Character Destructor called" << std::endl;
}

void Character::equip(AMateria* m){
    if(!m)
        return;

    for(int i =0;i<4;i++){
        if(!inven[i]){
            inven[i] = m;
            std::cout << name <<" equipped " << m->getType() <<" in inventory "<< i << std::endl;
        }
        return;
    }
    std::cout<< name <<" inventory is full" << std::endl;
}

void Character::use(int idx, ICharacter& target){
    if(idx >=0 && idx<4 && inven[idx]){
        inven[idx]-> use(target);
        std::cout << name << " used "<< inven[idx]->getType() << " to " << target.getName()<< std::endl;
    }
}

void Character::unequip(int idx){
    if(idx >=0 && idx<4 && inven[idx]){
        inven[idx] = NULL;
        std::cout << name << " unequipped in "<<idx << "th inventory"<< std::endl;
    }
}