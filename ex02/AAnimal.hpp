#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
	protected:
	std::string type;

	public:
	AAnimal();
	AAnimal(const std::string& t);
	virtual ~AAnimal();
	AAnimal(const AAnimal& rhs);
	AAnimal& operator=(const AAnimal& rhs);
	virtual void makeSound() const =0;
	std::string getType() const;
};

#endif