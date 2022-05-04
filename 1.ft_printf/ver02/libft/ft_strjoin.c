/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 14:53:57 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/03/23 12:05:34 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2, int target)
{
	char		*res;
	size_t		len1;
	size_t		len2;

	if (!s1 && !s2)
		return (0);
	else if (!s1)
		return (ft_strdup(s2));
	else if (!s2)
		return (ft_strdup(s1));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	res = (char *)malloc(sizeof(char) * (len1 + len2 + 1));
	if (!res)
		return (0);
	ft_strlcpy(res, s1, len1 + 1);
	ft_strlcat(res + len1, s2, len2 + 1);
	if (target == 1 || target == 3)
		free(s1);
	if (target == 2 || target == 3)
		free(s2);
	return (res);
}
