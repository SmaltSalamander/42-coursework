/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/04 18:17:32 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
# define ITER_HPP
#include <iostream>
#include <cstdlib>
#include <string>
#include <stdint.h>

template<typename type>
void iter(type *adr, int len, void (*f)(type const &))
{
	for (int i = 0; i < len; i++)
		f(adr[i]);
}

template<typename type>
void print(type &adr)
{
	std::cout << adr << std::endl;
}

#endif