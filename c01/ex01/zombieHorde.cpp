#include "Zombie.hpp"

Zombie*	zombieHorde( int N, std::string name )
{
	Zombie*	new_zombieHorde = new Zombie[N];
	for (int i = 0; i < N; i++) {
		new_zombieHorde[i].set_name(name);
	}
	return (new_zombieHorde);
}
