#include "AAnimal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	
	{
		AAnimal* animals[4] = {new Dog(), new Dog(), new Cat(), new Cat()};
		for (int i = 0; i < 4; i++)
			delete animals[i];
	}

	// // コンパイルエラーテスト
	// {
	// 	AAnimal *aAnimal = new AAnimal();
	// }

	// system("leaks -q a.out");
}
