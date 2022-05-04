/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   template.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 14:18:51 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/03/25 14:55:54 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEMPLATE_HPP
#define TEMPLATE_HPP

template <typename T>
void swap(T& a, T&b)
{
	T c;
	c = a;
	a = b;
	b = c;
}

template <typename T>
const T& min(const T& a, const T& b)
{
	return a < b ? a : b;
}

template <typename T>
const T& max(const T& a, const T& b)
{
	return a > b ? a : b;
}

#endif
