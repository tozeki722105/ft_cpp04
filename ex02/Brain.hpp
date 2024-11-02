#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain
{
private:
	const static size_t maxIdeas = 100;
	std::string         ideas[maxIdeas];

public:
	Brain();
	~Brain();
	Brain(const Brain& other);
	Brain& operator=(const Brain& rhs);
};

#endif