#include <iostream>

void	printer(str s)
{
	std::cout << s << "\n";
}

str	str_to_upper(str s)
{
	str	upper_s = "";
	int	i=0;
	while(s[i])
	{
		upper_s += toupper(s[i]);
		i++;
	}
	return (upper_s) ;
}

int	main(int ac, char **av)
{
	int			i    = 1;
	str	buff = "";

	if (ac == 1)
		printer("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	else
	{
		while (av[i])
		{
			buff += str_to_upper(av[i]);
			i++;
		}
		printer(buff);
	}

}