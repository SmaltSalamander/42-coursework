/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/27 16:13:48 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_H
# define POINT_H
#include <iostream>
#include <cstdlib>
#include <string>
#include "Fixed.hpp"

class	Point
{

private:
    Fixed   _x;
    Fixed   _y;
public:
	Point(void);
    Point(const float, const float);
	~Point(void);
    Point(const Point &ptr);
    Point &operator=(Point const &rhs);
    Fixed const   &getX() const;
    Fixed const   &getY() const;
    // void   setX(Fixed);
    // void   setY(Fixed);
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

std::ostream &operator<<(std::ostream &outstrobj, Point const &right);

#endif