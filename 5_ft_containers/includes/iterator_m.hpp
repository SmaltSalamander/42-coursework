/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator_m.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:29:20 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 10:46:58 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef ITERATOR_M_HPP
# define ITERATOR_M_HPP
#include <iostream>
#include <cstdlib>
#include "iterator.hpp"
#include "pair.hpp"
#include "rev_iterator.hpp"

namespace ft
{
template <class T, class Value>
struct node_s
	{
		node_s	*parent;
		node_s	*left;
		node_s	*right;
		ft::pair<const T, Value>   *values;
	};

template <class T, class Value>
class Nodeft
{
public:
	typedef	node_s<T, Value>				_node;
	typedef ft::pair<const T, Value>   		_pair;

	_pair  				*values;
	Nodeft	*parent;
	Nodeft	*left;
	Nodeft	*right;
public:
	Nodeft(T first, Value second) : parent(NULL), left(NULL), right(NULL)
	{
		values = new _pair(first, second);
	}
	Nodeft(_pair vals, Nodeft *par = NULL, Nodeft *lft = NULL, Nodeft *rt = NULL) : parent(par), left(lft), right(rt)
	{
		values = new _pair(vals.first, vals.second);
	}
	Nodeft() : parent(NULL), left(NULL), right(NULL)
	{
		values = new _pair;
	}
	Nodeft(Nodeft const &par) : parent(par.parent), left(par.left), right(par.right)
	{
		values = new _pair;
		*this = par;
	}
	Nodeft &operator=(Nodeft const &right)
	{
		this->parent = right.parent;
		this->left = right.left;
		this->right = right.right;
		delete values;
		values = new _pair(right.values->first, right.values->second);
		return (*this);
	}
	Nodeft &operator=(Nodeft const *right)
	{
		this->parent = right->parent;
		this->left = right->left;
		this->right = right->right;
		delete values;
		values = new ft::pair<const T, Value>(right->values->first, right->values->second);
		return (*this);
	}
	bool operator!=(Nodeft const &right) const
	{
		return (this->values->first != right.values->first);
	}
	bool operator==(Nodeft const &right) const
	{
		return (this->values->first == right.values->first);
	}
	void	addValue(_pair extvalues)
	{
		delete values;
		values = new _pair(extvalues.first, extvalues.second);
	}
	~Nodeft()
	{
		delete values;
	}
};

template <class T, class Value, bool is_const>
class map_iterator : public iterator<ft::bidirectional_iterator_tag, T>
{
public:
	typedef	Nodeft<T, Value>						_node;
	typedef typename ft::iterator_traits<map_iterator>::difference_type			difference_type;
	typedef typename ft::choose<is_const, const ft::pair<const T, Value>, ft::pair<const T, Value> >::type		value_type;
	typedef typename ft::choose<is_const, const _node *, _node *>::type		   	pointer;
	typedef typename ft::choose<is_const, const _node &, _node &>::type		 	reference;
	typedef typename ft::iterator_traits<map_iterator>::iterator_category		iterator_category;
private:
	pointer		_adr;
public:

	map_iterator()
	{

	}
	map_iterator(const reference ptr)
	{
		this->_adr = &ptr;
	}
	map_iterator(const pointer ptr)
	{
		this->_adr = ptr;
	}
	~map_iterator()
	{
	}
	map_iterator(const map_iterator& x)
	{
		*this = x;
	}
	template <bool boole>
	map_iterator(const map_iterator<T, Value, boole> &x)
	{
		this->_adr = x.base();
	}
	map_iterator &operator=(const reference right)
	{
		this->_adr = right._adr;
		return (*this);
	}

	template <bool boole>
	map_iterator &operator=(const typename map_iterator<T, Value, boole>::reference x)
	{
		this->_adr = x._adr;
		return (*this);
	}
	value_type &operator*() const
	{
		return *(_adr->values);
	}
	value_type *operator->() const
	{
		return (_adr->values);
	}

	//Comparison operators
	bool  operator>(const map_iterator &rhs) const
	{
		if (this->_adr->values.first > rhs._adr->values.first)
			return (true);
		return (false);
	}
	bool  operator<(const map_iterator &rhs) const
	{
		if (this->_adr < rhs._adr)
			return (true);
		return (false);
	}
	bool  operator>=(const map_iterator &rhs) const
	{
		if (this->_adr >= rhs._adr)
			return (true);
		return (false);
	}
	bool  operator<=(const map_iterator &rhs) const
	{
		if (this->_adr <= rhs._adr)
			return (true);
		return (false);
	}
	bool  operator==(const map_iterator &rhs) const
	{
		if (this->_adr == rhs._adr)
			return (true);
		return (false);
	}
	bool  operator!=(const map_iterator &rhs) const
	{
		return (this->_adr != rhs._adr);
	}

	//Incrementation/Decrementation operators
	map_iterator operator++(int)
	{
		map_iterator temp(*this);
		operator++();
		return (temp);
	}
	map_iterator operator--(int)
	{
		map_iterator temp(*this);
		operator--();
		return (temp);
	}
	map_iterator &operator++(void)
	{
		pointer parent;

		if (this->_adr->right)
		{
			this->_adr = this->_adr->right;
			while (this->_adr->left)
				this->_adr = this->_adr->left;
		}
		else if (this->_adr->parent && this->_adr->parent->right != this->_adr)
		{
			this->_adr = this->_adr->parent;
		}
		else if (this->_adr->parent)
		{
			parent = this->_adr->parent;
			while (parent && parent->right == this->_adr)
			{
				this->_adr = parent;
				parent = parent->parent;
			}
			this->_adr = parent;
		}
		else
			this->_adr = this->_adr->right;
		return (*this);
	}

	map_iterator &operator--(void)
	{
		pointer parent;

		if (this->_adr->left)
		{
			this->_adr = this->_adr->left;
			while (this->_adr->right)
				this->_adr = this->_adr->right;
		}
		else if (this->_adr->parent && this->_adr->parent->left != this->_adr)
		{
			this->_adr = this->_adr->parent;
		}
		else if (this->_adr->parent)
		{
			parent = this->_adr->parent;
			while (parent && parent->left == this->_adr)
			{
				this->_adr = parent;
				parent = parent->parent;
			}
			this->_adr = parent;
		}
		else
			this->_adr = this->_adr->left;
		return (*this);
	}

	pointer base() const
	{
		return (this->_adr);
	}
};

// Non-member overloads

template <typename T, typename Value, bool is_const, bool is_const2>
bool  operator==(const map_iterator<T, Value, is_const> &lhs, const map_iterator<T, Value, is_const2> &rhs)
{
	if (lhs.base() == rhs.base())
		return (true);
	return (false);
}

template <typename T, typename Value, bool is_const, bool is_const2>
bool  operator!=(const map_iterator<T, Value, is_const> &lhs, const map_iterator<T, Value, is_const2> &rhs)
{
	if (lhs.base() != rhs.base())
		return (true);
	return (false);
}

template <typename T, typename Value, bool is_const, bool is_const2>
bool  operator>(const map_iterator<T, Value, is_const> &lhs, const map_iterator<T, Value, is_const2> &rhs)
{
	if (lhs.base() > rhs.base())
		return (true);
	return (false);
}

template <typename T, typename Value, bool is_const, bool is_const2>
bool  operator<(const map_iterator<T, Value, is_const> &lhs, const map_iterator<T, Value, is_const2> &rhs)
{
	if (lhs.base() < rhs.base())
		return (true);
	return (false);
}

template <typename T, typename Value, bool is_const, bool is_const2>
bool  operator>=(const map_iterator<T, Value, is_const> &lhs, const map_iterator<T, Value, is_const2> &rhs)
{
	if (lhs.base() >= rhs.base())
		return (true);
	return (false);
}

template <typename T, typename Value, bool is_const, bool is_const2>
bool  operator<=(const map_iterator<T, Value, is_const> &lhs, const map_iterator<T, Value, is_const2> &rhs)
{
	if (lhs.base() <= rhs.base())
		return (true);
	return (false);
}
}
#endif