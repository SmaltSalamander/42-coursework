/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/27 16:18:48 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

Point::Point() : _x(0), _y(0)
{
	// std::cout << "Default constructor called" << std::endl;
}

Point::Point(float const x, float const y) : _x(x), _y(y)

{
	// std::cout << "Float constructor called" << std::endl;
}

Point::~Point(void)
{
	// std::cout << "Destructor called" << std::endl;
}

Point::Point(Point const &ptr) : _x(ptr.getX()), _y(ptr.getY())
{
	// std::cout << "Copy constructor called" << std::endl;
}

Point &Point::operator=(Point const &)
{
	// std::cout << "Overload assignment operator called" << std::endl;
	return (*this);
}

Fixed const   &Point::getX() const
{
    return(this->_x);
}

Fixed const   &Point::getY() const
{
    return(this->_y);
}

// Fixed   absl(Fixed num)
// {
//     int result;
//     result = num.getRawBits();
//     if (result < 0)
//         num.setRawBits(result * -1);
//     return (num);
// }

// Fixed	calculateAreaTri(Point a, Point b, Point c)
// {
// 	Fixed	result;
// 	// std::cout << "here";
//     // result = a.getX() * (b.getY() - c.getY());
//     // Fixed res1 = (b.getX() * absl(c.getY() - a.getY()));
// 	// std::cout << result << std::endl;
//     // std::cout << res1 << std::endl;
// 	result = (
// 	std::cout << result << std::endl;
// 	return result;
// }

std::ostream &operator<<(std::ostream &outstrobj, Point const &right)
{
	outstrobj << "X: " << right.getX().toFloat() << ", Y: " << right.getY().toFloat();
	return (outstrobj);
}

