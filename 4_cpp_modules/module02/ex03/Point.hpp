/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/08 18:04:58 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef POINT_HPP
# define POINT_HPP
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

std::ostream &operator<<(std::ostream &outstrobj, Point const &right);

#endif