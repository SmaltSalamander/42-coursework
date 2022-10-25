/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:28:53 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 22:01:56 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef map_TPP
# define map_TPP
#include "map.hpp"

namespace ft
{
// Constructors
template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map (const key_compare& comp, const allocator_type& alloc)
{
	_comp = comp;
	_alloc = alloc;
	_size = 0;
	_root = NULL;
	_end = _alloc.allocate(1);
	_alloc.construct(_end, _node());
	_begin = _end;
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
map<Key, T, Compare, Alloc>::map (InputIterator first, InputIterator last,
	const key_compare& comp, const allocator_type& alloc)
{
	_comp = comp;
	_alloc = alloc;
	_size = 0;
	_root = NULL;
	_end = _alloc.allocate(1);
	_alloc.construct(_end, _node());
	while (first != last)
	{
		this->insert(*first);
		++first;
	}
}

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::map (const map& x)
{
	this->_root = NULL;
	*this = x;
}

// Assignment Operator

template <class Key, class T, class Compare, class Alloc>
ft::map<Key, T, Compare, Alloc>& map<Key, T, Compare, Alloc>::operator=(const map& x)
{
	if (this->_root)
		this->clear_tree(_root);
	this->_root = NULL;
	this->_alloc = x._alloc;
	_end = _alloc.allocate(1);
	_alloc.construct(_end, _node());
	this->insert(x.begin(), x.end());
	this->_size = x._size;
	this->_comp = x._comp;
	return (*this);
}

//Destructors

template <class Key, class T, class Compare, class Alloc>
map<Key, T, Compare, Alloc>::~map()
{
	if (this->_root)
		clear_tree(this->_root);
}

// Iterators

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator 
map<Key, T, Compare, Alloc>::begin()
{
	return (iterator(this->_begin));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::begin() const
{
	return (const_iterator(iterator(this->_begin)));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator 
map<Key, T, Compare, Alloc>::end()
{
	return (iterator(this->_end));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::end() const
{
	return (const_iterator(this->_end));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator 
map<Key, T, Compare, Alloc>::rbegin()
{
	return (reverse_iterator(this->_end));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator 
map<Key, T, Compare, Alloc>::rbegin() const
{
	return (const_reverse_iterator(this->_end));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::reverse_iterator 
map<Key, T, Compare, Alloc>::rend()
{
	return (reverse_iterator(this->_begin));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_reverse_iterator 
map<Key, T, Compare, Alloc>::rend() const
{
	return (const_reverse_iterator(this->_begin));
}
// Capacity

template <class Key, class T, class Compare, class Alloc>
bool map<Key, T, Compare, Alloc>::empty() const
{
	if (this->_size == 0)
		return (true);
	return (false);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::size() const
{
	return (this->_size);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type
map<Key, T, Compare, Alloc>::max_size() const
{
	return (this->_alloc.max_size());
}

// Element access

template <class Key, class T, class Compare, class Alloc>
T& map<Key, T, Compare, Alloc>::operator[](const key_type& k)
{
	return ((*((this->insert(ft::make_pair(k, mapped_type()))).first)).second);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::mapped_type&
map<Key, T, Compare, Alloc>::at(const key_type& k)
{
	_node	*node = find_node(k);

	if (!node)
		throw (std::out_of_range("Value not found in the map container"));
	return (node->values->second);
}

template <class Key, class T, class Compare, class Alloc>
const typename map<Key, T, Compare, Alloc>::mapped_type&
map<Key, T, Compare, Alloc>::at(const key_type& k) const
{
	_node	*node = find_node(k);

	if (!node)
		throw (std::out_of_range("Value not found in the map container"));
	return (node->values->second);
}

// Modifiers

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator,bool>
map<Key, T, Compare, Alloc>::insert(const value_type& val)
{
	_node		*cpy;
	_node		*prev;
	
	if (!this->_root)
	{
		this->_root = _alloc.allocate(1);
		_alloc.construct(this->_root, _node(val, NULL, NULL, this->_end));
		this->_end->parent = this->_root;
		this->_begin = this->_root;
		this->_size++;
		return (ft::pair<iterator, bool>(iterator(_root), true));
	}
	cpy = this->_root;
	while (cpy && cpy != this->_end)
	{
		prev = cpy;
		if (cpy->values->first == val.first)
			return (ft::pair<iterator, bool>(iterator(cpy), false));
		if (_comp(cpy->values->first, val.first))
			cpy = cpy->right;
		else
			cpy = cpy->left;
	}
	cpy = _alloc.allocate(1);
	_alloc.construct(cpy, _node(val));
	if (_comp(cpy->values->first, prev->values->first))
	{
		prev->left = cpy;
		if (_comp(cpy->values->first, this->_begin->values->first))
			this->_begin = cpy;
	}
	else
	{
		if (prev->right == this->_end)
		{
			this->_end->parent = cpy;
			cpy->right = this->_end;
		}
		prev->right = cpy;
	}
	cpy->parent = prev;
	this->_size++;
	return (ft::pair<iterator, bool>(iterator(cpy), true));
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator
map<Key, T, Compare, Alloc>::insert(iterator position, const value_type& val)
{
	_node	*cpy;
	_node	*newval;

	cpy = find_node(val.first);
	if (cpy != this->_end && cpy != NULL)
		return (iterator(cpy));
	cpy = find_node(position->first);
	if (!(this->_comp(position->first, val.first)) || !cpy)
		return ((this->insert(val)).first);
	while (this->_comp(position->first, val.first) && iterator(this->_end) != position)
	{
		++position;
	}
	cpy = find_node(position->first);
	newval = _alloc.allocate(1);
	_alloc.construct(newval, _node(val));
	if (iterator(this->_end) == position)
	{
		this->_end->parent->right = newval;
		this->_end->parent = newval;
		newval->right = this->_end;
	}
	else if (cpy == this->_end)
	{
		cpy->parent->right = newval;
		this->_end->parent = newval;
		newval->right = this->_end;
	}
	else if (cpy->right == NULL)
	{
		cpy->right = newval;
	}
	else
	{
		cpy = cpy->right;
		while (cpy->left)
			cpy = cpy->left;
		cpy->left = newval;
	}
	newval->parent = cpy;
	this->_size++;
	return (iterator(newval));
}

template <class Key, class T, class Compare, class Alloc>
template <class InputIterator>
void map<Key, T, Compare, Alloc>::insert(InputIterator first, InputIterator last)
{
	while (first != last)
	{
		this->insert(ft::make_pair<Key, T>(first->first, first->second));
		++first;
	}
}

template <class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::erase(iterator position)
{
	this->erase(position->first);
	return ;
	// _node	*pos = this->find_node(position->first);
}

// Refactor it, too clustered QOL!
template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type  
map<Key, T, Compare, Alloc>::erase (const key_type& k)
{
	_node	*pos = this->find_node(k);

	if (pos == NULL || pos == this->_end)
		return (0);
	_node	*parent = pos->parent;
	_node	*addon;
	_node	*iter;
	if (!parent)
	{
		if (pos->left == NULL)
		{
			this->_root = pos->right;
			this->_begin = this->_root;
			while (this->_begin->left)
				this->_begin = this->_begin->left;
		}
		else
		{
			if (pos->right == NULL)
				this->_root = pos->left;
			else
			{
				iter = pos->left;
				while (iter->right != NULL)
					iter = iter->right;
				iter->right = pos->right;
				pos->right->parent = iter;
				this->_root = pos->left;
			}
		}
		this->_root->parent = NULL;
	}
	else if (parent->left == pos)
	{
		if (pos->left == NULL && pos->right == NULL)
		{
			parent->left = NULL;
		}
		else if (pos->right)
		{
			parent->left = pos->right;
			parent->left->parent = parent;
			iter = parent->left;
			while (iter->left)
				iter = iter->left;
			iter->left = pos->left;
			if (pos->left)
				pos->left->parent = iter;
		}
		else
		{
			parent->left = pos->left;
			pos->left->parent = parent;
		}
		if (this->_begin == pos)
			this->_begin = pos->parent;
	}
	else
	{
		addon = pos->right;
		if (pos->left)
		{
			parent->right = pos->left;
			parent->right->parent = parent;
			iter = parent->right;
			while (iter->right)
				iter = iter->right;
			iter->right = addon;
			if (addon)
				addon->parent = iter->right;
		}
		else if (addon)
		{
			parent->right = addon;
			addon->parent = parent;
		}
		else
			parent->right = NULL;
		if (this->_end == pos)
			this->_end = parent;
	}
	this->_size--;
	delete pos;
	return (1);
}
template <class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::erase (iterator first, iterator last)
{
	--last;
	while (last != first)
		this->erase((last--)->first);
	this->erase(first->first);
	return ;
}

template <class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::swap(map& x)
{
	_node			*tempRoot = this->_root;
	size_type		tempsize = this->_size;
	allocator_type	tempalloc = this->_alloc;
	key_compare	  	tempcomp = this->_comp;
	_node			*tempBegin = this->_begin;
	_node			*tempEnd = this->_end;

	this->_root = x._root;
	this->_begin = x._begin;
	this->_end = x._end;
	this->_size = x._size;
	this->_alloc = x._alloc;
	this->_comp = x._comp;

	x._root = tempRoot;
	x._size = tempsize;
	x._alloc = tempalloc;
	x._comp = tempcomp;
	x._begin = tempBegin;
	x._end = tempEnd;
}

template <class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::clear()
{
	this->clear_tree(this->_root);
	this->_root = NULL;
	this->_begin = NULL;
	this->_end = NULL;
	this->_size = 0;	
}

// Observers

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::key_compare
map<Key, T, Compare, Alloc>::key_comp() const
{
	return (this->_comp);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::value_compare
map<Key, T, Compare, Alloc>::value_comp() const
{
	return (value_compare(_comp));
}

// Operations
template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator 
map<Key, T, Compare, Alloc>::find(const key_type& k)
{
	_node	*position = find_node(k);
	if (position)
		return (iterator(position));
	return (this->end());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::find(const key_type& k) const
{
	_node	*position = find_node(k);
	if (position)
		return (const_iterator(position));
	return (this->end());
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::size_type 
map<Key, T, Compare, Alloc>::count(const key_type& k) const
{
	_node	*position = find_node(k);
	if (position != NULL && position != this->_end)
		return (1);
	return (0);
}

//Returns an iterator pointing to the first element in the container whose key is
//not considered to go before k (i.e., either it is equivalent or goes after).
template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator 
map<Key, T, Compare, Alloc>::lower_bound(const key_type& k)
{
	iterator	result(this->_begin);

	while (_comp(result->first, k) && result != this->_end)
		++result;
	return (result);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::lower_bound(const key_type& k) const
{
	const_iterator	result(this->_begin);

	while (_comp(result->first, k) && result != this->_end)
		++result;
	return (result);
}

//Returns an iterator pointing to the first element in the container 
//whose key is considered to go after k.
template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::iterator 
map<Key, T, Compare, Alloc>::upper_bound(const key_type& k)
{
	iterator	result(this->_begin);

	while (_comp(k, result->first) == false && result != this->_end)
		++result;
	return (result);
}

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::const_iterator 
map<Key, T, Compare, Alloc>::upper_bound(const key_type& k) const
{
	const_iterator	result(this->_begin);

	while (_comp(k, result->first) == false && result != this->_end)
		++result;
	return (result);
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::iterator, typename map<Key, T, Compare, Alloc>::iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type& k)
{
	return (ft::pair<iterator, iterator>(this->lower_bound(k), this->upper_bound(k)));
}

template <class Key, class T, class Compare, class Alloc>
ft::pair<typename map<Key, T, Compare, Alloc>::const_iterator, typename map<Key, T, Compare, Alloc>::const_iterator>
map<Key, T, Compare, Alloc>::equal_range(const key_type& k) const
{
	return (ft::pair<const_iterator, const_iterator>(this->lower_bound(k), this->upper_bound(k)));
}

// Allocator

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::allocator_type
map<Key, T, Compare, Alloc>::get_allocator() const
{
	return (this->_alloc);
}

//private

template <class Key, class T, class Compare, class Alloc>
typename map<Key, T, Compare, Alloc>::_node*
map<Key, T, Compare, Alloc>::find_node(const key_type& k) const
{
	_node	*cpy = _root;
	ft::pair<const Key, T>	*vals;

	while (cpy && cpy != this->_end)
	{
		vals = (cpy->values);
		if (_comp(vals->first, k))
			cpy = cpy->right;
		else if (_comp(vals->first, k) == false && _comp(k, vals->first) == false)
			return (cpy);
		else
			cpy = cpy->left;
	}
	return (cpy);
}
template <class Key, class T, class Compare, class Alloc>
void map<Key, T, Compare, Alloc>::clear_tree(_node *node)
{
	if (node == NULL)
		return ;
	clear_tree(node->left);
	clear_tree(node->right);
	_alloc.destroy(node);
	_alloc.deallocate(node, 1);
	node = NULL;
}
}

template<class Key, class T, class Compare, class Alloc>
bool operator==(const ft::map<Key, T, Compare, Alloc>& lhs,
		const ft::map<Key, T, Compare, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (false);
	typename ft::map<Key, T>::const_iterator rhval = rhs.begin();
	for (typename ft::map<Key, T>::const_iterator lhval = lhs.begin(); lhval != lhs.end(); lhval++, rhval++)
	{
		if (*lhval != *rhval)
			return (false);
	}
	return ((rhval == rhs.end()));
}

template<class Key, class T, class Compare, class Alloc>
bool operator!=( const ft::map<Key, T, Compare, Alloc>& lhs,
	const ft::map<Key, T, Compare, Alloc>& rhs)
{
	if (lhs.size() != rhs.size())
		return (true);
	typename ft::map<Key, T>::const_iterator rhval = rhs.begin();
	for (typename ft::map<Key, T>::const_iterator lhval = lhs.begin(); lhval != lhs.end(); lhval++, rhval++)
	{
		if (*lhval != *rhval)
			return (true);
	}
	return (false);
}

template<class Key, class T, class Compare, class Alloc>
bool operator<( const ft::map<Key, T, Compare, Alloc>& lhs, 
const ft::map<Key, T, Compare, Alloc>& rhs)
{
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return (true);
	return (false);
}

template<class Key, class T, class Compare, class Alloc>
bool operator<=( const ft::map<Key, T, Compare, Alloc>& lhs, 
const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return !(rhs < lhs);
}

template<class Key, class T, class Compare, class Alloc>
bool operator>( const ft::map<Key, T, Compare, Alloc>& lhs, 
const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return (rhs < lhs);
}

template<class Key, class T, class Compare, class Alloc>
bool operator>=( const ft::map<Key, T, Compare, Alloc>& lhs, 
const ft::map<Key, T, Compare, Alloc>& rhs)
{
	return !(lhs < rhs);
}

#endif