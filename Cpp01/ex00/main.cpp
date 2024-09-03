#include "Zombie.hpp"

int main(){
    Zombie unnamedZombie;
	unnamedZombie.announce();

    Zombie zombie("stackZombie");
	zombie.announce();

	randomChump("randomStackZombie");

	Zombie *newZom = newZombie("heapZombie");
	newZom->announce();
	delete(newZom);
}