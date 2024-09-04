#include "Zombie.hpp"

int main(){

  Zombie* zombieList = zombieHorde(5, "test");
  for (int i = 0; i < 5; i++) {
    zombieList[i].announce();
	}

  delete[] zombieList; 
  return 0;
}
