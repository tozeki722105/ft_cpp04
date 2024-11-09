#include "AMateria.hpp"

AMateria::AMateria(std::string const& type) : _type(type)
{
	std::cout << "AMateria Constructor: " << _type << std::endl;
}

AMateria::~AMateria()
{
	std::cout << "AMateria  Destructor: " << _type << std::endl;
}

AMateria::AMateria(const AMateria& other) : _type(other.getType())
{
	std::cout << "AMateria Copy Constructor: " << _type << std::endl;
}

AMateria& AMateria::operator=(const AMateria& other)
{
	std::cout << "Animal Copy Operator: " << other._type << std::endl;
	if (this == &other)
		return (*this);
	_type = other._type;
	return (*this);
}

std::string const& AMateria::getType() const
{
	return _type;
}

void AMateria::use(ICharacter& target)
{
	std::cout << _type << " use on " << target.getName() << std::endl;
}