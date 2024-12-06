/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:52:22 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 15:12:20 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Fixed	area(const Point &p1, const Point &p2, const Point &p3)
{
	Fixed	area;

	area = (p1.getX() * (p2.getY() - p3.getY())
			+ p2.getX() * (p3.getY() - p1.getY())
			+ p3.getX() * (p1.getY() - p2.getY())) / 2.0f;
	area.Abs();
	return (area);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	Fixed	abc;
	Fixed	abp;
	Fixed	acp;
	Fixed	bcp;

	abc = area(a, b, c);
	abp = area(a, b, point);
	acp = area(a, c, point);
	bcp = area(b, c, point);
	if (abp * acp * bcp == 0)
		return (false);
	return (abc == (abp + acp + bcp));
}
