/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:28:40 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 15:21:09 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP

# include "Fixed.hpp"

class Point
{
	public:
		Point();
		Point(const float &x, const float &y);
		Point(const Point &point);
		Point	&operator =(const Point &rhs);
		~Point();

		const Fixed	&getX() const;
		const Fixed	&getY() const;

	private:
		Fixed	_x;
		Fixed	_y;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif