/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:34:55 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/22 15:59:07 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*f1;
	const unsigned char	*f2;

	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	while (n--)
	{
		if (*f1 != *f2)
			return (*f1 - *f2);
		f1++;
		f2++;
	}
	return (0);
}
