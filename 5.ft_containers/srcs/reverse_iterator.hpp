/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 16:51:17 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/14 15:41:45 by seonhjeo         ###   ########.fr       */
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
	reverse_iterator() : current()
	{};

	// init constructor
	reverse_iterator(iterator_type it) : current(it)
	{};

	// copy/typecast constructor
	template < class Iter >
	reverse_iterator(const reverse_iterator<Iter>& it) : current(it.base())
	{};

	// destructor
	virtual ~reverse_iterator()
	{};

	// return a copy of the base iterator
	iterator_type base() const {
		return (current);
	};

	// return bast iterator that casted to <const Iterator>
	operator reverse_iterator< const Iterator >() const {
		return (this->current);
	};


	/* pointer operator overloading */
	reference operator*() const {
		iterator_type temp = current;
		return *(--temp);
	};

	pointer operator->() const {
		return &(operator*());
	};

	reference operator[](difference_type n) const {
		return (current[-n - 1]);
	};


	/* arithmatic operator overloading */
	// member function
	reverse_iterator operator+(difference_type n) {
		return (reverse_iterator(current - n));
	};

	reverse_iterator& operator++() {
		--current;
		return (*this);
	};

	reverse_iterator operator++(int) {
		reverse_iterator tmp(*this);
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

	reverse_iterator operator--(int) {
		reverse_iterator tmp(*this);
		++current;
		return (tmp);
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
  return (reverse_iterator< Iterator >(rev_it.base() - n));
};

template < class Iterator1, class Iterator2 >
typename reverse_iterator< Iterator1 >::difference_type operator-(
	const reverse_iterator< Iterator1 >& lhs,
	const reverse_iterator< Iterator2 >& rhs) {
  return (rhs.base() - lhs.base());
};

	//////////////////////////////
	// Reverse iterator
	//////////////////////////////

	template <class it>
	class rev_map_iterator {
	public:
		// -structors
		rev_map_iterator			(void)												{ _it = it(); }
		rev_map_iterator			(typename it::value_type * ptr)						{ _it = it(ptr); }
		rev_map_iterator			(const it & x)										{ _it = x; --_it; }
		~rev_map_iterator			(void)												{}
		// Conversion
		template <class U>			friend class										rev_map_iterator;
		template <class U>
		rev_map_iterator			(const rev_map_iterator<U> & x)						{ _it = x.getIt(); }

		// Assignment
		rev_map_iterator &			operator=	(const rev_map_iterator & x)			{ _it = x.getIt(); return (*this); }
		rev_map_iterator &			operator+=	(int n)									{ _it -= n; return (*this); }
		rev_map_iterator &			operator-=	(int n)									{ _it += n; return (*this); }
		// Comparison
		template <class U> bool		operator==	(const rev_map_iterator<U> & x) const	{ return (_it == x.getIt()); }
		template <class U> bool		operator!=	(const rev_map_iterator<U> & x) const	{ return (_it != x.getIt()); }
		template <class U> bool		operator<	(const rev_map_iterator<U> & x) const	{ return (_it > x.getIt()); }
		template <class U> bool		operator>	(const rev_map_iterator<U> & x) const	{ return (_it < x.getIt()); }
		template <class U> bool		operator<=	(const rev_map_iterator<U> & x) const	{ return (_it >= x.getIt()); }
		template <class U> bool		operator>=	(const rev_map_iterator<U> & x) const	{ return (_it <= x.getIt()); }
		// -crementation
		rev_map_iterator &			operator++	(void)									{ --_it; return (*this); }
		rev_map_iterator &			operator--	(void)									{ ++_it; return (*this); }
		rev_map_iterator			operator++	(int)									{ rev_map_iterator<it> x(*this); --_it; return (x); }
		rev_map_iterator			operator--	(int)									{ rev_map_iterator<it> x(*this); ++_it; return (x); }
		// Operation
		rev_map_iterator			operator+	(int n) const							{ return (_it - n + 1); }
		rev_map_iterator			operator-	(int n) const							{ return (_it + n + 1); }
		std::ptrdiff_t				operator-	(const rev_map_iterator & x) const		{ return (x.getIt() - _it); }
		// Dereference
		typename it::value_type &	operator[]	(size_t n) const						{ return (*(_it - n)); }
		typename it::value_type &	operator*	(void) const							{ return (*_it); }
		typename it::value_type *	operator->	(void) const							{ return (&(*_it)); }
		// Member functions
		it							base		(void)									{ return (++it(_it)); }
		it							getIt		(void) const							{ return (_it); }
		// Non-member functions
		friend rev_map_iterator		operator+	(int n, const rev_map_iterator & x)		{ return (x.getIt() - n + 1); }

	private:
		it		_it;
	};
} // namespace ft

#endif
