#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.cpp"


int main() {
    const Animal* meta = new Animal(); 
    const Animal* j = new Dog();
    const Animal* i = new Cat();
    const WrongAnimal* wCat = new WrongCat();
    std::cout << std::endl;
    
    std::cout << j->getType() << " : "; 
    j->makeSound();
    std::cout << i->getType() << " :  ";
    i->makeSound();
    std::cout << meta->getType() << " : ";
    meta->makeSound();
    std::cout << wCat->getType() << " : ";
    wCat->makeSound();
    std::cout << std::endl;

	delete meta;
    std::cout << std::endl;
	delete j;
    std::cout << std::endl;
    delete i;
    std::cout << std::endl;
    delete wCat;

    return 0; 
}