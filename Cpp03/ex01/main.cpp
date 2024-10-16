#include "ScavTrap.hpp"

int main() {
    ScavTrap A("A");
	ScavTrap B("B");
    std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(20);
	A.attack(B.getName());
	B.takeDamage(20);
	A.attack(B.getName());
	B.takeDamage(20);
	A.attack(B.getName());
	B.takeDamage(20);
	A.attack(B.getName());
	B.takeDamage(20);
	B.attack(A.getName());    
	std::cout << std::endl;

	A.beRepaired(5);
	B.beRepaired(5);
	std::cout << std::endl;

	A.guardGate();
	B.guardGate();
	std::cout << std::endl;
}