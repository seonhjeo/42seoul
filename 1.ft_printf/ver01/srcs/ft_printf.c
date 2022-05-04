/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/13 11:20:46 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/01/19 17:04:26 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

char	*ft_add_ap(char *res, const char *str, va_list ap, size_t i)
{
	char	*temp;

	temp = NULL;
	if (str[i] == 'c')
		temp = ft_strcadd(res, ap);
	else if (str[i] == 's')
		temp = ft_strsadd(res, ap);
	return (temp);
}

char	*ft_make_final(const char *str, va_list ap)
{
	char	*res;
	size_t	i;
	size_t	start;

	if (!(res = ft_strdup("")))
		return (0);
	i = 0;
	start = 0;
	while (str[i])
	{
		if (str[i] == '%' || str[i + 1] == '\0')
		{
			res = ft_strnjoin(res, str, start, i++);
			res = ft_add_ap(res, str, ap, i);
			start = ++i;
		}
		i++;
	}
	return (res);
}

int		ft_printf(const char *str, ...)
{
	char		*res;
	va_list 	ap;
	size_t		len;

	if (!str)
		return (0);
	va_start(ap, str);
	if (!(res = ft_make_final(str, ap)))
		return (-1);
	ft_putstr(res);
	len = ft_strlen(res);
	free(res);
	va_end(ap);
	return (len);
}

