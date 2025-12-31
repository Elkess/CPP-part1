# include "Zombie.hpp"


void f(){system("leaks horde_of_zombies");}

int main()
{
	atexit(f);
	int	n = 3;
	Zombie* zombies = zombieHorde(n, "Zimbombah");
	for (int i = 0; i < n; i++) {
		zombies[i].announce();
	}
	delete[] zombies;
}
