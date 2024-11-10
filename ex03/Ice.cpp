#include "Ice.hpp"

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Constructor" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor" << std::endl;
}

Ice::Ice(const Ice& other) : AMateria(other)
{
	std::cout << "Ice Copy Constructor" << std::endl;
}

Ice& Ice::operator=(const Ice& other)
{
	std::cout << "Ice Copy Operator" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

AMateria* Ice::clone() const
{
	std::cout << "clone: " << _type << std::endl;
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}