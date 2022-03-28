/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/09 12:13:45 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/28 10:26:15 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char	**argv)
{
	int	counter;
	int i;

	counter = 1;
	if (argc == 1)
	{
		std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << std::endl;
		return (0);
	}
	while (counter < argc)
	{
		i = 0;
		while (argv[counter][i])
		{
			if (isalpha(argv[counter][i]))
				std::cout << (char) toupper(argv[counter][i]);
			else
				std::cout << argv[counter][i];
			i++;
		}
		counter++;
	}
	std::cout << std::endl;
	return (0);
}
