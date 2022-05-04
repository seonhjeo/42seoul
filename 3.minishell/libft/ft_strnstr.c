/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 16:27:55 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/05 17:58:34 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n;
	char	*s1;
	char	*s2;

	i = 0;
	n = ft_strlen(needle);
	if (*needle == '\0')
		return ((char *)haystack);
	while (i < len && *haystack)
	{
		s1 = (char *)haystack;
		s2 = (char *)needle;
		while (*s1 == *s2 && *s2)
		{
			s1++;
			s2++;
		}
		if (*s2 == '\0' && ((i + n) <= len))
			return ((char *)haystack);
		i++;
		haystack++;
	}
	return (NULL);
}
