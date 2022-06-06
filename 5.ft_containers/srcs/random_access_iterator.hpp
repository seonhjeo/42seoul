/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:47:14 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/06 17:58:27 by seonhjeo         ###   ########.fr       */
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
	random_access_iterator(pointer _ptr = ft::u_nullptr) : _ptr(_ptr)
	{};

	random_access_iterator(const random_access_iterator< T >& other) : _ptr(other._ptr)
	{};

	template < typename diffT >
	random_access_iterator(const random_access_iterator< diffT >& other) : ptr(other.base())
	{};

	random_access_iterator &operator=(const random_access_iterator& other) {
		this.ptr = other.base();
		return (*this);
	}

	virtual ~random_access_iterator()
	{};

	operator random_access_iterator< const T >() const {
		return (this->_ptr);
	}

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

	reference operator*() const {
		return (*_ptr);
	};

  /**
   * @brief Returns a pointer to the pointed  (in order to access one of its
   * members).
   */
  pointer operator->() const { return &(operator*()); };

  /**
   * @brief Decreases the random_access_iterator by one position.
   * @example --_ptr;
   */
  random_access_iterator& operator--() {
    --_ptr;
    return *this;
  };

  /**
   * @brief Decreases the random_access_iterator by one position.
   * @example _ptr--;
   */
  random_access_iterator operator--(int) {
    random_access_iterator tmp = *this;
    --(*this);
    return tmp;
  };

  /**
   * @brief Returns a iterator pointing to the _ptrent located n
   * positions away from the _ptrent the iterator _ptrly points to.
   */
  random_access_iterator operator+(difference_type n) const {
    return random_access_iterator(this->_ptr + n);
  };

  /**
   * @brief Advances the random_access_iterator by n _ptrent positions.
   */
  random_access_iterator& operator+=(difference_type n) {
    this->_ptr += n;
    return *this;
  };

  /**
   * @brief Returns a iterator pointing to the _ptrent located n
   * positions before the _ptrent the iterator _ptrly points to.
   */
  random_access_iterator operator-(difference_type n) const {
    return random_access_iterator(this->_ptr - n);
  }

  /**
   * @brief Advances the random_access_iterator by n _ptrent positions.
   */
  random_access_iterator& operator-=(difference_type n) {
    this->_ptr -= n;
    return *this;
  };

  /**
   * @brief Accesses the _ptrent located n positions away from the _ptrent
   * _ptrly pointed to by the iterator.
   */
  reference operator[](difference_type n) const { return (this->_ptr[n]); };

  /**
   * @brief get base _ptr
   *
   * @return pointer const&
   */
  pointer const& base() const { return this->_ptr; }
};

/**
 * @brief Relational operators== for random_access_iterator
 */
template < class T1, class T2 >
bool operator==(const random_access_iterator< T1 >& lhs,
                const random_access_iterator< T2 >& rhs) {
  return (lhs.base() == rhs.base());
};

/**
 * @brief Relational operators!= for random_access_iterator
 */
template < class T1, class T2 >
bool operator!=(const random_access_iterator< T1 >& lhs,
                const random_access_iterator< T2 >& rhs) {
  return (lhs.base() != rhs.base());
};

/**
 * @brief Relational operators< for random_access_iterator
 */
template < class T1, class T2 >
bool operator<(const random_access_iterator< T1 > lhs,
               const random_access_iterator< T2 >& rhs) {
  return (lhs.base() < rhs.base());
};

/**
 * @brief Relational operators<= for random_access_iterator
 */
template < class T1, class T2 >
bool operator<=(const random_access_iterator< T1 >& lhs,
                const random_access_iterator< T2 >& rhs) {
  return (lhs.base() <= rhs.base());
};

/**
 * @brief Relational operators> for random_access_iterator
 */
template < class T1, class T2 >
bool operator>(const random_access_iterator< T1 > lhs,
               const random_access_iterator< T2 >& rhs) {
  return (lhs.base() > rhs.base());
};

/**
 * @brief Relational operators>= for random_access_iterator
 */
template < class T1, class T2 >
bool operator>=(const random_access_iterator< T1 >& lhs,
                const random_access_iterator< T2 >& rhs) {
  return (lhs.base() >= rhs.base());
};

/**
 * @brief Returns a iterator pointing to the _ptrent located n positions
 * away from the _ptrent pointed to by iter.
 *
 * @param n  Number of _ptrents to offset.
 * Member type difference_type is an alias of Iterator's own difference type.
 * @param iter iterator.
 */
template < class Iterator >
random_access_iterator< Iterator > operator+(
    typename random_access_iterator< Iterator >::difference_type n,
    const random_access_iterator< Iterator >& iter) {
  return iter + n;
};

/**
 * @brief Returns the distance between lhs and rhs.
 */
template < class T1, class T2 >
typename random_access_iterator< T1 >::difference_type operator-(
    const random_access_iterator< T2 >& lhs,
    const random_access_iterator< T1 >& rhs) {
  return lhs.base() - rhs.base();
};

}

#endif
