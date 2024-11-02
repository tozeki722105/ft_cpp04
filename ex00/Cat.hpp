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
	Cat(const Cat& other);
	Cat&         operator=(const Cat& rhs);
	virtual void makeSound() const;
};

#endif