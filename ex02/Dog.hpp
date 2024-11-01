#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Dog : public AAnimal
{
private:
	Brain* brain;

public:
	Dog();
	virtual ~Dog();
	Dog(const Dog& rhs);
	Dog& operator=(const Dog& rhs);
	virtual void makeSound() const;
};

#endif