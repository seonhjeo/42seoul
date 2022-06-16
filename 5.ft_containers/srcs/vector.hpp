/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:59:05 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/16 18:20:01 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define VECTOR_HPP

# include <memory>
# include <cstddef>
# include <iostream>

# include "utility.hpp"
# include "random_access_iterator.hpp"
# include "reverse_iterator.hpp"

namespace ft
{

template < class T, class Alloc = std::allocator< T > >
class vector
{
public:
	typedef T														value_type;
	typedef T const													const_value_type;
	typedef Alloc													allocator_type;
	typedef typename std::size_t									size_type;
	typedef typename std::ptrdiff_t									difference_type;
	typedef typename allocator_type::reference						reference;
	typedef typename allocator_type::const_reference				const_reference;
	typedef typename allocator_type::pointer						pointer;
	typedef typename allocator_type::const_pointer					const_pointer;
	typedef typename ft::random_access_iterator< value_type >		iterator;
	typedef typename ft::random_access_iterator< const_value_type >	const_iterator;
	typedef typename ft::reverse_iterator< iterator >				reverse_iterator;
	typedef typename ft::reverse_iterator< const_iterator >			const_reverse_iterator;


private:
	allocator_type	_alloc;
	pointer			_start;
	pointer			_end;
	pointer			_end_capacity;

public:
	/* constructor, copy, destructor */
	// empty container consturctor
	explicit vector(const allocator_type& alloc = allocator_type())
	: _alloc(alloc), _start(u_nullptr), _end(u_nullptr), _end_capacity(u_nullptr)
	{};

	// container with n elements. Each element is a copy of val.
	explicit vector(size_type n, const value_type& val = value_type(),
		const allocator_type& alloc = allocator_type()) : _alloc(alloc) {
		this->_start = this->_alloc.allocate(n);
		this->_end = this->_start;
		this->_end_capacity = this->_start + n;
		while (n--)
			this->_alloc.construct(this->_end++, val);
	};

	// range constructor
	// Constructs a container with as many elements as the range [first,last),
	// with each element constructed from its corresponding element in that range, in the same order.
	template < class InputIterator >
	vector(InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type(),
		typename ft::enable_if< !ft::is_integral< InputIterator >::value >::type* = u_nullptr) : _alloc(alloc) {
		size_type n = ft::difference(first, last);
		this->_start = this->_alloc.allocate(n);
		this->_end_capacity = this->_start + n;
		this->_end = this->_start;
		while (n--)
			this->_alloc.construct(this->_end++, *first++);
	};

	// copy constructor
	vector(const vector& x) : _alloc(x._alloc) {
		size_type n = x.size();
		this->_start = this->_alloc.allocate(n);
		this->_end_capacity = this->_start + n;
		this->_end = this->_start;

		pointer other = x._start;
		while (n--) this->_alloc.construct(this->_end++, *other++);
	};

	vector& operator=(const vector& x) {
		if (this != &x) {
			this->clear();
			this->insert(this->_start, x.begin(), x.end());
		}
		return *this;
	};

	// destructor
	~vector() {
		this->clear();
		this->_alloc.deallocate(this->_start, this->capacity());
	};

	/* iterator function */
	iterator begin() { return iterator(this->_start); };
	const_iterator begin() const { return iterator(this->_start); };
	reverse_iterator rbegin() { return reverse_iterator(iterator(this->_end)); };
	const_reverse_iterator rbegin() const { return const_reverse_iterator(iterator(this->_end)); };
	iterator end() { return iterator(this->_end); }
	const_iterator end() const { return iterator(this->_end); }
	reverse_iterator rend() { return reverse_iterator(iterator(this->_start)); };
	const_reverse_iterator rend() const { return const_reverse_iterator(iterator(this->_start)); };

	size_type size() const { return (this->_end - this->_start); };
	size_type max_size() const { return (this->_alloc.max_size()); };


	void resize(size_type n, value_type val = value_type()) {
		if (n > this->max_size()) {
			throw std::out_of_range("ft::vector");
		}
		size_type prev_size = this->size();
		if (prev_size > n) {
			while (prev_size-- > n) {
				this->_alloc.destroy(--this->_end);
			}
			return;
		}
		this->insert(this->_end, n - prev_size, val);
	};

	size_type capacity() const { return (this->_end_capacity - this->_start); };
	bool empty() const { return (this->size() == 0); };

	// Increase the capacity of the vector (the total number of elements that the vector can hold without requiring reallocation)
	// to a value that's greater or equal to new_cap.
	// If new_cap is greater than the current capacity(), new storage is allocated, otherwise the function does nothing
	void reserve(size_type n) {
		if (n > this->max_size()) {
			throw std::out_of_range("ft::vector");
		}

		if (this->capacity() >= n) {
			return;
		}

		pointer prev_start = this->_start;
		pointer prev_end = this->_end;
		size_type prev_capacity = this->capacity();

		this->_start = this->_alloc.allocate(n);
		this->_end_capacity = this->_start + n;
		this->_end = this->_start;

		for (pointer target = prev_start; target != prev_end; ++target) {
			this->_alloc.construct(this->_end++, *target);
		}
		for (size_type len = prev_end - prev_start; len > 0; --len) {
			this->_alloc.destroy(--prev_end);
		}
		this->_alloc.deallocate(prev_start, prev_capacity);
	};

	reference operator[](size_type n) { return (this->_start[n]); };
	const_reference operator[](size_type n) const { return (this->_start[n]); };

	reference at(size_type n) {
		if (this->size() < n) {
			throw std::out_of_range("ft::vector");
		}
		return (this->_start[n]);
	};

	const_reference at(size_type n) const {
		if (this->size() < n) {
			throw std::out_of_range("ft::vector");
		}
		return (this->_start[n]);
	};

	reference front() { return (*this->_start); };
	const_reference front() const { return (*this->_start); };
	reference back() { return *(this->_end - 1); };
	const_reference back() const { return *(this->_end - 1); };

	// Replaces the contents of the container.
	template < class InputIterator >
	void assign(
			InputIterator first, InputIterator last,
			typename ft::enable_if<
					!ft::is_integral< InputIterator >::value >::type* = u_nullptr) {
		size_type n = ft::difference(first, last);
		if (this->capacity() < n) {
			this->_start = this->_alloc.allocate(n);
			this->_end_capacity = this->_start + n;
			this->_end = this->_start;
		} else {
			this->clear();
		}
		while (n--) this->_alloc.construct(this->_end++, *first++);
	};

	// Replaces the contents of the container.
	void assign(size_type n, const value_type& val) {
		this->clear();
		if (this->capacity() >= n) {
			while (n--) this->_alloc.construct(this->_end++, val);
		} else {
			this->_start = this->_alloc.allocate(n);
			this->_end_capacity = this->_start + n;
			this->_end = this->_start;
			while (n--) this->_alloc.construct(this->_end++, val);
		}
	};

	// Add element at the end
	void push_back(const value_type& val) {
		if (this->_end_capacity == this->_end) {
			size_type capacity =
					(this->size() == 0) ? 1 : (this->_end_capacity - this->_start) * 2;
			this->reserve(capacity);
		}
		this->_alloc.construct(this->_end++, val);
	};

	// Delete last element
	void pop_back() { this->_alloc.destroy(--this->_end); };

	// Insert elements
	iterator insert(iterator position, const value_type& val) {
		size_type pos_at = &(*position) - this->_start;
		this->insert(position, 1, val);
		return (this->_start + pos_at);
	};

	// Inserts elements at the specified location in the container.
	void insert(iterator position, size_type n, const value_type& val) {
		size_type pos_at = &(*position) - this->_start;

		if (this->capacity() >= this->size() + n) {
			for (size_type i = 0; i < this->size() - pos_at; ++i) {
				this->_alloc.construct(this->_end + n - i, *(this->_end - i));
				this->_alloc.destroy(this->_end - i);
			}
			this->_end = this->_start + this->size() + n;
			for (size_type i = 0; i < n; ++i) {
				this->_alloc.construct(this->_start + pos_at + i, val);
			}
			return;
		}

		size_type next_capacity = this->size() + n;

		pointer prev_start = this->_start;
		pointer prev_end = this->_end;
		size_type prev_size = this->size();
		size_type prev_capacity = this->capacity();

		this->_start = this->_alloc.allocate(next_capacity);
		this->_end = this->_start + prev_size + n;
		this->_end_capacity = this->_end;

		for (size_type i = 0; i < pos_at; ++i) {
			this->_alloc.construct(this->_start + i, *(prev_start + i));
			this->_alloc.destroy(prev_start + i);
		}

		for (size_type i = 0; i < prev_size - pos_at; ++i) {
			this->_alloc.construct(this->_end - i - 1, *(prev_end - i - 1));
			this->_alloc.destroy(prev_end - i - 1);
		}

		for (size_type i = 0; i < n; ++i) {
			this->_alloc.construct(this->_start + pos_at + i, val);
		}

		this->_alloc.deallocate(prev_start, prev_capacity);
		return;
	};

	// Inserts elements at the specified location in the container.
	template < class InputIterator >
	void insert(
			iterator position, InputIterator first, InputIterator last,
			typename ft::enable_if<
					!ft::is_integral< InputIterator >::value >::type* = u_nullptr) {
		size_type pos_at = &(*position) - this->_start;
		size_type n = ft::difference(first, last);

		if (this->capacity() >= this->size() + n) {
			for (size_type i = 0; i < this->size() - pos_at; ++i) {
				this->_alloc.construct(this->_end + n - i, *(this->_end - i));
				this->_alloc.destroy(this->_end - i);
			}
			this->_end = this->_start + this->size() + n;
			for (size_type i = 0; i < n; ++i) {
				this->_alloc.construct(this->_start + pos_at + i, *first++);
			}
			return;
		}

		size_type next_capacity = this->size() + n;

		pointer prev_start = this->_start;
		pointer prev_end = this->_end;
		size_type prev_size = this->size();
		size_type prev_capacity = this->capacity();

		this->_start = this->_alloc.allocate(next_capacity);
		this->_end = this->_start + prev_size + n;
		this->_end_capacity = this->_end;

		for (size_type i = 0; i < pos_at; ++i) {
			this->_alloc.construct(this->_start + i, *(prev_start + i));
			this->_alloc.destroy(prev_start + i);
		}

		for (size_type i = 0; i < prev_size - pos_at; ++i) {
			this->_alloc.construct(this->_end - i - 1, *(prev_end - i - 1));
			this->_alloc.destroy(prev_end - i - 1);
		}

		for (size_type i = 0; i < n; ++i) {
			this->_alloc.construct(this->_start + pos_at + i, *first++);
		}
		this->_alloc.deallocate(prev_start, prev_capacity);
		return;
	}

	// Erases the specified elements from the container.
	iterator erase(iterator position) {
		size_type pos_at = &(*position) - this->_start;
		this->_alloc.destroy(&(*position));
		for (size_type i = 0; i < this->size() - pos_at; ++i) {
			this->_alloc.construct(this->_start + pos_at + i,
														 *(this->_start + pos_at + i + 1));
			this->_alloc.destroy(this->_start + pos_at + i + 1);
		}
		--this->_end;
		return this->_start + pos_at;
	};
	// Erases the specified elements from the container.
	iterator erase(iterator first, iterator last) {
		size_type pos_at = &(*first) - this->_start;
		size_type n = last - first;
		for (size_type i = 0; i < n; ++i) {
			this->_alloc.destroy(&(*(first + i)));
		}
		for (size_type i = 0; i < this->size() - pos_at; ++i) {
			this->_alloc.construct(this->_start + pos_at + i,
														 *(this->_start + pos_at + i + n));
			this->_alloc.destroy(this->_start + pos_at + i + n);
		}
		this->_end = this->_start + this->size() - n;
		return this->_start + pos_at;
	};

	// Exchanges the contents of the container with those of other.
	// Does not invoke any move, copy, or swap operations on individual elements.
	void swap(vector& x) {
		if (&x == this) {
			return;
		}

		pointer start = x._start;
		pointer end = x._end;
		pointer end_capacity = x._end_capacity;
		x._start = this->_start;
		x._end = this->_end;
		x._end_capacity = this->_end_capacity;
		this->_start = start;
		this->_end = end;
		this->_end_capacity = end_capacity;
	};

	// Erases all elements from the container. After this call, size() returns zero.
	void clear() {
		while (this->_start != this->_end) {
			this->_alloc.destroy(--this->_end);
		}
	};

	// Returns the allocator associated with the container.
	allocator_type get_allocator() const { return this->_alloc; };
};

/* Compare operator for vector */
template < class T, class Alloc >
bool operator==(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
	if (lhs.size() != rhs.size()) {
		return false;
	}
	return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
};

template < class T, class Alloc >
bool operator!=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
	return !(lhs == rhs);
};

template < class T, class Alloc >
bool operator<(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
};

template < class T, class Alloc >
bool operator<=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
	return (!(rhs < lhs));
};

template < class T, class Alloc >
bool operator>(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
	return (rhs < lhs);
};

template < class T, class Alloc >
bool operator>=(const vector< T, Alloc >& lhs, const vector< T, Alloc >& rhs) {
	return (!(lhs < rhs));
};

template < class T, class Alloc >
void swap(vector< T, Alloc >& x, vector< T, Alloc >& y) {
	x.swap(y);
};

} // namespace ft

#endif
