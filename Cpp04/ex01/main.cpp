#include "Dog.hpp"
#include "Cat.hpp"

int main() {
    
    int num = 4;
    Animal* animals[num];

    for(int i = 0; i<num / 2;i++){
        animals[i] = new Dog();
    }
    std::cout << std::endl;

    for(int i=num/2; i< num;i++){
        animals[i] = new Cat();
    }
    std::cout << std::endl; 

    for (int i = 0; i < num; ++i) {
        animals[i]->makeSound();
    }
    std::cout << std::endl;

    for (int i = 0; i < num; ++i) {
        delete animals[i];
    }

    return 0; 
}