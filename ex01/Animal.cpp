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

Animal::Animal(const Animal& other) : type(other.type)
{
	std::cout << "Animal Copy Constructor: " << type << std::endl;
}

Animal& Animal::operator=(const Animal& rhs)
{
	std::cout << "Animal Copy Operator: " << type << std::endl;
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

const std::string& Animal::getType() const
{
	return (this->type);
}

void Animal::makeSound() const
{
	std::cout << "Animal Class Don't Make Sound" << std::endl;
}
