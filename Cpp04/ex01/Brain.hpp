#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>

class Brain{
    private:
        std::string ideas[100];
    public:
        Brain();
        Brain(const Brain &a);
        Brain& operator=(const Brain &a);
        ~Brain();

        std::string getIdea(int index) const;
        void setIdea(int index, const std::string idea);
};

#endif