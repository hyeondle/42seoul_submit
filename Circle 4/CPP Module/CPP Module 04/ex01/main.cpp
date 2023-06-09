/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyeondle <hyeondle@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 03:28:06 by hyeondle          #+#    #+#             */
/*   Updated: 2023/05/28 03:29:12 by hyeondle         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void)
{
	std::string str;
	Animal *tab[10];

	for (size_t i = 0; i < 10; i++)
	{
		if (i % 2)
		{
			tab[i] = new Dog();
		}
		else
		{
			tab[i] = new Cat();
		}
	}
	std::cout << std::endl;

	for (size_t i = 0; i < 10; i++)
	{
		delete tab[i];
	}
	std::cout << std::endl;


	Cat *d = new Cat();
	Cat *d2 = new Cat();
	std::cout << std::endl;
	str = d->getBrain()->getIdeas(0);
	std::cout << "Cat1's first idea is "<< str << std::endl;

	d->getBrain()->setIdeas(0, "something");
	str = d->getBrain()->getIdeas(0);
	std::cout << "Cat1's first idea is "<< str << std::endl;

	*d2 = *d;
	str = d2->getBrain()->getIdeas(0);
	std::cout << "Cat2's first idea is "<< str << std::endl;

	std::cout << std::endl;
	delete d;
	d = NULL;
	delete d2;
	d2 = NULL;


	// system("leaks Crying_ver2");
	return 0;
}

/*
int main() {
    const Animal* meta = new Animal();
    const Animal* j = new Dog();
    const Animal* i = new Cat();

    std::cout << j->getType() << " " << std::endl;
    std::cout << i->getType() << " " << std::endl;

    i->makeSound();
    j->makeSound();
    meta->makeSound();

    delete meta;
    delete j;
    delete i;

    const WrongAnimal* wrong_meta = new WrongAnimal();
    const WrongAnimal* wrong_i = new WrongCat();

    std::cout << wrong_i->getType() << " " << std::endl;

    wrong_i->makeSound();
    wrong_meta->makeSound();

    delete wrong_meta;
    delete wrong_i;

	const Animal* x = new Dog();
	const Animal* y = new Cat();

	delete x;
	delete y;

    return 0;
}
*/