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
	virtual ~MateriaSource();
	MateriaSource(const MateriaSource& other);
	MateriaSource& operator=(const MateriaSource& other);

	virtual void      learnMateria(AMateria*);
	virtual AMateria* createMateria(std::string const& type);
};

#endif