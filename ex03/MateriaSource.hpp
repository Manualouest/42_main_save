/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 14:26:49 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/28 18:27:35 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
# define MATERIASOURCE_HPP

#include "IMateriaSource.hpp"
#include <spellBook.hpp>

class MateriaSource : public IMateriaSource
{
	public:
		MateriaSource();
		MateriaSource(const MateriaSource &src);
		MateriaSource	&operator =(const MateriaSource &rhs);
		~MateriaSource();

		void learnMateria(AMateria *materia);
		AMateria* createMateria(std::string const & type);

	private:
		AMateria	*_templates[4];
		AMateria	**_storage;
		int			_storageLen;
};

#endif