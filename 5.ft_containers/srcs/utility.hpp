/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 17:31:45 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/06 17:55:25 by seonhjeo         ###   ########.fr       */
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
typename ft::iterator_traits< InputIterator >::difference_type difference
	(InputIterator first, InputIterator last)
{
	typedef typename ft::iterator_traits< InputIterator >::difference_type size_type;
	size_type n = 0;
	for (; first != last; ++first) {
		++n;
	}
	return (n);
}

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

template < class T >
void swap(T& a, T& b) {
	T c(a);
	a = b;
	b = c;
}

/* make_pair */
// Creates a std::pair object, deducing the target type from the types of arguments.
template < class T1, class T2 >
pair< T1, T2 > make_pair(T1 x, T2 y) {
	return (pair< T1, T2 >(x, y));
}

}

#endif
