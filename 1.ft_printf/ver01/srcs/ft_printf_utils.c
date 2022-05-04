/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/15 14:36:07 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/01/19 16:51:33 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

int		ft_is_format(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd')
		return (1);
	else if (c == 'i' || c == 'u' || c == 'x' || c == 'X' || c == '%')
		return (1);
	else
		return (0);
}

void	ft_strncat(char *restrict dst, const char *restrict src,
	size_t start, size_t end)
{
	size_t	len;
	size_t	i;
	size_t	j;

	len = ft_strlen(src);
	i = ft_strlen(dst);
	j = start;
	while (src[j] != '\0' && j < end)
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
}

char	*ft_strcadd(char *res, va_list ap)
{
	char	*temp;
	size_t	len;
	char	c;

	c = va_arg(ap, int);
	if (!res || !c)
		return (0);
	len = ft_strlen(res);
	if (!(temp = (char *)malloc(len + 2)))
		return (0);
	ft_strlcpy(temp, res, len + 1);
	temp[len] = c;
	temp[len + 1] = '\0';
	free(res);
	return (temp);
}

char	*ft_strsadd(char *res, va_list ap)
{
	char	*temp;
	char	*src;

	src = va_arg(ap, char*);
	if (!res || !src)
		return (0);
	temp = ft_strjoin(res, src);
	free(res);
	return (temp);
}

char	*ft_strnjoin(char *res, const char *str, size_t start, size_t end)
{
	char		*temp;
	size_t		len1;

	if (!res || !str)
		return (0);
	len1 = ft_strlen(res);
	if (end > ft_strlen(str))
		end = ft_strlen(str);
	else if (start > end)
		return (0);
	if (str[end + 1] == '\0')
		end++;
	if (!(temp = (char *)malloc(sizeof(char) * (len1 + (end - start) + 1))))
		return (0);
	ft_strlcpy(temp, res, len1 + 1);
	ft_strncat(temp + len1, str, start, end);
	free(res);
	return (temp);
}
