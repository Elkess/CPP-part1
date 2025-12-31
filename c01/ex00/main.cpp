#include "Zombie.hpp"

int	main()
{
	Zombie*	heap_zombie = newZombie("heap_zombie");
	heap_zombie->announce();
	delete heap_zombie;
	randomChump("stack_zombie");
}
