#include "ClapTrap.hpp"

int main() {
    ClapTrap A("A");
	ClapTrap B("B");
    std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(9);
	B.beRepaired(1);
    B.takeDamage(2);
	std::cout << std::endl;

    A.attack(B.getName());
	B.attack(A.getName());
	std::cout << std::endl;

	A.beRepaired(5);
	B.beRepaired(5);
	std::cout << std::endl;

	A.takeDamage(15);
	std::cout << std::endl;
}