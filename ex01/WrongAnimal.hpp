#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal
{
protected:
	std::string type;

public:
	WrongAnimal(const std::string& t = "Generic WrogAnimal");
	virtual ~WrongAnimal();
	WrongAnimal(const WrongAnimal& other);
	WrongAnimal&       operator=(const WrongAnimal& rhs);
	void               makeSound() const;
	const std::string& getType() const;
};

#endif