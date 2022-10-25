/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_v.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:29:20 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 10:46:52 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_VEC_HPP
# define ITERATOR_VEC_HPP
#include <iostream>
#include <cstdlib>
#include "iterator.hpp"
#include "rev_iterator.hpp"

namespace ft
{
template <class T, bool is_const>
class vec_iterator : public iterator<ft::random_access_iterator_tag, T>
{
public:
	typedef typename ft::iterator_traits<vec_iterator>::difference_type			difference_type;
	typedef typename ft::choose<is_const, const T, T>::type						value_type;
	typedef typename ft::choose<is_const, const T *, T *>::type		   			pointer;
	typedef typename ft::choose<is_const, const T &, T &>::type		 			reference;
	typedef typename ft::iterator_traits<vec_iterator>::iterator_category		iterator_category;

private:
	pointer		_adr;
public:

	vec_iterator()
	{
		this->_adr = NULL;
	}
	vec_iterator(const pointer ptr)
	{
		this->_adr = ptr;
	}
	~vec_iterator()
	{
	}
	vec_iterator(const vec_iterator &x)
	{
		*this = x;
	}

	template <bool boole>
	vec_iterator(const vec_iterator<T, boole> &x)
	{
		this->_adr = x.base();
	}
	
	vec_iterator &operator=(const reference right)
	{
		this->_adr = right._adr;
		return (*this);
	}
	
	template <bool boole>
	vec_iterator &operator=(const typename vec_iterator<T, boole>::reference right)
	{
		this->_adr = right._adr;
		return (*this);
	}
	
	T &operator[](int n)
	{
		return (this->_adr[n]);
	}
	T const &operator[](int n) const
	{
		return (this->_adr[n]);
	}
	pointer operator->()
	{
		return (this->_adr);
	}
	value_type &operator*()
	{
		return (*(this->_adr));
	}

	//Comparison operators
	template <bool boole>
	bool  operator>(const typename vec_iterator<T, boole>::reference &rhs) const
	{
		if (this->_adr > rhs._adr)
			return (true);
		return (false);
	}
	
	template <bool boole>
	bool  operator<(const typename vec_iterator<T, boole>::reference &rhs) const
	{
		if (this->_adr < rhs._adr)
			return (true);
		return (false);
	}
	
	template <bool boole>
	bool  operator>=(const typename vec_iterator<T, boole>::reference &rhs) const
	{
		if (this->_adr >= rhs._adr)
			return (true);
		return (false);
	}
	
	template <bool boole>
	bool  operator<=(const typename vec_iterator<T, boole>::reference &rhs) const
	{
		if (this->_adr <= rhs._adr)
			return (true);
		return (false);
	}

	template <bool boole>
	bool  operator==(const typename vec_iterator<T, boole>::reference &rhs) const
	{
		if (this->_adr == rhs._adr)
			return (true);
		return (false);
	}

	template <bool boole>
	bool  operator!=(const vec_iterator<T, boole> &rhs) const
	{
		if (this->_adr != rhs.base())
			return (true);
		return (false);
	}

	bool  operator>(const vec_iterator &rhs) const
	{
		if (this->_adr > rhs._adr)
			return (true);
		return (false);
	}

	bool  operator<(const vec_iterator &rhs) const
	{
		if (this->_adr < rhs._adr)
			return (true);
		return (false);
	}
	bool  operator>=(const vec_iterator &rhs) const
	{
		if (this->_adr >= rhs._adr)
			return (true);
		return (false);
	}
	bool  operator<=(const vec_iterator &rhs) const
	{
		if (this->_adr <= rhs._adr)
			return (true);
		return (false);
	}
	bool  operator==(const vec_iterator &rhs) const
	{
		if (this->_adr == rhs._adr)
			return (true);
		return (false);
	}
	bool  operator!=(const vec_iterator &rhs) const
	{
		if (this->_adr != rhs._adr)
			return (true);
		return (false);
	}

	//Arithmetic operators
	difference_type operator-(const vec_iterator &rhs) const
	{
		return (this->_adr - rhs._adr);
	}
	vec_iterator operator+(difference_type val) const
	{
		return (this->_adr + (val));
	}
	vec_iterator operator-(difference_type val) const
	{
		return (this->_adr - (val));
	}
	vec_iterator operator+=(const int val)
	{
		this->_adr = this->_adr + (val);
		return (this->_adr);
	}
	vec_iterator operator-=(const int val)
	{
		this->_adr = this->_adr - (val);
		return (this->_adr);
	}
	//Incrementation/Decrementation operators
	vec_iterator operator++(int)
	{
		vec_iterator temp(*this);
		operator++();
		return (temp);
	}
	vec_iterator operator--(int)
	{
		vec_iterator temp(*this);
		operator--();
		return (temp);
	}
	vec_iterator &operator++(void)
	{
		this->_adr += 1;
		return (*this);
	}
	vec_iterator &operator--(void)
	{
		this->_adr -= 1;
		return (*this);
	}

// protected:
	pointer base() const
	{
		return (this->_adr);
	}
};



// template <class T, bool is_const>
// vec_iterator operator+(difference_type val) const
// {
// 	return (this->_adr + (val));
// }
// Non-member overloads
template <typename T, bool is_const>
typename vec_iterator<T, is_const>::pointer
operator-(typename vec_iterator<T, is_const>::difference_type left, typename vec_iterator<T, is_const>::reference right)
{
	return (right.base() - (left));
}

template <typename T, bool is_const>
vec_iterator<T, is_const> operator+(typename vec_iterator<T, is_const>::difference_type left, vec_iterator<T, is_const> &right)
{
	return (right.base() + (left));
}

template <typename T, bool is_const, bool is_const2>
bool  operator==(const vec_iterator<T, is_const> &lhs, const vec_iterator<T, is_const2> &rhs)
{
	if (lhs.base() == rhs.base())
		return (true);
	return (false);
}

template <typename T, bool is_const, bool is_const2>
bool  operator!=(const vec_iterator<T, is_const> &lhs, const vec_iterator<T, is_const2> &rhs)
{
	if (lhs.base() != rhs.base())
		return (true);
	return (false);
}

template <typename T, bool is_const, bool is_const2>
bool  operator>(const vec_iterator<T, is_const> &lhs, const vec_iterator<T, is_const2> &rhs)
{
	if (lhs.base() > rhs.base())
		return (true);
	return (false);
}

template <typename T, bool is_const, bool is_const2>
bool  operator<(const vec_iterator<T, is_const> &lhs, const vec_iterator<T, is_const2> &rhs)
{
	if (lhs.base() < rhs.base())
		return (true);
	return (false);
}

template <typename T, bool is_const, bool is_const2>
bool  operator>=(const vec_iterator<T, is_const> &lhs, const vec_iterator<T, is_const2> &rhs)
{
	if (lhs.base() >= rhs.base())
		return (true);
	return (false);
}

template <typename T, bool is_const, bool is_const2>
bool  operator<=(const vec_iterator<T, is_const> &lhs, const vec_iterator<T, is_const2> &rhs)
{
	if (lhs.base() <= rhs.base())
		return (true);
	return (false);
}
}
#endif