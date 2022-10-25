/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:12 by sbienias          #+#    #+#             */
/*   Updated: 2022/09/16 18:02:17 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft
{
template <class T1, class T2>
class pair
{
public:
	typedef T1			  first_type;
	typedef T2			  second_type;

	first_type 		first;
	second_type 	second;
// Constructors
	pair();
template<class U, class V>
	pair(const pair<U,V>& pr);
	pair(const first_type& a, const second_type& b);
// Destructors
	~pair();
// Overloads
	pair& operator= (const pair& pr);
};

// Non-member functions
template <class T1, class T2>
	ft::pair<T1,T2> make_pair( T1 t, T2 u );
template <class T1, class T2>
	bool operator==(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);
template <class T1, class T2>
	bool operator!=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);
template <class T1, class T2>
	bool operator<(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);
template <class T1, class T2>
	bool operator<=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);
template <class T1, class T2>
	bool operator>(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);
template <class T1, class T2>
	bool operator>=(const ft::pair<T1,T2>& lhs, const ft::pair<T1,T2>& rhs);
}

#include "pair.tpp"
#endif