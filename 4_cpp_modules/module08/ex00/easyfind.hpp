/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/06 12:45:43 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP
#include <iostream>
#include <cstdlib>
#include <set>
#include <iterator>
#include <algorithm>

template<typename T>
typename T::iterator easyfind(T obj, int val)
{
	if (std::find(obj.begin(), obj.end(), val) == obj.end())
		throw (std::exception());
	else
		return (std::find(obj.begin(), obj.end(), val));
}

#endif