#include "ScavTrap.hpp"

int main() {
    ScavTrap A("A");
	ScavTrap B("B");
    std::cout << std::endl;

	A.attack(B);
	B.takeDamage(79);
	B.beRepaired(1);
    B.takeDamage(2);
	std::cout << std::endl;

    A.attack(B);
	B.attack(A);
	std::cout << std::endl;

	A.beRepaired(5);
	B.beRepaired(5);
	std::cout << std::endl;

	A.takeDamage(15);
	A.guardGate();
	B.guardGate();
	std::cout << std::endl;
}