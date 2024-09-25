#include "FragTrap.hpp"

int main() {
    FragTrap A("A");
	FragTrap B("B");
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
	A.highFivesGuys();
	B.highFivesGuys();
	std::cout << std::endl;
}