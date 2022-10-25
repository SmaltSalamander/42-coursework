/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:30:01 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/24 16:39:09 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP
#include "vector.hpp"

namespace ft
{
template <typename T, class Container = ft::vector<T> >
class stack
{
	public:
	typedef T										value_type;
	typedef Container								container_type;
	typedef typename container_type::size_type		size_type;
	
	protected:
	container_type		_cont;

	public:
	explicit stack (const container_type& ctnr = container_type()) : _cont(ctnr) {};
	~stack() {};

	bool empty() const;
	size_type size() const;
    value_type& top();
	const value_type& top() const;
	void push (const value_type& val);
	void pop();

	friend bool operator==( const stack& lhs, const stack& rhs)
	{
		return (lhs._cont == rhs._cont);
	}

	friend bool operator!=( const stack& lhs, const stack& rhs)
	{
		return (lhs._cont != rhs._cont);
	}

	friend bool operator<( const stack& lhs, const stack& rhs)
	{
		return (lhs._cont < rhs._cont);
	}

	friend bool operator<=( const stack& lhs, const stack& rhs)
	{
		return (lhs._cont <= rhs._cont);
	}

	friend bool operator>( const stack& lhs, const stack& rhs)
	{
		return (lhs._cont > rhs._cont);
	}
	
	friend bool operator>=( const stack& lhs, const stack& rhs)
	{
		return (lhs._cont >= rhs._cont);
	}
};
}


#include "stack.tpp"
#endif