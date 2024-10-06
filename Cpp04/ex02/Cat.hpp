#ifndef CAT_HPP
#define CAT_HPP

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal{
    private:
        Brain *brain;

    public:
        Cat();
        Cat(const Cat &a);
		Cat& operator=(const Cat &a);
        ~Cat();

        void makeSound() const;
        Brain* getBrain() const;
};

#endif