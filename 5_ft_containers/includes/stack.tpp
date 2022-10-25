/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:22:05 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/24 14:16:53 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_TPP
# define STACK_TPP
#include "stack.hpp"


template <typename T, class Container>
bool ft::stack<T, Container>::empty() const
{
	return (_cont.empty());
}

template <typename T, class Container>
typename ft::stack<T, Container>::size_type
ft::stack<T, Container>::size() const
{
	return (_cont.size());
}

template <typename T, class Container>
typename ft::stack<T, Container>::value_type&
ft::stack<T, Container>:: top()
{
	return (_cont.back());
}

template <typename T, class Container>
const typename ft::stack<T, Container>::value_type&
ft::stack<T, Container>::top() const
{
	return (_cont.back());
}

template <typename T, class Container>
void ft::stack<T, Container>::push(const value_type& val)
{
	_cont.push_back(val);
}

template <typename T, class Container>
void ft::stack<T, Container>::pop()
{
	_cont.pop_back();
}


#endif