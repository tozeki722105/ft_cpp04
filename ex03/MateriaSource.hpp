#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include <string>

#include "IMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
private:
	static const size_t _SLOTS_LIMIT = 4;
	AMateria*           _materia_slots[_SLOTS_LIMIT];

public:
	MateriaSource();
	virtual ~MateriaSource() {}
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);

	virtual void      learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const& type);
};

MateriaSource::MateriaSource()
{
	std::cout << "MateriaSource Constructor" << std::endl;
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		_materia_slots[i] = NULL;
	}
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
	std::cout << "MateriaSource Copy Constructor" << std::endl;
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (other._materia_slots[i]) {
			_materia_slots[i] = other._materia_slots[i]->clone();
		} else {
			_materia_slots[i] = NULL;
		}
	}
}

MateriaSource::~MateriaSource()
{
	std::cout << "MateriaSource Destructor" << std::endl;
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (_materia_slots[i]) {
			delete _materia_slots[i];
		}
	}
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
	std::cout << "MateriaSource Copy Operator" << std::endl;
	if (this == &other)
		return *this;
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

void MateriaSource::learnMateria(AMateria* new_materia)
{
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (!_materia_slots[i]) {
			_materia_slots[i] = new_materia;
			return;
		}
	}
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (_materia_slots[i] && type == _materia_slots[i]->getType())
			return _materia_slots[i]->clone();
	}
	return NULL;
}

#endif