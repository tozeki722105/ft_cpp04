#include "Dog.hpp"

Dog::Dog() : AAnimal("Dog"), brain(new Brain())
{
	std::cout << "Dog Constructor" << std::endl;
}

Dog::~Dog()
{
	std::cout << "Dog Destructor" << std::endl;
	delete this->brain;
}

Dog::Dog(const Dog& rhs) : AAnimal(rhs.type), brain(new Brain(*(rhs.brain)))
{
	std::cout << "Dog copy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	if (this == &rhs)
		return (*this);
	this->type = rhs.type;
	delete this->brain;
	this->brain = new Brain(*(rhs.brain));
	return (*this);
}

void Dog::makeSound() const
{
	std::cout << "Woof!" << std::endl;
}
