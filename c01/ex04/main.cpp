#include <iostream>
#include <fstream>

void	err_printer(std::string str)
{
	std::cerr << str << std::endl;
}

int	main(int ac, char **av)
{
	if (ac == 4)
	{
		std::string filename = av[1];
		std::string s1 = av[2];
		std::string s2 = av[3];			
		std::ifstream file(filename.c_str());
		if (!file)
		{
			err_printer("Failed to open file:" + filename);
			return (1);
		}
		std::string	line;
		std::string	buff;
		while(std::getline(file, line))
		{
			if (!file.eof())
				line += '\n';
			if (s1 != s2)
			{				
				unsigned long pos = line.find(s1);
				while(pos != std::string::npos)
				{
					std::string before = line.substr(0, pos);
					std::string after = line.substr(pos + s1.length());
					line = before + s2 + after;
					pos = line.find(s1);
				}
			}
			buff += line;
		}
		std::ofstream	outfile(filename+".replace");
		outfile.write(buff.c_str(), buff.length());
		return (0);
	}
	err_printer("Only four parameters required, plz!");
	return (1);
}
