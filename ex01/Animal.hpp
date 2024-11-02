#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>

class Animal
{
protected:
	std::string type;

public:
	Animal();
	Animal(const std::string& t);
	virtual ~Animal();
	Animal(const Animal& other);
	Animal&            operator=(const Animal& rhs);
	virtual void       makeSound() const;
	const std::string& getType() const;
};

#endif