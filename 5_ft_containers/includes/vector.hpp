/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:30:01 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/24 16:32:48 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP
#include <iostream>
#include <cstdlib>
#include "iterator_v.hpp"
#include "features.hpp"
#include <typeinfo> // typeid for iter cat identification

namespace ft
{
template <typename T, class Allocator = std::allocator<T> >
class vector
{
public:
	typedef T										value_type;
	typedef Allocator								allocator_type;
	typedef typename allocator_type::reference	   	reference;
	typedef typename allocator_type::const_reference const_reference;

	typedef typename allocator_type::pointer		pointer;
	typedef typename allocator_type::const_pointer  const_pointer;

	typedef vec_iterator<T, false>						iterator;
	typedef vec_iterator<T, true>						const_iterator;
	typedef ft::reverse_iterator<iterator>				reverse_iterator;
	typedef ft::reverse_iterator<const_iterator>		const_reverse_iterator;

	typedef typename allocator_type::difference_type difference_type;
	typedef typename allocator_type::size_type	   size_type;
private:
	pointer			_start;
	size_type		_size;
	size_type		_capacity;
	allocator_type	_alloc;
	pointer			_end;
	value_type	  	_val;   
	
public:
//CONSTRUCTORS
	// vector(const allocator_type& alloc);
	vector();
	explicit vector(const allocator_type& allocator_type);

	explicit vector (size_type n, const value_type& val = value_type(),
			const allocator_type& alloc = allocator_type());

	template <class InputIterator>
			vector (InputIterator first, InputIterator last,
					const allocator_type& alloc = allocator_type(),
					typename ft::enable_if<!ft::is_integral<InputIterator>::value>::type* = 0);

	vector (const vector& x);

//DESTRUCTOR

	~vector(void);

//ASSIGNMENT OPERATOR

	vector& operator=(const vector& x);

//ITERATORS
	iterator begin();
	const_iterator begin() const;
	reverse_iterator rbegin();
	const_reverse_iterator rbegin() const;
	iterator end();
	const_iterator end() const;
	reverse_iterator rend();
	const_reverse_iterator rend() const;

//CAPACITY
	size_type size() const;
	size_type max_size() const;
	size_type capacity() const;
	bool empty() const;
	void reserve (size_type n);
	void resize (size_type n, value_type val = value_type());

//ELEMENT ACCESS
	reference operator[] (size_type n);
	const_reference operator[] (size_type n) const;
	reference at (size_type n);
	const_reference at (size_type n) const;
	reference front();
	const_reference front() const;
	reference back();
	const_reference back() const;

//MODIFIERS
template <class InputIterator>
	void		assign (InputIterator first, InputIterator last, typename 
	ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0);
	void		assign (size_type n, const value_type& val);
	void		push_back(const value_type &x);
	void		pop_back();
	void		swap (vector& x);
	iterator 	erase (iterator position);
	iterator 	erase (iterator first, iterator last);
	iterator	insert (iterator position, const value_type& val);
	void		insert (iterator position, size_type n, const value_type& val);
template <class InputIterator>
	void		insert (iterator position, InputIterator first, InputIterator last, 
				typename ft::enable_if<!ft::is_integral<InputIterator>::value >::type* = 0);
	void		clear();

	// HELPER FUNCTIONS
	private:
		void reserve (size_type n, bool flag);
		void resize (size_type n, bool flag);
		void internal_resize (size_type n, value_type val = value_type());
	template <class InputIterator>
		void resize(size_type n, InputIterator first, InputIterator last);

};

	template<class T, class Alloc>
	bool operator==( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

	template<class T, class Alloc>
	bool operator!=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

	template<class T, class Alloc>
	bool operator<( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

	template<class T, class Alloc>
	bool operator<=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

	template<class T, class Alloc>
	bool operator>( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

	template<class T, class Alloc>
	bool operator>=( const ft::vector<T,Alloc>& lhs, const ft::vector<T,Alloc>& rhs);

	template <class T, class Alloc> void swap (ft::vector<T, Alloc>& lhs, ft::vector<T, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}

#include "vector.tpp"
#endif