#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <iostream>
#include <string>

#include "ICharacter.hpp"

class AMateria
{
protected:
	std::string _type;

public:
	AMateria(std::string const& type = "AMateria");
	~AMateria();
	AMateria(const AMateria& other);
	AMateria&          operator=(const AMateria& other);
	std::string const& getType() const;  // マテリアの種類を返す
	virtual AMateria*  clone() const = 0;
	virtual void       use(ICharacter& target);
};

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
	if (this == &other)
		return (*this);
	std::cout << "Animal Copy Operator: " << other._type << std::endl;
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

#endif