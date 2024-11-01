#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "AAnimal.hpp"
#include "Brain.hpp"

class Cat : public AAnimal
{
private:
	Brain* brain;

public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	virtual void makeSound() const;
};

#endif