/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:47:14 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/07 17:33:47 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RANDOM_ACCESS_ITERATOR_HPP
# define RANDOM_ACCESS_ITERATOR_HPP

# include "traits.hpp"
# include "utility.hpp"

namespace ft
{

template < class T >
class random_access_iterator : public ft::iterator< ft::random_access_iterator_tag, T >
{
public:
	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::iterator_category	iterator_category;
	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::value_type			value_type;
	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::difference_type		difference_type;
	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::pointer				pointer;
 	typedef typename ft::iterator< ft::random_access_iterator_tag, T >::reference			reference;

protected:
	pointer _ptr;

public:
	/* constructor, copy, destructor */
	random_access_iterator(pointer _ptr = ft::u_nullptr) : _ptr(_ptr)
	{};

	random_access_iterator(const random_access_iterator< T >& other) : _ptr(other._ptr)
	{};

	template < typename diffT >
	random_access_iterator(const random_access_iterator< diffT >& other) : _ptr(other.base())
	{};

	random_access_iterator &operator=(const random_access_iterator& other) {
		this->_ptr = other.base();
		return (*this);
	}

	virtual ~random_access_iterator()
	{};

	// return bast iterator that casted to <const Iterator>
	operator random_access_iterator< const T >() const {
		return (this->_ptr);
	}

	/* pointer operator overloading */
	reference operator*() const {
		return (*_ptr);
	};

	pointer operator->() const {
		return &(operator*());
	};

	/* arithmatic operator overloading */
	random_access_iterator& operator++() {
		++_ptr;
		return (*this);
	};

	random_access_iterator operator++(int) {
		random_access_iterator tmp = *this;
		++(*this);
		return (tmp);
	};

	random_access_iterator& operator--() {
		--_ptr;
		return (*this);
	};

	random_access_iterator operator--(int) {
		random_access_iterator tmp = *this;
		--(*this);
		return (tmp);
	};

	random_access_iterator operator+(difference_type n) const {
		return random_access_iterator(this->_ptr + n);
	};

	random_access_iterator& operator+=(difference_type n) {
		this->_ptr += n;
		return (*this);
	};

	random_access_iterator operator-(difference_type n) const {
		return random_access_iterator(this->_ptr - n);
	}

	random_access_iterator& operator-=(difference_type n) {
		this->_ptr -= n;
		return (*this);
	};

	reference operator[](difference_type n) const {
		return (this->_ptr[n]);
	};

	pointer const& base() const {
		return (this->_ptr);
	}
};

template < class T1, class T2 >
bool operator==(const random_access_iterator< T1 >& lhs,
	const random_access_iterator< T2 >& rhs) {
	return (lhs.base() == rhs.base());
};

template < class T1, class T2 >
bool operator!=(const random_access_iterator< T1 >& lhs,
	const random_access_iterator< T2 >& rhs) {
	return (lhs.base() != rhs.base());
};

template < class T1, class T2 >
bool operator<(const random_access_iterator< T1 > lhs,
	const random_access_iterator< T2 >& rhs) {
	return (lhs.base() < rhs.base());
};

template < class T1, class T2 >
bool operator<=(const random_access_iterator< T1 >& lhs,
	const random_access_iterator< T2 >& rhs) {
	return (lhs.base() <= rhs.base());
};

template < class T1, class T2 >
bool operator>(const random_access_iterator< T1 > lhs,
	const random_access_iterator< T2 >& rhs) {
	return (lhs.base() > rhs.base());
};

template < class T1, class T2 >
bool operator>=(const random_access_iterator< T1 >& lhs,
	const random_access_iterator< T2 >& rhs) {
	return (lhs.base() >= rhs.base());
};

template < class Iterator >
random_access_iterator< Iterator > operator+(
		typename random_access_iterator< Iterator >::difference_type n,
		const random_access_iterator< Iterator >& iter) {
	return iter + n;
};

template < class T1, class T2 >
typename random_access_iterator< T1 >::difference_type operator-(
		const random_access_iterator< T2 >& lhs,
		const random_access_iterator< T1 >& rhs) {
	return lhs.base() - rhs.base();
};

}

#endif
