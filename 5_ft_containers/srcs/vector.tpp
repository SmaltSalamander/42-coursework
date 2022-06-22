/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:01:13 by sbienias          #+#    #+#             */
/*   Updated: 2022/06/21 11:59:41 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "vector.hpp"

// Constructors
vector();
{
    _ptr = NULL;
    _size = 0;
    _alloc = Allocator;
}
explicit vector(const allocator_type&) : const_reference(allocator_type);
   // noexcept(std::is_nothrow_default_constructible<allocator_type>::value);

explicit vector(size_type n)
{
    _size = n;
    _alloc = Allocator;
    _ptr = _alloc.allocate(T * n);
}
template <class InputIterator>
vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type())
{
	_alloc = alloc;
	_ptr = _alloc.allocate(T * std::distance(first, last));
	iterator iter = _ptr.begin();
	while (first != last)
	{
		iter = *first;
		++iter;		
		++first;
	}
}

~vector()
{
	if (_ptr)
		_alloc.deallocate(_ptr, _size);
}
    // vector(size_type n, const value_type& value, const allocator_type& = allocator_type());
    // template <class InputIterator>
    //     vector(InputIterator first, InputIterator last, const allocator_type& = allocator_type());
    // vector(const vector& x);
    // vector(vector&& x)
    //     noexcept(std::is_nothrow_move_constructible<allocator_type>::value);
    // vector(initializer_list<value_type> il);
    // vector(initializer_list<value_type> il, const allocator_type& a);
~vector()
{
    if (_ptr)
        _alloc.deallocate(_ptr, _size);
}
vector& operator=(const vector& x)
{
    
}