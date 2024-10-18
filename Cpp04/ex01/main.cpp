#include "Dog.hpp"
#include "Cat.hpp"

void checkLeaks(){
    system("leaks Animal");
}

int main() {
    atexit(checkLeaks);
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
    std::cout <<"--------------"<< std::endl;

    Dog dog1;
    std::cout << std::endl;
    dog1.getBrain()->setIdea(0, "basic idea");

    Dog dog2 = dog1;
    std::cout << std::endl;

    std::cout << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    dog1.getBrain()->setIdea(0, "modified idea");
    std::cout << std::endl;

    std::cout << dog1.getBrain()->getIdea(0) << std::endl;
    std::cout << dog2.getBrain()->getIdea(0) << std::endl;
    std::cout << std::endl;

    return 0; 
}