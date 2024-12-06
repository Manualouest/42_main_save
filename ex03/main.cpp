/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbirou <mbirou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 14:26:13 by mbirou            #+#    #+#             */
/*   Updated: 2024/12/06 15:13:45 by mbirou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

static void callBsp(const Point &a, const Point &b, const Point &c, const Point &p);

int main()
{
    float x = 0;
    float y = 0;

    Point a(x, y);

    x = 2;
    y = 7;
    Point b(x, y);

    x = 4;
    y = 1;
    Point c(x, y);

    x = 3;
    y = 2;
    Point p(x, y);

    callBsp(a, b, c, p);

    x = -3;
    y = -2;
    p = Point(x, y);

    callBsp(a, b, c, p);
}

static void callBsp(const Point &a, const Point &b, const Point &c, const Point &p) {
    std::cout << "\033[36;1mThe point p (" << p.getX() << "; " << p.getY() << ") ";
    if (bsp(a, b, c, p))
        std::cout << "\033[32;1;4mis inside";
    else
        std::cout << "\033[31;1;4mis outside";
    std::cout << "\033[0m\033[36;1m the triangle.\033[0m" << std::endl;
}