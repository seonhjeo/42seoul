/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:31:45 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/14 15:31:10 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILITY_HPP
# define UTILITY_HPP

# include "traits.hpp"

namespace ft
{

/* definition of nullptr */
struct nullptr_t
{
private:
	void operator&() const;

public:
	template < class T >
	inline operator T*() const {
		return (0);
	}

	template < class C, class T >
	inline operator T C::*() const {
		return (0);
	}
};

static nullptr_t u_nullptr = {};

/* difference */
// find gap of first iterator and last iterator
template < class InputIterator >
typename ft::iterator_traits< InputIterator >::difference_type difference(InputIterator first, InputIterator last)
{
	typedef typename ft::iterator_traits< InputIterator >::difference_type size_type;
	size_type n = 0;
	for (; first != last; ++first) {
		++n;
	}
	return (n);
}


/* less */
// Binary function object class whose call returns whether the its first argument compares less than the second
// (as returned by operator <).
template <class Arg1, class Arg2, class Result>
struct binary_function
{
	typedef Arg1 first_argument_type;
	typedef Arg2 second_argument_type;
	typedef Result result_type;
};

template <class T>
struct less : binary_function<T, T, bool>
{
	bool operator() (const T& x, const T& y) const {
		return (x < y);
	}
};


/* pair */
// std::pair is a class template that provides a way to store two heterogeneous objects as a single unit.
// A pair is a specific case of a std::tuple with two elements.
// If neither T1 nor T2 is a possibly cv-qualified class type with non-trivial destructor,
// or array thereof, the destructor of pair is trivial.
template < class T1, class T2 >
struct pair
{
public:
	typedef T1 first_type;
	typedef T2 second_type;

	first_type first;
	second_type second;

	pair() : first(), second(){};

	template < class U, class V >
	pair(const pair< U, V >& pr) : first(pr.first), second(pr.second)
	{};

	pair(const first_type& a, const second_type& b) : first(a), second(b)
	{};

	pair& operator=(const pair& pr) {
		first = pr.first;
		second = pr.second;
		return (*this);
	};
};

template < class T1, class T2 >
bool operator==(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return (lhs.first == rhs.first && lhs.second == rhs.second);
}

template < class T1, class T2 >
bool operator!=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return !(lhs == rhs);
}

template < class T1, class T2 >
bool operator<(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
}

template < class T1, class T2 >
bool operator<=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
	return !(rhs < lhs);
}

template < class T1, class T2 >
bool operator>(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
  return (rhs < lhs);
}

template < class T1, class T2 >
bool operator>=(const pair< T1, T2 >& lhs, const pair< T1, T2 >& rhs) {
  return !(lhs < rhs);
}

/* make_pair */
// Creates a std::pair object, deducing the target type from the types of arguments.
template < class T1, class T2 >
pair< T1, T2 > make_pair(T1 x, T2 y) {
	return (pair< T1, T2 >(x, y));
}

/* swap for specialization */
template < class T >
void swap(T& a, T& b) {
	T c(a);
	a = b;
	b = c;
}

/* equal */
// Returns true if the range [first1, last1) is equal to the range [first2, first2 + (last1 - first1)), and false otherwise
// The overloads use operator== to determine if two elements are equal
template < class InputIt1, class InputIt2 >
bool equal(InputIt1 first1, InputIt1 last1, InputIt2 first2) {
	for (; first1 != last1; ++first1, (void)++first2) {
		if (!(*first1 == *first2))
			return (false);
	}
	return true;
};

// overloads use the given binary predicate p
template < class InputIterator1, class InputIterator2, class BinaryPredicate >
bool equal(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2, BinaryPredicate pred) {
	for (; first1 != last1; ++first1, (void)++first2) {
		if (!bool(pred(*first1, *first2)))
			return (false);
	}
	return true;
}

/* lexicographical_compare */
// Checks if the first range [first1, last1) is lexicographically less than the second range [first2, last2).
// Elements are compared using operator<.
template < class InputIterator1, class InputIterator2 >
bool lexicographical_compare(InputIterator1 first1,
	InputIterator1 last1, InputIterator2 first2, InputIterator2 last2) {
	while (first1 != last1) {
		if (first2 == last2 || *first2 < *first1)
			return false;
		else if (*first1 < *first2)
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
};

// Elements are compared using the given binary comparison function comp.
template < class InputIterator1, class InputIterator2, class Compare >
bool lexicographical_compare(InputIterator1 first1, InputIterator1 last1,
	InputIterator2 first2, InputIterator2 last2, Compare comp) {
	while (first1 != last1) {
		if (first2 == last2 || comp(*first2, *first1))
			return false;
		else if (comp(*first1, *first2))
			return true;
		++first1;
		++first2;
	}
	return (first2 != last2);
};

}

#endif
