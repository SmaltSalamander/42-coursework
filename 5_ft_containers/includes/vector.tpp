/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:30:16 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 10:49:55 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef vector_TPP
# define vector_TPP
#include "vector.hpp"

namespace ft
{
// Constructors
template <typename T, class Allocator>
vector<T, Allocator>::vector()
{
	_start = _alloc.allocate(0);
	_end = _start;
	_size = 0;
	_capacity = 0;
}

template <typename T, class Allocator>
vector<T, Allocator>::vector(const allocator_type& allocator_type)
{
	_start = _alloc.allocate(0);
	_end = _start;
	_alloc = allocator_type;
	_size = 0;
	_capacity = 0;
}

template <typename T, class Allocator>
vector<T, Allocator>::vector(size_type n, const value_type& val,
			const allocator_type& alloc)
{
	_val = val;
	_alloc = alloc;
	if (n > alloc.max_size())
		throw (std::exception());
	this->_start = _alloc.allocate(n * sizeof(_val));
	this->_end = this->_start;
	while (n)
	{
		this->_alloc.construct(this->_end, _val);
		++this->_end;
		n--;
	}
	this->_size = static_cast<unsigned long>(this->_end - this->_start);
	this->_capacity = this->_size;
}

template <typename T, class Allocator>
template <class InputIterator>
vector<T, Allocator>::vector (InputIterator first, InputIterator last,
		const allocator_type& alloc, 
		typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
	size_type n = ft::distance<InputIterator>(first, last);

	_alloc = alloc;
	if (n > _alloc.max_size())
		throw (std::exception());
	this->_start = _alloc.allocate(n * sizeof(_val));
	this->_end = this->_start;
	while (first != last)
	{
		this->_alloc.construct(this->_end, *first);
		++this->_end;
		++first;
	}
	this->_size = static_cast<unsigned long>(this->_end - this->_start);
	this->_capacity = n * sizeof(_val);
}

template <typename T, class Allocator>
vector<T, Allocator>::vector(const vector& x)
{
	_start = _alloc.allocate(0);
	this->_capacity = 0;
	*this = x;
}

// DESTRUCTOR

template <typename T, class Allocator>
vector<T, Allocator>::~vector(void)
{
	_alloc.deallocate(_start, _size);
}

// ASSIGNMENT OPERATOR

template <typename T, class Allocator>
ft::vector<T, Allocator>& vector<T, Allocator>::operator=(const vector& x)
{
	_alloc = x._alloc;
	_val = x._val;
	this->assign(x.begin(), x.end());
	_capacity = x._capacity;
	return (*this);
}

// ITERATORS

template <typename T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin()
{
	return (iterator (this->_start));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const
{
	return (const_iterator (this->_start));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin()
{
	return (reverse_iterator(iterator(this->_end)));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const
{
	return (const_reverse_iterator(const_iterator(this->_end)));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::iterator	vector<T, Allocator>::end()
{
	return (iterator(this->_end));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const
{
	return (const_iterator(this->_end));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::reverse_iterator	vector<T, Allocator>::rend()
{
	return (reverse_iterator(iterator(this->_start)));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const
{
	return (const_reverse_iterator(const_iterator(this->_start)));
}

// CAPACITY

template <typename T, class Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::size() const
{
	return (this->_size);
}

template <typename T, class Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size() const
{
	return (this->_alloc.max_size());
}

template <typename T, class Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity() const
{
	return (this->_capacity);
}

template <typename T, class Allocator>
bool vector<T, Allocator>::empty() const
{
	if (this->_size == 0)
		return (true);
	return (false);
}

template <typename T, class Allocator>
void vector<T, Allocator>::internal_resize (size_type n, value_type val)
{
	pointer tempVect = _alloc.allocate(n);
	size_type i = 0;
	for (; i < this->_size && i < n; i++)
		_alloc.construct(tempVect + i, _start[i]);
	while (i < n)
		_alloc.construct(tempVect + i++, val);
	this->_alloc.deallocate(_start, this->_capacity);
	this->_capacity = n;
	this->_start = tempVect;
	if (_size > n)
		this->_size = n;
	this->_end = tempVect + _size;	
}

template <typename T, class Allocator>
void vector<T, Allocator>::resize (size_type n, value_type val)
{
	pointer tempVect = _alloc.allocate(n);
	size_type i = 0;
	for (; i < this->_size && i < n; i++)
		_alloc.construct(tempVect + i, _start[i]);
	while (i < n)
		_alloc.construct(tempVect + i++, val);
	this->_alloc.deallocate(_start, this->_capacity);
	this->_capacity = n;
	this->_start = tempVect;
	this->_size = n;
	this->_end = tempVect + _size;	
}

template <typename T, class Allocator>
void vector<T, Allocator>::reserve (size_type n)
{
	size_type	readjust = n;

	if (readjust > _alloc.max_size())
		throw (std::exception());
	if (readjust < this->_capacity)
		return ;
	this->internal_resize(readjust);
}

// Private
template <typename T, class Allocator>
void vector<T, Allocator>::resize (size_type n, bool flag)
{
	if (!flag)
		return ;
	pointer tempVect = _alloc.allocate(n);
	this->_alloc.deallocate(_start, this->_capacity);
	this->_capacity = n;
	this->_start = tempVect;
	if (n < this->_size)
		this->_size = n;
	this->_end = tempVect + _size;
}

template <typename T, class Allocator>
template <class InputIterator>
void vector<T, Allocator>::resize(size_type n, InputIterator first, InputIterator last)
{
	pointer tempVect = _alloc.allocate(n);
	iterator start(tempVect);
	while (first != last)
	{
		this->_alloc.construct(&(*start), *first);
		// *start = *(first);
		++start;
		++first;
	}
	this->_alloc.deallocate(_start, this->_capacity);
	this->_capacity = n;
	this->_start = tempVect;
	this->_end = &(*start);
	this->_size = start - this->_start;
}

template <typename T, class Allocator>
void vector<T, Allocator>::reserve (size_type n, bool flag)
{
	if (n > _alloc.max_size())
		throw (std::exception());
	if (flag)
		this->resize(n, flag);
	else
		this->internal_resize(n);
}
//ELEMENT ACCESS

template <typename T, class Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::operator[] (size_type n)
{
	return (*(this->_start + n));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[] (size_type n) const
{
	return (*(this->_start + n));
}

// std::out_of_range works with no args only in Linux, Mac throws errors
template <typename T, class Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::at (size_type n)
{
	if (n >= this->_size)
	{
		std::string	errmsg;
		errmsg = "vector::_M_range_check: __n (which is " + ft::to_string(n) + ") >= this->size() (which is " + ft::to_string(this->_size) + ")";
		throw (std::out_of_range(errmsg));
	}
	return (*(this->_start + n));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at (size_type n) const
{
	if (n >= this->_size)
		throw (std::out_of_range("vector"));
	return (*(this->_start + n));
}


template <typename T, class Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::front()
{
	return (*(this->_start));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const
{
	return (*(this->_start));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::back()
{
	return (*(this->_end - 1));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const
{
	return (*(this->_end - 1));
}

//MODIFIERS

template <typename T, class Allocator>
template <class InputIterator>
void vector<T, Allocator>::assign (InputIterator first, InputIterator last,
typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
	size_type	size = static_cast<size_type>(ft::distance<InputIterator>(first, last));
	typename ft::iterator_traits<InputIterator>::value_type	temp;

	if (this->_capacity < size)
		this->resize(size, first, last);
	else
	{
		this->_end = this->_start;
		while (first != last)
		{
			temp = *first;
			this->_alloc.construct(this->_end++, temp);
			++first;
		}
		this->_size = size;
	}
	// this->_end = this->_start;
	// while (first != last)
	// {
	// 	this->_alloc.construct(this->_end++, *first);
	// 	++first;
	// }
}

template <typename T, class Allocator>
void vector<T, Allocator>::assign (size_type n, const value_type& val)
{
	pointer copy;
	this->reserve(n, 1);
	copy = this->_start;
	while (n--)
	{
		this->_alloc.construct(copy, val);
		++copy;
	}
	this->_end = copy;
	this->_size = _end - _start;
}
	
template <typename T, class Allocator>
void vector<T, Allocator>::swap (vector& x)
{
	pointer			TempStart = this->_start;
	size_type		TempSize = this->_size;
	size_type		TempCapacity = this->_capacity;
	pointer			TempEnd = this->_end;

	this->_start = x._start;
	this->_size = x._size;
	this->_capacity = x._capacity;
	this->_end = x._end;
	
	x._start = TempStart;
	x._size = TempSize;
	x._capacity = TempCapacity;
	x._end = TempEnd;
}

template <typename T, class Allocator>
void vector<T, Allocator>::push_back(const value_type& x)
{
	this->reserve(this->_size + 1, false);
	this->_alloc.construct(this->_end++, x);
	this->_size++;
}

template <typename T, class Allocator>
void vector<T, Allocator>::pop_back()
{
	this->_alloc.destroy(this->_end--);
	this->_size--;
}

template <typename T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator position)
{
	iterator	copy(position);

	while ((copy + 1) != this->_end)
	{
		*copy = *(copy + 1);
		++copy;
	}
	this->_end = &(*copy);
	difference_type index = position - iterator(this->_start);
	this->assign<iterator>(this->_start, this->_end);
	return (iterator(this->_start + index));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator first, iterator last)
{
	difference_type num = last - first;
	iterator	copy(first);

	while (copy + num !=  this->_end)
	{
		*copy = *(copy + num);
		++copy;
	}
	this->_end = &(*copy);
	num = ft::distance<iterator>(this->_start, last) - num;
	this->assign<iterator>(this->_start, this->_end);
	// copy = last;
	// ++copy;
	// while (first != last)
	// {
	// 	this->_alloc.destroy(&(*first++));
	// }
	return (iterator(this->_start + num));
}

template <typename T, class Allocator>
typename vector<T, Allocator>::iterator	vector<T, Allocator>::insert(iterator position, const value_type& val)
{
	size_type	index = (this->_end - &(*position));
	pointer 	adr;
	value_type	temp;

	this->reserve(this->_size + 1, false);
	adr = this->_end;
	temp = *(adr - 1);
	while (index--)
	{
		*adr = temp;
		--adr;
		temp = *(adr - 1);
	}
	*adr = val;
	this->_size++;
	this->_end++;
	return (iterator(adr));
}

template <typename T, class Allocator>
void	vector<T, Allocator>::insert(iterator position, size_type n, const value_type& val)
{
	size_type	index = (this->_end - &(*position));
	pointer 	adr;
	value_type	temp;

	this->reserve(this->_size + n, false);
	adr = this->_end + n - 1;
	temp = *(adr - n);
	while (index--)
	{
		*adr = temp;
		--adr;
		temp = *(adr - n);
	}
	this->_end = this->_end + n;
	this->_size += n;
	while (n--)
	{
		*adr = val;
		--adr;
	}
}

template <typename T, class Allocator>
template <class InputIterator>
void	vector<T, Allocator>::insert (iterator position, InputIterator first, InputIterator last,
typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type*)
{
	size_type	index = (this->_end - &(*position));
	size_type	length;
	pointer 	adr;
	value_type	temp;

	length = ft::distance(first, last);
	this->reserve(this->_size + length, false);
	adr = this->_end + length - 1;
	temp = *(adr - length);
	while (index--)
	{
		*adr = temp;
		--adr;
		temp = *(adr - length);
	}
	this->_end = this->_end + length;
	this->_size += length;
	while (length--)
	{
		
		*adr = *(--last);
		--adr;
	}
}

template <typename T, class Allocator>
void vector<T, Allocator>::clear(void)
{
	_alloc.deallocate(_start, _size);
	this->_size = 0;
	this->_capacity = 0;
	this->_start = _alloc.allocate(0);
	this->_end = this->_start;
}

template<class T, class Alloc>
bool operator==(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity())
		return (false);
	typename ft::vector<T, Alloc>::const_iterator rhval = rhs.begin();
	for (typename ft::vector<T, Alloc>::const_iterator lhval = lhs.begin(); lhval != lhs.end(); lhval++, rhval++)
	{
		if (*lhval != *rhval)
			return (false);
	}
	return ((rhval == rhs.end()));
}

template<class T, class Alloc>
bool operator!=(const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (lhs.size() != rhs.size() || lhs.capacity() != rhs.capacity())
		return (true);
	typename ft::vector<T, Alloc>::const_iterator rhval = rhs.begin();
	for (typename ft::vector<T, Alloc>::const_iterator lhval = lhs.begin(); lhval != lhs.end(); lhval++, rhval++)
	{
		if (*lhval != *rhval)
			return (true);
	}
	return (false);
}

template<class T, class Alloc>
bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return (true);
	return (false);
}

template<class T, class Alloc>
bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(rhs < lhs);
}

template<class T, class Alloc>
bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return (rhs < lhs);
}

template<class T, class Alloc>
bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs)
{
	return !(lhs < rhs);
}

}
#endif