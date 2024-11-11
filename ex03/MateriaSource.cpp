#include "MateriaSource.hpp"

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
			std::cout << "Lean materia: " << new_materia->getType() << std::endl;
			return;
		}
	}
	std::cout << "MateriaSource's Materia_slots are full" << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const& type)
{
	for (size_t i = 0; i < _SLOTS_LIMIT; i++) {
		if (_materia_slots[i] && type == _materia_slots[i]->getType()) {
			std::cout << "Create materia: " << _materia_slots[i]->getType() << std::endl;
			return _materia_slots[i]->clone();
		}
	}
	std::cout << "No type " << type << " materia was found" << std::endl;
	return NULL;
}