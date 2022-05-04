/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dataparsing_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:03:30 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/06/17 13:38:49 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/solong.h"

int		ft_inter_c(char c, char *needle)
{
	int	i;

	i = 0;
	while (needle[i])
	{
		if (needle[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		ft_inter(char *str, char *needle)
{
	int	flag;
	int	i;
	int	j;

	flag = 0;
	i = ft_strlen(str);
	if (i == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		j = 0;
		while (needle[j])
		{
			if (str[i] == needle[j])
				flag = 1;
			j++;
		}
		if (flag == 0)
			return (0);
		flag = 0;
		i++;
	}
	return (1);
}

int		find_col(t_window **window)
{
	int		y;
	int		x;
	int		res;

	res = 0;
	y = 0;
	while (y < (*window)->m_height)
	{
		x = 0;
		while (x < (*window)->m_width)
		{
			if ((*window)->m_data[y][x] == 'C')
				res++;
			x++;
		}
		y++;
	}
	return (res);
}
