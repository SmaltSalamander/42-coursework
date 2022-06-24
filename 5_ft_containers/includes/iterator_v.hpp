/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_v.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/22 11:09:05 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/23 13:32:27 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_V_HPP
# define ITERATOR_V_HPP
#include <iostream>
#include <cstdlib>

namespace ft
{
// template <class Category,              // iterator::iterator_category
// 		class T,                     // iterator::value_type
// 		class Distance = ptrdiff_t,  // iterator::difference_type
// 		class Pointer = T*,          // iterator::pointer
// 		class Reference = T&         // iterator::reference
// 		>
template <class T>
class iterator
{
private:
	T		*_adr;
public:
    // typedef typename allocator_type::reference       reference;
    // typedef typename allocator_type::const_reference const_reference;

	// typedef typename allocator_type::pointer        pointer;
    // typedef typename allocator_type::const_pointer  const_pointer;

	iterator()
	{
		this->_adr = NULL;
	}
	iterator(T *ptr)
	{
		this->_adr = ptr;
	}
	~iterator()
	{
		
	}
	iterator(const iterator& x)
	{
		*this = x;
	}
	iterator &operator=(iterator const &right)
	{
		this->_adr = right._adr;
		return (*this);
	}
	T &operator[](unsigned int n)
	{
		// if (this->_size <= n)
		// 	throw std::exception();
		return (this->_adr[n]);
	}
	T const &operator[](unsigned int n) const
	{
		// if (this->_size <= n)
		// 	throw std::exception();
		return (this->_adr[n]);
	}
	T const &operator*() const
	{
		return (*(this->_adr));
	}
	//Comparison operators
    bool  operator>(const iterator &rhs) const
	{
		if (this->_adr > rhs._adr)
			return (true);
		return (false);
	}
    bool  operator<(const iterator &rhs) const
	{
		if (this->_adr < rhs._adr)
			return (true);
		return (false);
	}
    bool  operator>=(const iterator &rhs) const
	{
		if (this->_adr >= rhs._adr)
			return (true);
		return (false);
	}
    bool  operator<=(const iterator &rhs) const
	{
		if (this->_adr <= rhs._adr)
			return (true);
		return (false);
	}
    bool  operator==(const iterator &rhs) const
	{
		if (this->_adr == rhs._adr)
			return (true);
		return (false);
	}
    bool  operator!=(const iterator &rhs) const
	{
		if (this->_adr != rhs._adr)
			return (true);
		return (false);
	}

    //Arithmetic operators
    iterator operator+(const iterator &rhs) const
	{
		return (this->_adr + rhs._adr);
	}
    iterator operator-(const iterator &rhs) const
	{
		return (this->_adr - rhs._adr);
	}
	iterator operator+(const int val) const
	{
		return (this->_adr + (val * sizeof(*_adr)));
	}
    iterator operator-(const int val) const
	{
		return (this->_adr - (val * sizeof(*_adr)));
	}
    //Incrementation/Decrementation operators
    iterator operator++(int)
	{
		iterator temp(*this);
		operator++();
		return (temp);
	}
    iterator operator--(int)
	{
		iterator temp(*this);
		operator--();
		return (temp);
	}
    iterator &operator++(void)
	{
		this->_adr += 1;
		return (*this);
	}
    iterator &operator--(void)
	{
		this->_adr -= 1;
		return (*this);
	}
};
}
#endif