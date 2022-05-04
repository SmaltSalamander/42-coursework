/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 10:27:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/05/04 18:26:26 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cstdlib>
#include <iostream>
#include "iter.hpp"
#include "Data.hpp"

int main(void)
{
	int	arr[5] = {0, 1, 2, 3, 4};
	Data	data[3];
	::iter(arr, 5, ::print);
	arr[3] = 10;
	::iter(arr, 5, ::print);
	iter<Data>(data, 3, print);
	return (0);
}
