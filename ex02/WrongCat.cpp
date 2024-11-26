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
	std::cout << "WrongCat Copy Constructor" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat& rhs)
{
	std::cout << "WrongCat Copy Operator: " << type << std::endl;
	if (this == &rhs)
		return (*this);
	WrongAnimal::operator=(rhs);
	return (*this);
}

void WrongCat::makeSound() const
{
	std::cout << "Moo?" << std::endl;
}
