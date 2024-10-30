#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() : type("")
{
	std::cout << "WrongAnimal Constructor" << std::endl;
}

WrongAnimal::WrongAnimal(const std::string& t) : type(t)
{
	std::cout << "WrongAnimal Constructor " << "type is " << t << std::endl;
}

WrongAnimal::~WrongAnimal()
{
	std::cout << "WrongAnimal Destructor" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal& rhs) : type(rhs.type)
{
	std::cout << "WrongAnimal Copy Constructor" << std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

void WrongAnimal::makeSound() const
{
	std::cout << "Wrong Animal Sound" << std::endl;
}

std::string WrongAnimal::getType() const
{
	return (this->type);
}
