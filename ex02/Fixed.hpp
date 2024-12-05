/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:51:11 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/05 13:17:26 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
	public:
		Fixed();
		Fixed(const Fixed &src);
		Fixed(const int &num);
		Fixed(const float &num);
		Fixed	&operator=(const Fixed &rhs);
		int 	&operator<<(std::ostream &ost, const Fixed &src);
		int 	&operator<<(std::ostream &ost, const Fixed &src);
		int 	&operator<<(std::ostream &ost, const Fixed &src);
		~Fixed();

		int		getRawBits( void ) const;
		void	setRawBits( int const raw );
		float	toFloat( void ) const;
		int		toInt( void ) const;

	private:
		int					_num;
		static const int	_bit = 8;
};

std::ostream 	&operator<<(std::ostream &ost, const Fixed &src);


#endif