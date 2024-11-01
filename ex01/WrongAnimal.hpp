#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal();
	WrongAnimal(const std::string& t);
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& rhs);
	WrongAnimal& operator=(const WrongAnimal& rhs);
	virtual void makeSound() const;
	std::string getType() const;
};

#endif