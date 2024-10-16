#include "FragTrap.hpp"

int main() {
    FragTrap A("A");
	FragTrap B("B");
    std::cout << std::endl;

	A.attack(B.getName());
	B.takeDamage(30);
	A.attack(B.getName());
	B.takeDamage(30);
	A.attack(B.getName());
	B.takeDamage(30);
	A.attack(B.getName());
	B.takeDamage(30);
	std::cout << std::endl;

    A.attack(B.getName());
	B.takeDamage(20);
	B.attack(A.getName());
	std::cout << std::endl;

	A.beRepaired(5);
	B.beRepaired(5);
	std::cout << std::endl;

	A.highFivesGuys();
	B.highFivesGuys();
	std::cout << std::endl;
}