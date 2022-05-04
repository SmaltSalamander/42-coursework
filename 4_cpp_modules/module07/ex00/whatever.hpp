/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/04 16:40:18 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdint.h>

template<typename whatever>
void swap(whatever &a, whatever &b)
{
	whatever temp;
	temp = a;
	a = b;
	b = temp;
}

template<typename whatever>
whatever const &min(whatever const &a, whatever const &b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

template<typename whatever>
whatever const &max(whatever const &a, whatever const &b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

#endif