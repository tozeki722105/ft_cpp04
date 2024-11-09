#ifndef CURE_HPP
#define CURE_HPP

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Cure : public AMateria
{
public:
	Cure();
	~Cure();
	virtual AMateria* clone() const;
	virtual void      use(ICharacter& target);
};

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Constructor" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor" << std::endl;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *";
}

#endif