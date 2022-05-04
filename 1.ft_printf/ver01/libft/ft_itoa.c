/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 17:06:39 by seonhjeo          #+#    #+#             */
/*   Updated: 2020/12/23 19:52:27 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_abs_itoa(int n)
{
	if (n < 0)
		return (-n);
	return (n);
}

static int	ft_get_len_itoa(int n)
{
	int len;

	len = 0;
	if (n == 0)
		return (1);
	else
	{
		if (n < 0)
			len++;
		while (n != 0)
		{
			n /= 10;
			len++;
		}
		return (len);
	}
}

char		*ft_itoa(int n)
{
	char	*res;
	int		len;

	len = ft_get_len_itoa(n);
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = '\0';
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	while (n != 0)
	{
		res[--len] = '0' + ft_abs_itoa(n % 10);
		n /= 10;
	}
	return (res);
}
