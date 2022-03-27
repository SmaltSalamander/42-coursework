/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsp.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/27 16:46:21 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

//True if left of the AB line
bool    pointLeftRight(Point const a, Point const b, Point const c)
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
    u = pointLeftRight(point, a, b);
    w = pointLeftRight(point, b, c);
    v = pointLeftRight(point, c, a);
    if (u && w && v)
        return (true);
    else if (!u && !w && !v)
        return (true);
    return (false);
}
