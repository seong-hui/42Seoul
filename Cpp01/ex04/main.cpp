#include "Replacer.hpp"

int main(int ac, char *av[]){
    if(ac !=4){
        std::cerr << "[ERROR] Araguments Error" << std::endl;
        return 1;
    }

    std::string filename = av[1];
    std::string s1 = av[2];
    std::string s2 = av[3];

    Replacer replacer(filename, s1, s2);
    if(replacer.processFile()) return 1;

    return 0;
}