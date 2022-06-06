/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:51:17 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/06 17:58:04 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_REVERSE_ITERATOR_HPP
# define FT_REVERSE_ITERATOR_HPP

# include "traits.hpp"
# include "utility.hpp"

namespace ft
{
/* reverse_iterator */
// std::reverse_iterator is an iterator adaptor that reverses the direction of a given iterator,
// which must be at least a LegacyBidirectionalIterator or model bidirectional_iterator (since C++20).
// In other words, when provided with a bidirectional iterator,
// std::reverse_iterator produces a new iterator that moves
// from the end to the beginning of the sequence defined by the underlying bidirectional iterator.
template < class Iterator >
class reverse_iterator
{
public:
	typedef Iterator iterator_type;
	typedef typename iterator_traits<Iterator>::iterator_category iterator_category;
	typedef typename iterator_traits<Iterator>::value_type value_type;
	typedef typename iterator_traits<Iterator>::difference_type difference_type;
	typedef typename iterator_traits<Iterator>::pointer pointer;
	typedef typename iterator_traits<Iterator>::reference reference;

protected:
	iterator_type current;

public:
	// default constructor
	reverse_iterator() : current() {};

	// init constructor
	reverse_iterator(iterator_type it) : current(it) {};

	// copy/typecast constructor
	template < class Iter >
	reverse_iterator(const reverse_iterator<Iter>& it) : current(it.base()) {};

	// destructor
	virtual ~reverse_iterator() {};

	// copy operator overloading
	reverse_iterator &operator=(const reverse_iterator<Iter> &it)
	{
		this->current = it.base();
		return (*this);
	};

	// return a copy of the base iterator
	iterator_type base() const { return (current); };

	// return bast iterator that casted to <const Iterator>
	operator reverse_iterator< const Iterator >() const {
		return (this->current);
	};


	/* pointer operator overloading */
	reference operator*() const {
		iterator_type temp = this->current;
		return (*(--temp));
	};

	pointer operator->() const { return &(operator*()); };

	reference operator[](difference_type n) const { return (current[-n - 1]); };


	/* arithmatic operator overloading */
	// member function
	reverse_iterator operator+(different_type n) {
		return (reverse_iterator(current - n));
	};

	reverse_iterator& operator++() {
		--current;
		return (*this);
	};

	reverse_iterator operator++(int) {
		reverse_iterator tmp = *this;
		--current;
		return (tmp);
	};

	reverse_iterator& operator+=(difference_type n) {
		current -= n;
		return (*this);
	};

	reverse_iterator operator-(difference_type n) const {
		return (reverse_iterator(current + n));
	}

	reverse_iterator& operator--() {
		++current;
		return (*this);
	}

	reverse_iterator& operator--(int) {
		reverse_iterator tmp = *this;
		++current;
		return (this);
	}

	reverse_iterator operator-=(difference_type n) {
		current += n;
		return (*this);
	}
};

/* arithmatic operator overloading */
// none-member function
template < class Iterator1, class Iterator2 >
bool operator==	(
	const reverse_iterator< Iterator1 >& lhs,
	const reverse_iterator< Iterator2 >& rhs) {
	return (lhs.base() == rhs.base());
};

template < class Iterator1, class Iterator2 >
bool operator!=	(
	const reverse_iterator< Iterator1 >& lhs,
	const reverse_iterator< Iterator2 >& rhs) {
	return (lhs.base() != rhs.base());
};

template < class Iterator1, class Iterator2 >
bool operator<	(
	const reverse_iterator< Iterator1 >& lhs,
	const reverse_iterator< Iterator2 >& rhs) {
	return (lhs.base() > rhs.base());
};

template < class Iterator1, class Iterator2 >
bool operator<=	(
	const reverse_iterator< Iterator1 >& lhs,
	const reverse_iterator< Iterator2 >& rhs) {
	return (lhs.base() >= rhs.base());
};

template < class Iterator1, class Iterator2 >
bool operator>(
	const reverse_iterator< Iterator1 >& lhs,
	const reverse_iterator< Iterator2 >& rhs) {
	return (lhs.base() < rhs.base());
};

template < class Iterator1, class Iterator2 >
bool operator>=(
	const reverse_iterator< Iterator1 >& lhs,
	const reverse_iterator< Iterator2 >& rhs) {
	return (lhs.base() <= rhs.base());
};

template < class Iterator >
reverse_iterator< Iterator > operator+(
	typename reverse_iterator< Iterator >::difference_type n,
	const reverse_iterator< Iterator >& rev_it) {
  return (rev_it + n);
};

template < class Iterator1, class Iterator2 >
typename reverse_iterator< Iterator1 >::difference_type operator-(
	const reverse_iterator< Iterator1 >& lhs,
	const reverse_iterator< Iterator2 >& rhs) {
  return (rhs.base() - lhs.base());
};

}

#endif
