#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>

class Animal{
    protected:
        std::string type;
    public:
        Animal();
        Animal(const Animal &a);
		Animal& operator=(const Animal &a);
        virtual ~Animal();

        virtual void makeSound() const;
        std::string getType() const;
};

#endif