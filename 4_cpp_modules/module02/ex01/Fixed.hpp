/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/08 17:23:14 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cstdlib>
#include <cmath>

class	Fixed
{

private:
    int    _fixednum;
    static const int    _fracBitsNum = 8;
public:
	Fixed(void);
	Fixed(const int);
    Fixed(const float);
	~Fixed(void);
    Fixed(const Fixed &ptr);
    Fixed &operator=(Fixed const &right);
	int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &outstrobj, Fixed const &right);

#endif