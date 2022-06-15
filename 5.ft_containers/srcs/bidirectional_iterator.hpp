/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bidirectional_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 16:55:58 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/09 16:11:58 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_BIDIRECTIONAL_ITERATOR_HPP
# define FT_BIDIRECTIONAL_ITERATOR_HPP

# include "traits.hpp"
# include "utility.hpp"

namespace ft
{

template < class T >
class bidirectional_iterator : public ft::iterator< ft::bidirectional_iterator_tag, T >
{
public:
	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::iterator_category	iterator_category;
	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::value_type			value_type;
	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::difference_type		difference_type;
	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::pointer				pointer;
	typedef typename ft::iterator< ft::bidirectional_iterator_tag, T >::reference			reference;

protected:
	pointer	_ptr;

public:
	/* constructor, copy, destructor */
	bidirectional_iterator(pointer _ptr = ft::u_nullptr) : _ptr(_ptr)
	{};

	bidirectional_iterator(const bidirectional_iterator& other) : _ptr(other.base())
	{};

	template < typename diffT >
	bidirectional_iterator(const bidirectional_iterator< diffT >& other) : _ptr(other.base())
	{};

	bidirectional_iterator &operator=(const bidirectional_iterator& other) {
		this->_ptr = other.base();
		return (*this);
	}

	virtual ~bidirectional_iterator()
	{};

	operator bidirectional_iterator< const T >() const {
		return (this->_ptr);
	}

	/* arithmatic operator overloading */
	bidirectional_iterator& operator++() {
		++_ptr;
		return (*this);
	};

	bidirectional_iterator operator++(int) {
		bidirectional_iterator tmp = *this;
		++(*this);
		return (tmp);
	};

	bool operator==(const bidirectional_iterator< T >& other) {
		return (this->_ptr == other._ptr);
	};

	bool operator!=(const bidirectional_iterator< T >& other) {
		return (this->_ptr != other._ptr);
	};

	reference operator*() const {
		return (*_ptr);
	};

	pointer operator->() const {
		return &(operator*());
	};

	bidirectional_iterator& operator--() {
		--_ptr;
		return (*this);
	};

	bidirectional_iterator operator--(int) {
		bidirectional_iterator tmp = *this;
		--(*this);
		return (tmp);
	};

	pointer const& base() const {
		return (_ptr);
	};
};

}

#endif
