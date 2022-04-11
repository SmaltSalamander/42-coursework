/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/04/08 17:23:07 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
# define FIXED_HPP
#include <iostream>
#include <cstdlib>
#include <string>

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
    Fixed &operator=(Fixed const &rhs);

    //Comparison operators
    bool  operator>(const Fixed &rhs) const;
    bool  operator<(const Fixed &rhs) const;
    bool  operator>=(const Fixed &rhs) const;
    bool  operator<=(const Fixed &rhs) const;
    bool  operator==(const Fixed &rhs) const;
    bool  operator!=(const Fixed &rhs) const;

    
    //Arithmetic operators
    Fixed operator+(const Fixed &rhs) const;
    Fixed operator-(const Fixed &rhs) const;
    Fixed operator*(const Fixed &rhs) const;
    Fixed operator/(const Fixed &rhs) const;

    //Incrementation/Decrementation operators
    Fixed operator++(int);
    Fixed operator--(int);
    Fixed &operator++(void);
    Fixed &operator--(void);
    
	int getRawBits( void ) const;
    void setRawBits( int const raw );
    float toFloat( void ) const;
    int toInt( void ) const;
    static Fixed &min(Fixed &num1, Fixed &num2);
    static const Fixed &min(Fixed const &num1, Fixed const &num2);
    static Fixed &max(Fixed &num1, Fixed &num2);
    static const Fixed& max(Fixed const &num1, Fixed const &num2);
};

std::ostream &operator<<(std::ostream &outstrobj, Fixed const &right);

#endif