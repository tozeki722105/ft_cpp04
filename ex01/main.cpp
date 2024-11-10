#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{

	{
		Animal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
		for (int i = 0; i < 4; i++)
			delete animals[i];
	}
	std::cout << std::endl;
	

	// //ディープコピーテスト
	// {
	// 	Dog *a = new Dog();
	// 	{
	// 		Dog *b = new Dog();
	// 		*b = *a;
	// 		delete b;
	// 	}
	// 	delete a;	
	// }
	// std::cout << std::endl;

	// system("leaks -q a.out");
}
