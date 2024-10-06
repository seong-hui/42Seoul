#ifndef DOG_HPP
#define DOG_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal{
    private:
        Brain *brain;

    public :
        Dog();
        Dog(const Dog &a);
		Dog& operator=(const Dog &a);
        ~Dog();

        void makeSound() const;
        Brain* getBrain() const;
};

#endif