#include <iostream>

void	printer(std::string s)
{
	std::cout << s << "\n";
}

std::string	str_to_upper(std::string s)
{
	std::string	upper_s = "";
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
	std::string	buff = "";

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