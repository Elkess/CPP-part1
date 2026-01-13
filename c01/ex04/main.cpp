#include <iostream>
#include <fstream>

void	printer(std::string str)
{
	std::cout << str << std::endl;
}

void	replace(std::string filename, std::string s1, std::string s2)
{
	std::ifstream file(filename.c_str());
	if (!file)
	{
		printer("Failed to open file:" + filename);
		return ;
	}
	if (s1.empty())
	{
		printer("S1 should not be empty!");
		return ;
	}
	std::string	line, buff;
	while(std::getline(file, line))
	{
		if (!file.eof())
			line += '\n';
		unsigned long pos = line.find(s1);
		while(pos != std::string::npos)
		{
			std::string before = line.substr(0, pos);
			std::string after = line.substr(pos + s1.length());
			line = before + s2 + after;
			pos = line.find(s1, pos + s2.length());
		}
		buff += line;
	}
	std::ofstream	outfile(filename+".replace");
	outfile.write(buff.c_str(), buff.length());
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];
		replace(filename, s1, s2);
		return (0);
	}
	printer("Only four parameters required, plz!");
	return (1);
}
