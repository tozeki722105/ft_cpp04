#include "WrongCat.hpp"

WrongCat::WrongCat() : WrongAnimal("WrongCat")
{
	std::cout << "WrongCat Constructor" << std::endl;
}

WrongCat::~WrongCat()
{
	std::cout << "WrongCat Destructor" << std::endl;
}

WrongCat::WrongCat(const WrongCat& other) : WrongAnimal(other.type)
{
	std::cout << "WrongCat copy Constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Moo?" << std::endl;
}
