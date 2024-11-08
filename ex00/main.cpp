#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	Animal* animal = new Animal();
	animal->makeSound();  // Animal Class Don't Make Sound
	delete animal;

	animal = new Dog();
	animal->makeSound();  // Woof!
	delete animal;

	animal = new Cat();
	animal->makeSound();  // Meow!
	delete animal;

	Cat myCat;
	myCat.makeSound();  // Meow!
	assert(myCat.getType() == "Cat");

	Dog myDog;
	myDog.makeSound();  // Woof!
	assert(myDog.getType() == "Dog");

	WrongAnimal* wrongAnimal = new WrongAnimal();
	wrongAnimal->makeSound();  // Wrong Animal Class Don't Make Sound
	delete wrongAnimal;

	wrongAnimal = new WrongCat();  // Slicing problem demonstration
	wrongAnimal->makeSound();      // Wrong Animal Class Don't Make Sound (because makeSound IS
								   // virtual in WrongAnimal)
	delete wrongAnimal;

	WrongCat badKitty;
	badKitty.makeSound();  // Moo? (Wrong sound, WrongCat's non-virtual method
						   // hides WrongAnimal's)

	// Copy constructor test
	Cat cat1;
	Cat cat2 = cat1;   // Copy constructor
	cat2.makeSound();  // Meow!

	// Assignment operator test
	Cat cat3;
	cat3 = cat2;       // Assignment operator
	cat3.makeSound();  // Meow!
}
