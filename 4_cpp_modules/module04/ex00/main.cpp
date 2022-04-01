/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/31 09:47:07 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();
	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();
	delete meta;
	delete i;
	delete j;
	const Animal* a = new Animal();
	const Dog* b = new Dog();
	const Cat* c = new Cat();
	std::cout << b->getType() << " " << std::endl;
	std::cout << c->getType() << " " << std::endl;
	b->makeSound(); //will output the cat sound!
	c->makeSound();
	a->makeSound();
	delete a;
	delete b;
	delete c;
	const WrongAnimal* z = new WrongCat();
	std::cout << z->getType() << " " << std::endl;
	z->makeSound();
	delete z;
	return 0;
}