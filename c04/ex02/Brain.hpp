#ifndef BRAIN_H
#define BRAIN_H

#include <iostream>

class Brain {
	std::string	ideas[100];
	public:
		Brain();
		Brain(const Brain& obj);
		Brain& operator=(const Brain& right);
		void	setIdea(std::string idea, size_t index);
		std::string	getIdea(size_t index) const;
		~Brain();
};

void	printer(std::string msg);

#endif