/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/21 14:39:56 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int main()
{
	IMateriaSource* src = new MateriaSource();
	ICharacter* me = new Character("me");

	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Ice());
	src->learnMateria(new Cure());
	src->learnMateria(new Cure());
	AMateria* tmp;
	tmp = src->createMateria("ice");
	me->equip(tmp);
	tmp = src->createMateria("cure");
	me->equip(tmp);
	tmp = src->createMateria("FIRA");
	me->equip(new Ice());
	me->equip(new Ice());
	me->equip(new Ice());
	me->equip(new Ice());
	me->equip(new Ice());
	// Deep copy test
	Character test("Ashe");
	Character test2("Brand");
	test.equip(new Ice());
	test.equip(new Ice());
	test2.equip(new Cure());
	test2 = test;
	test2.use(0, test);
	// Usage test
	ICharacter* bob = new Character("bob");
	me->use(2, *bob);
	me->use(1, *bob);
	delete bob;
	delete me;
	delete src;
	return 0;
}