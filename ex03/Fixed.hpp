/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 12:51:11 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 15:08:35 by mbirou           ###   ########.fr       */
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
		Fixed	&operator =(const Fixed &rhs);
		bool 	operator >(const Fixed &rhs) const;
		bool 	operator <(const Fixed &rhs) const;
		bool 	operator >=(const Fixed &rhs) const;
		bool 	operator <=(const Fixed &rhs) const;
		bool 	operator ==(const Fixed &rhs) const;
		bool 	operator !=(const Fixed &rhs) const;
		Fixed 	operator +(const Fixed &rhs) const;
		Fixed 	operator -(const Fixed &rhs) const;
		Fixed 	operator *(const Fixed &rhs) const;
		Fixed 	operator /(const Fixed &rhs) const;
		Fixed	operator ++(int);
		Fixed	&operator ++();
		Fixed	operator --(int);
		Fixed	&operator --();
		~Fixed();

		int					getRawBits( void ) const;
		void				setRawBits( int const raw );
		float				toFloat( void ) const;
		int					toInt( void ) const;
		static Fixed		&min(Fixed &a, Fixed &b);
		static const Fixed	&min(const Fixed &a, const Fixed &b);
		static Fixed		&max(Fixed &a, Fixed &b);
		static const Fixed	&max(const Fixed &a, const Fixed &b);
		void				Abs(void);

	private:
		int					_num;
		static const int	_bit = 8;
};

std::ostream 	&operator <<(std::ostream &ost, const Fixed &rhs);


#endif