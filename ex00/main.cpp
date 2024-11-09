#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	{
		Animal* animal = new Animal();
		animal->makeSound();  // Animal Class Don't Make Sound
		delete animal;
		std::cout << std::endl;

		animal = new Dog();
		animal->makeSound();  // Woof!
		delete animal;
		std::cout << std::endl;

		animal = new Cat();
		animal->makeSound();  // Meow!
		delete animal;
	}
	std::cout << std::endl;

	{
		WrongAnimal* wrongAnimal = new WrongAnimal();
		wrongAnimal->makeSound();
		delete wrongAnimal;
		std::cout << std::endl;

		WrongAnimal* wrongAnimal_2 = new WrongCat();
		wrongAnimal_2->makeSound();
		delete wrongAnimal_2;
	}
	std::cout << std::endl;
}
