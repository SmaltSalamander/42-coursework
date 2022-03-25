/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 16:15:32 by sbienias          #+#    #+#             */
/*   Updated: 2022/03/25 16:51:22 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_H
# define HARL_H
#include <iostream>
#include <cstdlib>
#include <string>
using std::string;

class	Harl
{

private:
    void    debug(void);
    void    info(void);
    void    warning(void);
    void    error(void);
public:
	Harl(void);
	~Harl(void);
	void			filter(string level);
};

#endif