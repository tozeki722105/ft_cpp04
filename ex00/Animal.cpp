#include "Animal.hpp"

Animal::Animal() : type("Generic Animal")
{
	std::cout << "Animal Constructor: Generic Animal" << std::endl;
}

Animal::Animal(const std::string& t) : type(t)
{
	std::cout << "Animal Constructor: " << t << std::endl;
}

Animal::~Animal()
{
	std::cout << "Animal Destructor: " << type << std::endl;
}

Animal::Animal(const Animal& rhs) : type(rhs.type)
{
	std::cout << "Animal Copy Constructor: " << type << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	std::cout << "Animal Assignment Operator: " << type << std::endl;
	return (*this);
}

std::string Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Generic Animal Sound" << std::endl;
}
