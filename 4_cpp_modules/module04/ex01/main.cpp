/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/31 16:37:39 by sbienias         ###   ########.fr       */
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
	const Animal  *d = new Dog();
	const Animal *c = new Cat();
	int				size = 6;
	Dog				dog;
	Cat				cat;

	Animal *arr[6];
	for (int i = 0; i < size / 2; i++)
	{
		arr[i] = new Dog();
	}
	for (int i = size / 2; i < size; i++)
	{
		arr[i] = new Cat();
	}
	std::cout << GR << "CONSTRUCTION DONE" << std::endl << BLANK;
	delete d;
	delete c;
	std::cout << RED << "DELETED d and c" << std::endl << BLANK;
	for (int i = 0; i < size; i++)
	{
		std::cout << CY << i << std::endl;
		arr[i]->makeSound();
		std::cout << BLANK;
		delete arr[i];
	}
	cat.makeIdea(0, "fish");
	dog.makeIdea(0, "bones");
	std::cout << YE << cat.getType() << " is thinking of " << cat.seeIdea(0) << std::endl;
	std::cout << dog.getType() << " is thinking of " << dog.seeIdea(0) << std::endl;
	std::cout << cat.getType() << " is thinking of " << cat.seeIdea(1) << std::endl << BLANK;
	{
		Dog test(dog);
		Dog test1;
		test1 = dog;
		std::cout << test.getBrain() << " " << dog.getBrain() << std::endl;
		std::cout << PU << test.getType() << " in separate scope is thinking of " << test.seeIdea(0) << std::endl;
	}
	std::cout << dog.getType() << " is thinking of " << dog.seeIdea(0) << std::endl << BLANK;
	return (0);
}
