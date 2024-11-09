#include "Character.hpp"

Character::Character(std::string name) : _name(name)
{
	std::cout << "Character Constructor: " << name << std::endl;
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		_materia_slots[i] = NULL;
	}
}

Character::Character(const Character& other)
{
	std::cout << "Character Copy Constructor: " << other._name << std::endl;

	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (other._materia_slots[i]) {
			_materia_slots[i] = other._materia_slots[i]->clone();
		} else {
			_materia_slots[i] = NULL;
		}
	}
}

Character::~Character()
{
	std::cout << "Character Destructor: " << _name << std::endl;
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (_materia_slots[i]) {
			delete _materia_slots[i];
		}
	}
}

Character& Character::operator=(const Character& other)
{
	std::cout << "Character Copy Operator: " << other._name << std::endl;
	if (this == &other)
		return *this;
	_name = other._name;
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (_materia_slots[i]) {
			delete _materia_slots[i];
		}
	}
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (other._materia_slots[i]) {
			_materia_slots[i] = other._materia_slots[i]->clone();
		} else {
			_materia_slots[i] = NULL;
		}
	}
	return *this;
}

std::string const& Character::getName() const
{
	return _name;
}

void Character::equip(AMateria* m)
{
	if (!m)
		return;
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (!_materia_slots[i]) {
			_materia_slots[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx)
{
	if (idx < 0 || idx >= static_cast<int>(_SLOTS_LIMIT) || !_materia_slots[idx])
		return;
	_materia_slots[idx] = NULL;
}

void Character::use(int idx, ICharacter& target)
{
	if (idx < 0 || idx >= static_cast<int>(_SLOTS_LIMIT) || !_materia_slots[idx])
		return;
	_materia_slots[idx]->use(target);
}