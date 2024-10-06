#include "Brain.hpp"

Brain::Brain(){
    std::cout << "Brain constructor created!" << std::endl;
}

Brain::Brain(const Brain &a){
    for(int i=0; i <100;i++){
        this->ideas[i] = a.ideas[i];
    }
    std::cout << "Brain Copy constructor called" << std::endl;
}

Brain& Brain::operator=(const Brain &a){
    if(this != &a){
        for(int i=0; i <100;i++){
        this->ideas[i] = a.ideas[i];
        }
    }
    std::cout <<"Brain copy assignment operator called" << std::endl;
    return *this;
}

Brain::~Brain(){
    std::cout << "Brain Destructor called" << std::endl;
}

std::string Brain::getIdea(int index) const{
    if(index >=0 && index <100)
        return ideas[index];
    else
        return "out of index";

}

void Brain::setIdea(int index, const std::string idea){
    if(index >=0 && index <100)
        ideas[index] = idea;
    else
        std::cerr << "out of index" << std::endl;
}
