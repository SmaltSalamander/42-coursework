/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   features.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/02 12:58:29 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 10:46:35 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FEATURES_HPP
# define FEATURES_HPP
#include <stdint.h>
#include "pair.hpp"
#include "iterator.hpp"

namespace ft
{
	template <class InputIterator>
	typename iterator_traits<InputIterator>::difference_type distance(InputIterator first, InputIterator last)
	{
		typename iterator_traits<InputIterator>::difference_type n = 0;

		while (first != last)
		{
			first++;
			n++;
		}
		return (n);
	}


// LESS
	template <class T>
	struct less : std::binary_function<T, T, bool>
	{
		bool operator()(const T& lhs, const T& rhs) const
		{
			return (lhs < rhs);
		} 
	};


// ENABLE_IF
	template<bool B, class T = void>
	struct enable_if {};
	
	template<class T>
	struct enable_if<true, T> { typedef T type; };

	template <class T, T v>
	struct integral_constant
	{
		const static T value = v;
		typedef T value_type;
		typedef integral_constant<T,v> type;
		operator T() { return v; }
	};

	
//Integral_constant wraps a static constant of specified type. It is the base class for the C++ type traits.
	typedef integral_constant<bool, true> true_type;
	typedef integral_constant<bool, false> false_type;

//Else
	template <class T> struct is_integral : false_type {};
//Integral types
	template <> struct is_integral<bool> : true_type {};
	template <> struct is_integral<char> : true_type {};
	template <> struct is_integral<wchar_t> : true_type {};
	template <> struct is_integral<signed char> : true_type {};
	template <> struct is_integral<short int> : true_type {};
	template <> struct is_integral<int> : true_type {};
	template <> struct is_integral<long int> : true_type {};
	template <> struct is_integral<long long int> : true_type {};
	template <> struct is_integral<unsigned char> : true_type {};
	template <> struct is_integral<unsigned short int> : true_type {};
	template <> struct is_integral<unsigned int> : true_type {};
	template <> struct is_integral<unsigned long int> : true_type {};
	template <> struct is_integral<unsigned long long int> : true_type {};

	template<class T>
	std::string	to_string(T num)
	{
		std::string	res;
		T			cpy = num;
		
		if (num == 0)
			return (res.append("0"));
		while (num)
		{
			cpy = num % 10;
			res.insert(0, 1, static_cast<char>(cpy + '0'));
			num /= 10;
		}
		return (res);
	}

	// Lexicographical Compare
	template<class InputIter1, class InputIter2>
	bool lexicographical_compare( InputIter1 first1, InputIter1 last1,
									InputIter2 first2, InputIter2 last2 )
	{
		while (first1 != last1 && first2 != last2)
		{
			if (*first2 < *first1)
				return (false);
			else if (*first1 < *first2)
				return (true);
			++first1;
			++first2;
		}
		return ((first1 == last1) && (first2 != last2));
	}

	template<class InputIter1, class InputIter2, class Compare>
	bool lexicographical_compare( InputIter1 first1, InputIter1 last1,
									InputIter2 first2, InputIter2 last2, Compare comp)
	{
		while (first1 != last1 && first2 != last2)
		{
			if (comp(*first2, *first1))
				return (false);
			else if (comp(*first1, *first2))
				return (true);
			++first1;
			++first2;
		}
		return (first1 == last1) && (first2 != last2);
	}
}

#endif