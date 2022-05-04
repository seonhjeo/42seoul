/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/06 15:08:56 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/22 19:15:59 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	slen;
	size_t	i;

	slen = 0;
	while (src[slen] != '\0')
	{
		slen++;
	}
	if (dstsize == 0)
	{
		return (slen);
	}
	i = 0;
	while (src[i] != '\0' && i < (dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = 0;
	return (slen);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	dlen;
	size_t	slen;

	dlen = ft_strlen(dst);
	slen = ft_strlen(src);
	i = 0;
	while (src[i] != '\0' && dlen + 1 + i < dstsize)
	{
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	if (dstsize < dlen)
		return (dstsize + slen);
	return (dlen + slen);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*newstr;
	int		len1;
	int		len2;

	if (!(s1) && !(s2))
		return (NULL);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	newstr = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!newstr)
		return (NULL);
	ft_strlcpy(newstr, s1, len1 + 1);
	free(s1);
	ft_strlcat(newstr + (len1), s2, len2 + 1);
	return (newstr);
}

char	*ft_strdup(char *s1)
{
	char	*result;
	int		i;

	i = ft_strlen(s1);
	result = (char *)malloc(sizeof(char) * (i + 1));
	if (!result)
		return (0);
	i = 0;
	while (s1[i])
	{
		result[i] = s1[i];
		i++;
	}
	result[i] = '\0';
	return (result);
}
