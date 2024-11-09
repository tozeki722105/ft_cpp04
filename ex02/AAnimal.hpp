#ifndef AANIMAL_HPP
#define AANIMAL_HPP

#include <iostream>
#include <string>

class AAnimal
{
protected:
	std::string type;

public:
	AAnimal(const std::string& t = "Generic AAnimal");
	virtual ~AAnimal();
	AAnimal(const AAnimal& other);
	AAnimal&           operator=(const AAnimal& rhs);
	virtual void       makeSound() const = 0;
	const std::string& getType() const;
};

#endif