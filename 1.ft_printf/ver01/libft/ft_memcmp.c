/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 10:34:55 by seonhjeo          #+#    #+#             */
/*   Updated: 2020/12/23 10:36:06 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
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
