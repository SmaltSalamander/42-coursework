/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/25 19:07:58 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_H
# define FIXED_H
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
	~Fixed(void);
    Fixed(const Fixed &ptr);
    //overload Fixed &operator=(Fixed const &right);
	int getRawBits( void ) const;
    void setRawBits( int const raw );
};

#endif