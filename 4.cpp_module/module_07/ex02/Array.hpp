/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/29 14:21:09 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/04/14 16:11:07 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <stdexcept>

template <typename T>
class Array
{
private:
	T *_array;
	unsigned int _n;
public:
	Array() : _n(0)
	{
		this->_array = new T[0];
		if (!this->_array)
			throw std::runtime_error("allocating memory failed");
	}

	Array(unsigned int n) : _n(n)
	{
		this->_array = new T[n];
		if (!this->_array)
			throw std::runtime_error("allocating memory failed");
	}

	Array(Array<T> const &array)
	{
		this->_array = new T[array.size()];
		if (!this->_array)
			throw std::runtime_error("allocating memory failed");
		for (unsigned int i = 0; i < array.size(); i++)
			this->_array[i] = array[i];
		this->_n = array.size();
	}

	~Array()
	{
		delete[] this->_array;
		this->_array = NULL;
		this->_n = 0;
	}

	Array<T> &operator=(Array<T> const &array)
	{
		T* tmp = new T[array.size()];
		if (!tmp)
			throw std::runtime_error("allocating memory failed");
		for (unsigned int i = 0; i < array.size(); ++i)
			tmp[i] = array[i];
		delete[] this->_array;
		this->_array = tmp;
		this->_n = array.size();
	}

	T& operator[](unsigned int n)
	{
		if (this->_n <= n)
			throw std::exception();
		return this->_array[n];
	}

	const T& operator[](unsigned int n) const
	{
		if (this->_n <= n)
			throw std::exception();
		return this->_array[n];
	}

	unsigned int size() const
	{
		return (this->_n);
	}
};

#endif
