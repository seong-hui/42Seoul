#include "Zombie.hpp"
void checkLeaks()
{
	system("leaks zombie");
}

int main(){
  // atexit(checkLeaks);
  Zombie* zombieList = zombieHorde(5, "test"); 
  for (int i = 0; i < 5; i++) {
    zombieList[i].announce();
	}

  delete[] zombieList; 
  return 0;
}
