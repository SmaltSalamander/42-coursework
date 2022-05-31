/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/23 10:36:29 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "AMateria.hpp"
#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"
#include "color.h"

int main()
{
	IMateriaSource* spellbook = new MateriaSource();
	ICharacter* wizard = new Character("Harry");

	std::cout << CY << "Spellbook acquiring new spells" << std::endl;
	spellbook->learnMateria(new Ice());
	std::cout << GR;
	spellbook->learnMateria(new Cure());
	std::cout << CY;
	spellbook->learnMateria(new Ice());
	std::cout << GR;
	spellbook->learnMateria(new Cure());
	spellbook->learnMateria(new Cure());
	std::cout << BLANK;
	AMateria* tmp;
	tmp = spellbook->createMateria("ice");
	wizard->equip(tmp);
	tmp = spellbook->createMateria("cure");
	wizard->equip(tmp);
	tmp = spellbook->createMateria("FIRA");
	wizard->equip(new Ice());
	wizard->equip(new Ice());
	wizard->equip(new Ice());
	wizard->equip(new Ice());
	wizard->equip(new Ice());
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
	wizard->use(2, *bob);
	wizard->use(1, *bob);
	delete bob;
	delete wizard;
	delete spellbook;
	return 0;
}