#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(const std::string& t) : type(t)
{
	std::cout << "WrongAnimal Constructor: " << t << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor: " << type << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& other) : type(other.type)
{
	std::cout << "WrongAnimal Copy Constructor: " << type << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	std::cout << "WrongAnimal Copy Operator: " << type << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal Class Don't Make Sound" << std::endl;
}

const std::string& WrongAnimal::getType() const
{
	return (this->type);
}
