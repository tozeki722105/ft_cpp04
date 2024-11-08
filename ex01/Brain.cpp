#include "Brain.hpp"
Brain::Brain()
{
	std::cout << "Brain Constructor" << std::endl;
}

Brain::~Brain()
{
	std::cout << "Brain Destructor" << std::endl;
}

Brain::Brain(const Brain& other)
{
	std::cout << "Brain Copy Constructor" << std::endl;
	for (size_t i = 0; i < maxIdeas; i++)
		this->ideas[i] = other.ideas[i];
}

Brain& Brain::operator=(const Brain& rhs)
{
	std::cout << "Brain Copy Operator: " << std::endl;
	if (this == &rhs)
		return (*this);
	for (size_t i = 0; i < maxIdeas; i++)
		this->ideas[i] = rhs.ideas[i];
	return (*this);
}