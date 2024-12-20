#include "Cat.hpp"

Cat::Cat() : AAnimal("Cat"), brain(new Brain())
{
	std::cout << "Cat Constructor" << std::endl;
}

Cat::~Cat()
{
	std::cout << "Cat Destructor" << std::endl;
	delete this->brain;
}

Cat::Cat(const Cat& other) : AAnimal(other.type), brain(new Brain(*(other.brain)))
{
	std::cout << "Cat Copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	std::cout << "Cat Copy Operator: " << type << std::endl;
	if (this == &rhs)
		return (*this);
	AAnimal::operator=(rhs);
	delete this->brain;
	this->brain = new Brain(*(rhs.brain));
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
