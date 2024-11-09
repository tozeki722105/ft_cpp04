#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include <string>

class AMateria
{
protected:
	[...];

public:
	AMateria(std::string const& type);
	[...];
	std::string const& getType() const;  // マテリアの種類を返す
	virtual AMateria*  clone() const = 0;
	virtual void       use(ICharacter& target);
};

#endif