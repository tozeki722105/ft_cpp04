#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <string>

#include "AMateria.hpp"
#include "ICharacter.hpp"

class Character : public ICharacter
{
private:
	Character();

	std::string         _name;
	static const size_t _SLOTS_LIMIT = 4;
	AMateria*           _materia_slots[_SLOTS_LIMIT];

public:
	Character(std::string name);
	virtual ~Character();
	Character(const Character& other);
	Character& operator=(const Character& other);

	virtual std::string const& getName() const;
	virtual void               equip(AMateria* m);
	virtual void               unequip(int idx);
	virtual void               use(int idx, ICharacter& target);
};

#endif