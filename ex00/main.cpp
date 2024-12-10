/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mawin.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/10 14:02:21 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/10 14:40:28 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <spellBook.hpp>

int main()
{
	{
		const Animal*	meta = new Animal();
		const Animal*	j = new Dog();
		const Animal*	i = new Cat();
		Cat				t;

		PRINT CYN BOLD "Type for Animal:" TAB AND meta->getType() ENDL;
		PRINT CYN BOLD "Type for Dog:" TAB TAB AND j->getType() ENDL;
		PRINT CYN BOLD "Type for Cat:" TAB TAB AND i->getType() ENDL;
		PRINT CYN BOLD "Type for Cat:" TAB TAB AND t.getType() ENDL;
		
		i->makeSound();
		j->makeSound();
		meta->makeSound();
		t.makeSound();
	}
	NEWL;
	{
		const WrongAnimal*	wmeta = new WrongAnimal();
		const WrongAnimal*	wi = new WrongCat();

		PRINT CYN BOLD "Type for WrongAnimal:" TAB AND wmeta->getType() ENDL;
		PRINT CYN BOLD "Type for WrongCat:" TAB AND wi->getType() ENDL;
		
		wi->makeSound();
		wmeta->makeSound();
	}
}
