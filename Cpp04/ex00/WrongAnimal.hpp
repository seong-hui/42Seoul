#ifndef WRONG_ANIMAL_HPP
#define WRONG_ANIMAL_HPP

#include <iostream>

class WrongAnimal{
    protected:
        std::string type;
    public:
        WrongAnimal();
        WrongAnimal(const WrongAnimal &a);
		WrongAnimal& operator=(const WrongAnimal &a);
        virtual ~WrongAnimal();

        void makeSound() const;
        std::string getType() const;
};

#endif