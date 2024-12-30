/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 12:18:16 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/30 15:51:47 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "MateriaSource.hpp"

int	main(void)
{
	ICharacter	*Jhon = new Character("Jhon");
	ICharacter	*SW = new Character();
	IMateriaSource	*source = new MateriaSource();

	source->learnMateria(new Ice);
	source->learnMateria(new Ice);
	source->learnMateria(new Cure);
	source->learnMateria(new Cure);
	source->learnMateria(new Cure);
	source->learnMateria(NULL);
	NEWL;

	Jhon->equip(source->createMateria("ice"));
	Jhon->equip(source->createMateria("ice"));
	Jhon->equip(source->createMateria("cure"));
	Jhon->equip(source->createMateria("cure"));
	Jhon->equip(source->createMateria("cure"));
	Jhon->equip(NULL);
	Jhon->equip(source->createMateria("fire"));
	NEWL;

	Jhon->unequip(10);
	Jhon->unequip(-10);
	Jhon->unequip(0);
	Jhon->unequip(0);
	Jhon->unequip(0);
	Jhon->unequip(0);
	Jhon->unequip(0);
	NEWL;

	SW->equip(source->createMateria("ice"));
	SW->equip(source->createMateria("cure"));
	SW->use(0, *Jhon);
	SW->use(1, *Jhon);
	SW->use(-1, *Jhon);
	SW->use(5, *Jhon);
	SW->unequip(0);
	SW->unequip(0);
	SW->use(5, *Jhon);
	NEWL;

	delete Jhon;
	delete SW;

	delete source;
}
