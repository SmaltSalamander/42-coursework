/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbienias <sbienias@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/05 15:29:40 by sbienias          #+#    #+#             */
/*   Updated: 2022/10/25 10:49:28 by sbienias         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REV_ITERATOR_HPP
# define REV_ITERATOR_HPP
#include <iostream>
#include <cstdlib>
#include "iterator.hpp"
#include "features.hpp"

namespace ft
{
	template<class Iter>
	class reverse_iterator
	{
	protected:
		Iter    current;
	public:
		typedef 			Iter										iterator_type;
		typedef typename 	ft::iterator_traits<Iter>::iterator_category	iterator_category;
		typedef typename 	Iter::value_type								value_type;
		typedef typename 	ft::iterator_traits<Iter>::difference_type		difference_type;
		typedef typename 	ft::iterator_traits<Iter>::pointer				pointer;
		typedef typename 	ft::iterator_traits<Iter>::reference			reference;

		reverse_iterator() : current(0) { }
		reverse_iterator(Iter itr)
        {
            current = itr;
        }
        reverse_iterator(const reverse_iterator &cpy) : current(cpy.base()) {}
		template<class Other>
			reverse_iterator(const reverse_iterator<Other>& other) : current(other.base()) {}
		
		value_type &operator*() const
		{
			Iter	temp(current);
			--temp;
			return (*temp);
		}

		value_type *operator->() const
		{
			return &(operator*());
		}

		reference operator[](difference_type n) const
		{
			return (this->base()[-n - 1]);
		}

		reverse_iterator &operator=(Iter right)
		{
			this->current = right;
			return (*this);
		}

        reverse_iterator &operator=(reverse_iterator right)
		{
			this->current = right.base();
			return (*this);
		}
        
		reverse_iterator& operator++()
		{
			--current;
			return (*this);
		}
		reverse_iterator operator++(int)
		{
			reverse_iterator temp(current);
			operator++();
			return (temp);
		}
		reverse_iterator& operator--()
		{
			++current;
			return (*this);
		}
		reverse_iterator operator--(int)
		{
			reverse_iterator temp(*this);
			operator--();
			return (temp);
		}
		
		difference_type operator-(const Iter &rhs) const
		{
			return (this->current - rhs);
		}
		difference_type operator-(const reverse_iterator &rhs) const
		{
			return (rhs.base() - this->current);
		}
		reverse_iterator operator+(difference_type val) const
		{
			return reverse_iterator(current - val);
		}
		reverse_iterator operator-(difference_type val) const
		{
			return reverse_iterator(current + val);
		}
		reverse_iterator operator+=(difference_type val)
		{
			current -= val;
			return (*this);
		}
		reverse_iterator operator-=(difference_type val)
		{
			current += val;
			return (*this);
		}
		Iter base() const
		{
			return (current);
		}
	};

	template <typename Iter, typename Iter2>
	bool  operator==(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		if (lhs.base() == rhs.base())
			return (true);
		return (false);
	}

	template <typename Iter, typename Iter2>
	bool  operator!=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		if (lhs.base() != rhs.base())
			return (true);
		return (false);
	}

	template <typename Iter, typename Iter2>
	bool  operator>(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		if (lhs.base() < rhs.base())
			return (true);
		return (false);
	}

	template <typename Iter, typename Iter2>
	bool  operator<(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return (rhs > lhs);
	}

	template <typename Iter, typename Iter2>
	bool  operator>=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return !(rhs > lhs);
	}

	template <typename Iter, typename Iter2>
	bool  operator<=(const reverse_iterator<Iter> &lhs, const reverse_iterator<Iter2> &rhs)
	{
		return !(lhs > rhs);
	}

    template <typename Iter>
    reverse_iterator<Iter> operator-(typename reverse_iterator<Iter>::difference_type left, reverse_iterator<Iter> right)
    {
        return (right - (left));
    }

    template <typename Iter>
    reverse_iterator<Iter> operator+(typename reverse_iterator<Iter>::difference_type left, reverse_iterator<Iter> right)
    {
        return (right + (left));
    }
}
#endif