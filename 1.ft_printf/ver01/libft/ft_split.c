/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42seoul.kr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/23 16:10:28 by seonhjeo          #+#    #+#             */
/*   Updated: 2020/12/29 12:13:30 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_sc(char const *s, char c)
{
	int		i;
	int		cnt;

	i = 0;
	cnt = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c && s[i + 1] != '\0')
			cnt++;
		i++;
	}
	return (cnt);
}

static char		**ft_free_split(char **res)
{
	int		i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (0);
}

static void		ft_strcpy_split(char *res, char const *s, int start, int end)
{
	size_t	i;

	i = 0;
	while (start < end)
	{
		res[i] = s[start];
		i++;
		start++;
	}
	res[i] = '\0';
}

char			**ft_split(char const *s, char c)
{
	char	**res;
	size_t	i;
	size_t	j;
	size_t	end;

	if (!s || !(res = (char **)malloc(sizeof(char *) * (ft_sc(s, c) + 2))))
		return (0);
	i = 0;
	j = 0;
	while (i < ft_strlen(s))
	{
		if (s[i] != c)
		{
			end = i + 1;
			while (s[end] != c && s[end] != '\0')
				end++;
			if (!(res[j] = (char *)malloc(sizeof(char) * (end - i + 2))))
				return (ft_free_split(res));
			ft_strcpy_split(res[j++], s, i, end);
			i = end;
		}
		i++;
	}
	res[j] = 0;
	return (res);
}
