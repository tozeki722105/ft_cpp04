#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include <string>

#include "Animal.hpp"

class Cat : public Animal
{
public:
	Cat();
	virtual ~Cat();
	Cat(const Cat& rhs);
	Cat& operator=(const Cat& rhs);
	virtual void makeSound() const;
};

#endif