/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/02 13:00:07 by sbienias         ###   ########.fr       */
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
	delete d;
	delete c;
	for (int i = 0; i < size; i++)
	{
		arr[i]->makeSound();
		delete arr[i];
	}
	cat.makeIdea(0, "fish");
	dog.makeIdea(0, "bones");
	std::cout << cat.getType() << " is thinking of " << cat.seeIdea(0) << std::endl;
	std::cout << dog.getType() << " is thinking of " << dog.seeIdea(0) << std::endl;
	return (0);
}