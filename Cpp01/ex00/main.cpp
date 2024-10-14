#include "Zombie.hpp"

void checkLeaks()
{
	system("leaks zombie");
}
int main(){
	// atexit(checkLeaks);
    Zombie unnamedZombie;
	unnamedZombie.announce();
	std::cout << std::endl;

    Zombie zombie("stackZombie");
	zombie.announce();
	std::cout << std::endl;

	randomChump("randomStackZombie");
	std::cout << std::endl;
	
	Zombie *newZom = newZombie("heapZombie");
	newZom->announce();
	delete(newZom);
	checkLeaks();
	
}