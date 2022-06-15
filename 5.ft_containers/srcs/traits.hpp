/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   traits.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/02 14:10:33 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/10 15:30:08 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_TRAITS_HPP
# define FT_TRAITS_HPP

# include <cstddef>
# include <iostream>

namespace ft
{

template <class>
struct check_type { typedef void type; };

/* enable if */
// If B is true, std::enable_if has a public member typedef type, equal to T;
// otherwise, there is no member typedef.
template < bool B, class T = void >
struct enable_if {};

template < class T >
struct enable_if< true, T > {
	typedef T type;
};

/* is_same */
template <class T, class U>
struct is_same { static const bool value = false; };

template <class T>
struct is_same<T, T> { static const bool value = true; };

/* conditional */
template <bool B, class T = void, class U = void>
struct conditional {};

template <class T, class U>
struct conditional<true, T, U> { typedef T type; };

template <class T, class U>
struct conditional<false, T, U> { typedef U type; };


/* integral_constant */
// std::integral_constant wraps a static constant of specified type. It is the base class for the C++ type traits.
// Two typedefs for the common case where T is bool are provided
struct true_type {
  static const bool value = true;
  typedef bool value_type;
  typedef true_type type;
};

struct false_type {
  static const bool value = false;
  typedef bool value_type;
  typedef false_type type;
};

/* is_integral */
// Checks whether T is an integral type. Provides the member constant value which is equal to true,
// if T is the type bool, char, char8_t (since C++20), char16_t, char32_t, wchar_t, short, int, long, long long,
// or any implementation-defined extended integer types, including any signed, unsigned, and cv-qualified variants.
// Otherwise, value is equal to false.
template < class T >
struct is_integral : public false_type {};

template <>
struct is_integral< bool > : public true_type {};
template <>
struct is_integral< char > : public true_type {};
template <>
struct is_integral< char16_t > : public true_type {};
template <>
struct is_integral< char32_t > : public true_type {};
template <>
struct is_integral< wchar_t > : public true_type {};
template <>
struct is_integral< signed char > : public true_type {};
template <>
struct is_integral< short int > : public true_type {};
template <>
struct is_integral< int > : public true_type {};
template <>
struct is_integral< long int > : public true_type {};
template <>
struct is_integral< long long int > : public true_type {};
template <>
struct is_integral< unsigned char > : public true_type {};
template <>
struct is_integral< unsigned short int > : public true_type {};
template <>
struct is_integral< unsigned int > : public true_type {};
template <>
struct is_integral< unsigned long int > : public true_type {};
template <>
struct is_integral< unsigned long long int > : public true_type {};



/* iterator category */
// Defines the category of an iterator. Each tag is an empty type.
struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : public input_iterator_tag {};
struct bidirectional_iterator_tag : public forward_iterator_tag {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};


/* iterator */
// std::iterator is the base class provided to simplify definitions of the required types for iterators.
template < class Category, class T, class Distance = std::ptrdiff_t,
		   class Pointer = T*, class Reference = T& >
struct iterator {
	typedef Category	iterator_category;
	typedef T			value_type;
	typedef Distance	difference_type;
	typedef Pointer		pointer;
	typedef Reference	reference;
};

/* iterator_traits */
// std::iterator_traits is the type trait class that provides uniform interface to the properties of LegacyIterator types.
// This makes it possible to implement algorithms only in terms of iterators.
template < class Iterator >
struct iterator_traits {
	typedef typename Iterator::iterator_category	iterator_category;
	typedef typename Iterator::value_type			value_type;
	typedef typename Iterator::difference_type		difference_type;
	typedef typename Iterator::pointer				pointer;
	typedef typename Iterator::reference			reference;
};

/* iterator_traits specializations */
// This type trait may be specialized for user-provided types that may be used as iterators.
// The standard library provides partial specializations for pointer types T*,
// which makes it possible to use all iterator-based algorithms with raw pointers.
template < class T >
struct iterator_traits< T* > {
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef T*							pointer;
	typedef T&							reference;
};

template < class T >
struct iterator_traits< T* const > {
	typedef random_access_iterator_tag	iterator_category;
	typedef T							value_type;
	typedef ptrdiff_t					difference_type;
	typedef const T*					pointer;
	typedef const T&					reference;
};

}

#endif
