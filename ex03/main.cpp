#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	//subject
	{
		IMateriaSource *src = new MateriaSource();
		std::cout << '\n';

		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		std::cout << '\n';

		ICharacter *me = new Character("me");
		std::cout << '\n';

		AMateria *tmp;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp = src->createMateria("cure");
		me->equip(tmp);
		std::cout << '\n';

		ICharacter *bob = new Character("bob");
		std::cout << '\n';

		me->use(0, *bob);
		me->use(1, *bob);
		std::cout << '\n';

		delete bob;
		std::cout << '\n';

		delete me;
		std::cout << '\n';

		delete src;
		std::cout << '\n';
	}

	//unequipテスト
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());

		ICharacter *me = new Character("me");
		AMateria   *ice = src->createMateria("ice");
		AMateria   *cure = src->createMateria("cure");

		me->equip(ice);
		me->equip(cure);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->unequip(0);
		std::cout << "unequip(0)" << std::endl;
		me->use(1, *bob);
		AMateria *cure2 = src->createMateria("cure");
		me->equip(cure2);
		me->use(0, *bob);
		me->use(1, *bob);
		delete bob;
		delete me;
		delete src;
		delete ice;
	}

	//akazukiテスト
	{
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		src->learnMateria(new Ice()); //leak
		src->learnMateria(new Cure()); //leak
		delete src;
	}
	{
		std::cout << "-------------subjectTest------------" << std::endl;
		IMateriaSource *src = new MateriaSource();
		src->learnMateria(new Ice());
		src->learnMateria(new Cure());
		ICharacter *me = new Character("me");
		AMateria   *tmp;
		AMateria   *tmp1;
		tmp = src->createMateria("ice");
		me->equip(tmp);
		tmp1 = src->createMateria("cure");
		me->equip(tmp1);
		me->unequip(1);
		ICharacter *bob = new Character("bob");
		me->use(0, *bob);
		me->use(1, *bob);
		me->use(5, *bob);
		delete tmp; //error-fact
		delete tmp1;
		delete bob;
		delete me;
		delete src; //crash
	}
}