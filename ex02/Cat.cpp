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

Cat::Cat(const Cat& rhs) : AAnimal(rhs.type), brain(new Brain(*(rhs.brain)))
{
	std::cout << "Cat copy Constructor" << std::endl;
}

Cat& Cat::operator=(const Cat& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	delete this->brain;
	this->brain = new Brain(*(rhs.brain));
	return (*this);
}

void Cat::makeSound() const
{
	std::cout << "Meow!" << std::endl;
}
