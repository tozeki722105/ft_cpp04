#ifndef ICE_HPP
#define ICE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Ice : public AMateria
{
public:
	Ice();
	~Ice();
	virtual AMateria* clone() const;
	virtual void      use(ICharacter& target);
};

Ice::Ice() : AMateria("ice")
{
	std::cout << "Ice Constructor" << std::endl;
}

Ice::~Ice()
{
	std::cout << "Ice Destructor" << std::endl;
}

AMateria* Ice::clone() const
{
	return new Ice();
}

void Ice::use(ICharacter& target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *";
}

#endif