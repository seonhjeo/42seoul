/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/16 17:03:05 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/06/16 18:26:17 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACK_HPP
# define STACK_HPP

# include "vector.hpp"

namespace ft
{

template <class T, class Container = ft::vector<T> >
class stack
{
public:
   	typedef typename Container::value_type		value_type;
   	typedef typename Container::reference		reference;
   	typedef typename Container::const_reference	const_reference;
   	typedef typename Container::size_type		size_type;
   	typedef	Container					        container_type;

    /* constructor*/
	explicit stack( const Container& c = Container() ) : c(c) {}

    stack( const stack& other ) : c(other.c) {};
	
    /* capacity */

    // Checks if the underlying container has no elements
	bool empty() const{ return c.empty(); }

	// Returns the number of elements in the underlying container, that is, c.size().
	size_type size() const { return c.size(); }


	/* element access */

	// Returns reference to the top element in the stack. This is the most recently pushed element.
	// This element will be removed on a call to pop(). Effectively calls c.back()
	reference top() { return c.back(); }
	
	const_reference top() const { return c.back(); }

	
	/* modifier */

	// Pushes the given element value to the top of the stack.
	// Effectively calls c.push_back(value)
		void push( const value_type& val ) { c.push_back(val); }

	// Removes the top element from the stack.
	// Effectively calls c.pop_back()
	void pop() { c.pop_back(); }


	// Allows the non member operator to have access to the Sequence c.
	template<typename T1, typename Cont1>
	friend bool operator==(const stack<T1, Cont1>&, const stack<T1, Cont1>&);

	template<typename T1, typename Cont1>
	friend bool operator<(const stack<T1, Cont1>&, const stack<T1, Cont1>&);


	protected:
		container_type c;
	}; // class stack

	/* compare operator */
	// Compares the contents of the underlying containers of two container adaptors.
	// The comparison is done by applying the corresponding operator to the underlying containers
	template<class T, class Cont>
    bool operator==(const stack<T, Cont>& x, const stack<T, Cont>& y) {
		return x.c == y.c;
	}

	template<class T, class Cont>
    bool operator<(const stack<T, Cont>& x, const stack<T, Cont>& y){
		return x.c < y.c;
	}

	template<class T, class Cont>
    bool operator!=(const stack<T, Cont>& x, const stack<T, Cont>& y){
		return !(x == y);
	}

	template<class T, class Cont>
    bool operator>(const stack<T, Cont>& x, const stack<T, Cont>& y){
		return y < x;
	}

	template<class T, class Cont>
    bool operator<=(const stack<T, Cont>& x, const stack<T, Cont>& y){
		return !(y < x);
	}

	template<class T, class Cont>
    bool operator>=(const stack<T, Cont>& x, const stack<T, Cont>& y){
		return !(x < y);
	}

} // namespace ft

#endif