#include "Cure.hpp"

Cure::Cure() : AMateria("cure")
{
	std::cout << "Cure Constructor" << std::endl;
}

Cure::~Cure()
{
	std::cout << "Cure Destructor" << std::endl;
}

Cure::Cure(const Cure& other) : AMateria(other)
{
	std::cout << "Cure Copy Constructor" << std::endl;
}

Cure& Cure::operator=(const Cure& other)
{
	std::cout << "Cure Copy Operator" << std::endl;
	if (this == &other)
		return *this;
	_type = other._type;
	return *this;
}

AMateria* Cure::clone() const
{
	return new Cure();
}

void Cure::use(ICharacter& target)
{
	std::cout << "* heals " << target.getName() << "'s wounds *" << std::endl;
}