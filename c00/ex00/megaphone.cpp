#include <iostream>

void	ft_printer(std::string s)
{
	std::cout << s << "\n";
}

std::string	ft_string_to_upper(std::string s)
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
		ft_printer("* LOUD AND UNBEARABLE FEEDBACK NOISE *");
	else
	{
		while (av[i])
		{
			buff += ft_string_to_upper(av[i]);
			i++;
		}
		ft_printer(buff);
	}

}