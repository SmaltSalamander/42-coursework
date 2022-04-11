/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/11 12:15:03 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.h"

//True if outside of the vector (3rd dimension facing towards the screen, false if outside) 
// (x1 - x3) * (y2 - y3) - (x2 - x3) * (y1 - y3)
// vector has length and directions (magnitude)
// vector's direction can be calculated by subtracting X and Y values of two points
// Cross product of two vectors = (x1 * y2 - y1 * x2)
// where x1 is a vector from two points (AC) y2 vector from BC
// x2 is from BC and y1 is AC
bool    crossProduct(Point const a, Point const b, Point const c)
{
    Fixed retval;

    retval = (a.getX() - c.getX()) * (b.getY() - c.getY()) - (b.getX() - c.getX()) * (a.getY() - c.getY());
    if (retval < 0)
        return (true);
    return (false);
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
    bool   u;
    bool   w;
    bool   v;

    u = crossProduct(point, a, b);
    w = crossProduct(point, b, c);
    v = crossProduct(point, c, a);
    if (u && w && v)
        return (true);
    else if (!u && !w && !v)
        return (true);
    return (false);
}
