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

Dog::Dog(const Dog& other) : AAnimal(other.type), brain(new Brain(*(other.brain)))
{
	std::cout << "Dog copy Constructor" << std::endl;
}

Dog& Dog::operator=(const Dog& rhs)
{
	std::cout << "Dog Assignment Operator: " << type << std::endl;
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
