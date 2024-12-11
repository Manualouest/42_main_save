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

#include "Cat.hpp"
#include "Dog.hpp"
#include "WrongCat.hpp"
#include <spellBook.hpp>

int main()
{
	{
		Animal	**animals = new Animal*[10];
		for (int i = 0; i < 10; ++i)
		{
			if (i < 5)
				animals[i] = new Cat();
			else
				animals[i] = new Dog();
		}
		for (int i = 0; i < 10; ++i)
		{
			animals[i]->makeSound();
			delete animals[i];
		}
		delete []animals;
	}
	NEWL;
	{
		Cat	cat;
		{
			Cat ncat = cat;
			PRINT BOLD "Ncat's brain address: " TAB UNDL AND ncat.getBrainAddr() AND CLR ENDL;
		}
		PRINT BOLD "Cat's brain address: " TAB UNDL AND cat.getBrainAddr() AND CLR ENDL;
		
	}
	NEWL;
	{
		Dog	dog;
		{
			Dog ndog = dog;
			PRINT BOLD "Ndog's brain address: " TAB UNDL AND ndog.getBrainAddr() AND CLR ENDL;
		}
		PRINT BOLD "dog's brain address: " TAB UNDL AND dog.getBrainAddr() AND CLR ENDL;
		
	}
}
