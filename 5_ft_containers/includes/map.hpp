/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 16:42:05 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 18:32:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
# define MAP_HPP
#include <iostream>
#include <cstdlib>
#include "iterator_m.hpp"
#include "features.hpp"
#include "pair.hpp"
#include <typeinfo> // typeid for iter cat identification

namespace ft
{
template < class Key,									 // map::key_type
		   class T,									   // map::mapped_type
		   class Compare = less<Key>,					 // map::key_compare
		   class Alloc = std::allocator<Nodeft<Key, T> >	// map::allocator_type
		   >
class map
{
public:
	typedef	Key										key_type;
	typedef T										mapped_type;
	typedef ft::pair<const Key, T>					value_type;
	typedef Compare									key_compare;
	typedef Alloc									allocator_type;

	typedef typename allocator_type::reference		reference;
	typedef typename allocator_type::const_reference const_reference;
	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer  const_pointer;

	typedef ft::map_iterator<Key, T, false>			iterator;
	typedef ft::map_iterator<Key, T, true>			const_iterator;
	typedef ft::reverse_iterator<iterator>			reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>	const_reverse_iterator;

	typedef typename allocator_type::difference_type difference_type;
	typedef typename allocator_type::size_type	   		size_type;
	typedef	Nodeft<Key, T>							_node;

private:
	_node			*_root;
	_node			*_begin;
	_node			*_end;
	size_type		_size;
	allocator_type	_alloc;
	key_compare	  	_comp;

	class value_compare : std::binary_function<value_type, value_type, bool>
	{
		friend class map;
		protected:
			key_compare comp;
			value_compare(key_compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			typedef bool result_type;
			typedef value_type first_argument_type;
			typedef value_type second_argument_type;
			bool operator() (const value_type& x, const value_type& y) const
			{
				return comp(x.first, y.first);
			}
	};

public:


// Constructors

explicit map (const key_compare& comp = key_compare(),
              const allocator_type& alloc = allocator_type());

template <class InputIterator>
  map (InputIterator first, InputIterator last,
       const key_compare& comp = key_compare(),
       const allocator_type& alloc = allocator_type());

map (const map& x);

// Destructors

~map();

// Operator =
map& operator=(const map& x);

// Iterators

iterator begin();
const_iterator begin() const;
iterator end();
const_iterator end() const;
reverse_iterator rbegin();
const_reverse_iterator rbegin() const;
reverse_iterator rend();
const_reverse_iterator rend() const;

// Capacity

bool empty() const;
size_type size() const;
size_type max_size() const;

// Element access
T& operator[] (const key_type& k);
mapped_type& at (const key_type& k);
const mapped_type& at (const key_type& k) const;

// Modifiers

pair<iterator,bool> insert(const value_type& val);

iterator insert (iterator position, const value_type& val);

template <class InputIterator>
	void insert (InputIterator first, InputIterator last);

void erase (iterator position);

size_type erase (const key_type& k);

void erase (iterator first, iterator last);

void swap (map& x);

void clear();

// Observers

key_compare key_comp() const;
value_compare value_comp() const;

// Operations

iterator find (const key_type& k);
const_iterator find (const key_type& k) const;
size_type count (const key_type& k) const;
iterator lower_bound (const key_type& k);
const_iterator lower_bound (const key_type& k) const;
iterator upper_bound (const key_type& k);
const_iterator upper_bound (const key_type& k) const;
pair<const_iterator,const_iterator> equal_range (const key_type& k) const;
pair<iterator,iterator> equal_range (const key_type& k);

//Allocator

allocator_type get_allocator() const;

private:
	_node	*find_node(const key_type& k) const;
	void	clear_tree(_node *node);

};

}

template<class Key, class T, class Compare, class Alloc>
bool operator==( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

template<class Key, class T, class Compare, class Alloc>
bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

template<class Key, class T, class Compare, class Alloc>
bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

template<class Key, class T, class Compare, class Alloc>
bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

template<class Key, class T, class Compare, class Alloc>
bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

template<class Key, class T, class Compare, class Alloc>
bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs, const ft::map<Key, T, Compare, Alloc>& rhs);

#include "map.tpp"
#endif