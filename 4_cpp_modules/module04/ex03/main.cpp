/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/31 18:35:36 by sbienias         ###   ########.fr       */
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
	std::cout << CY;
	test.equip(new Ice());
	test.equip(new Cure());
	test2.equip(new Cure());
	test2.unequip(1);
	test2 = test;
	test2.use(0, test);
	test.use(1, test2);
	// Usage test
	std::cout << BLANK;
	ICharacter* bob = new Character("bob");
	{
		Character jane("Jane");
		jane.equip(new Ice());
		Character jane2(jane);
		AMateria *adr = jane2.retrieveMateria(0);
		jane2.unequip(0);
		jane.use(0, jane2);
		delete adr;
	}
	std::cout << GR << "Usage test" << std::endl;
	wizard->use(2, *bob);
	wizard->use(1, *bob);
	std::cout << BLANK;
	delete bob;
	delete wizard;
	delete spellbook;
	return 0;
}
