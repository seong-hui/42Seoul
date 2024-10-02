#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    
    std::cout << j->getType() << " " << std::endl; 
    std::cout << i->getType() << " " << std::endl; 

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    std::cout << std::endl;
	delete meta;
    std::cout << std::endl;
	delete j;
    std::cout << std::endl;
    delete i;

    return 0; 
}