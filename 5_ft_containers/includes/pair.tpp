/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.tpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/09/16 18:02:57 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef pair_TPP
# define pair_TPP
#include "pair.hpp"

namespace ft
{
// Constructors

template <class T1, class T2>
pair<T1, T2>::pair() : first(), second()
{
}

template <class T1, class T2>
template<class U, class V>
pair<T1, T2>::pair(const pair<U,V>& pr) : first(pr.first), second(pr.second)
{
}

template <class T1, class T2>
pair<T1, T2>::pair(const first_type& a, const second_type& b) : first(a), second(b)
{
}

// Destructor
template <class T1, class T2>
pair<T1, T2>::~pair()
{

}

// Overloads
template <class T1, class T2>
pair<T1, T2>&  pair<T1, T2>::operator=(const pair& pr)
{
	first = pr.first;
	second = pr.second;
	return (*this);
}

template <class T1, class T2>
ft::pair<T1,T2> make_pair( T1 t, T2 u )
{
	return (ft::pair<T1, T2>(t, u));
}

template <class T1, class T2>
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	if (lhs.first == rhs.first)
		if (lhs.second == rhs.second)
			return (true);
	return (false);
}

template <class T1, class T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	if (lhs.first == rhs.first)
		if (lhs.second == rhs.second)
			return (false);
	return (true);
}

template <class T1, class T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	if (lhs.first >= rhs.first)
		if (lhs.second >= rhs.second)
			return (false);
	return (true);
}

template <class T1, class T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	if (lhs.first <= rhs.first)
		if (lhs.second <= rhs.second)
			return (true);
	return (false);
}

template <class T1, class T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	if (lhs.first <= rhs.first)
		if (lhs.second <= rhs.second)
			return (false);
	return (true);
}

template <class T1, class T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs)
{
	if (lhs.first >= rhs.first)
		if (lhs.second >= rhs.second)
			return (true);
	return (false);
}

}
#endif