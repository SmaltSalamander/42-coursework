/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:29:40 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 10:47:42 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_U_HPP
# define ITERATOR_U_HPP
#include <iostream>
#include <cstdlib>

namespace ft
{
template <bool flag, class IsTrue, class IsFalse>
	struct choose;

template <class IsTrue, class IsFalse>
	struct choose<true, IsTrue, IsFalse>
	{
		typedef IsTrue type;
	};

template <class IsTrue, class IsFalse>
	struct choose<false, IsTrue, IsFalse>
	{
		typedef IsFalse type;
	};

template <	class Category,
			class T,
			class Distance = std::ptrdiff_t,
			class Pointer = T*,
			class Reference = T& 
		>
class iterator
{
public:
	typedef Category iterator_category;
	typedef T value_type;
	typedef Distance difference_type;
	typedef Pointer pointer;
	typedef Reference reference;
};

struct input_iterator_tag { };
struct output_iterator_tag { };
struct forward_iterator_tag : public input_iterator_tag { };
struct bidirectional_iterator_tag : public forward_iterator_tag { };
struct random_access_iterator_tag : public bidirectional_iterator_tag { };

template<typename _Iterator>
struct iterator_traits
{
	typedef typename _Iterator::iterator_category	iterator_category;
	typedef typename _Iterator::value_type			value_type;
	typedef typename _Iterator::difference_type		difference_type;
	typedef typename _Iterator::pointer		   		pointer;
	typedef typename _Iterator::reference		 	reference;
};
}
#endif