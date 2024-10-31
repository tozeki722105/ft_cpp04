#include "AAnimal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
    // const Cat* i = new Cat();
	const AAnimal* j = new Dog();

    j->makeSound();
    delete j;//should not create a leak
    // delete i;

    system("leaks -q a.out");
}