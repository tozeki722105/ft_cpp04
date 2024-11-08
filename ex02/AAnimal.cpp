#include "AAnimal.hpp"

AAnimal::AAnimal() : type("Generic AAnimal")
{
	std::cout << "AAnimal Constructor: Generic AAnimal" << std::endl;
}

AAnimal::AAnimal(const std::string& t) : type(t)
{
	std::cout << "AAnimal Constructor: " << t << std::endl;
}

AAnimal::~AAnimal()
{
	std::cout << "AAnimal Destructor: " << type << std::endl;
}

AAnimal::AAnimal(const AAnimal& other) : type(other.type)
{
	std::cout << "AAnimal Copy Constructor: " << type << std::endl;
}

AAnimal& AAnimal::operator=(const AAnimal& rhs)
{
	std::cout << "AAnimal Copy Operator: " << type << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

const std::string& AAnimal::getType() const
{
	return (this->type);
}

void AAnimal::makeSound() const
{
	std::cout << "Generic AAnimal Sound" << std::endl;
}
