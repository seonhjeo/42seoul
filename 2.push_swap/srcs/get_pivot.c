/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 11:54:04 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:54:10 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	bubble_sort(int *x, int size)
{
	int		i;
	int		j;
	int		swap;

	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (x[i] > x[j])
			{
				swap = x[i];
				x[i] = x[j];
				x[j] = swap;
			}
			j++;
		}
		i++;
	}
}

int	ft_pivot(t_ps *a, t_data *data, int len)
{
	int		*x;
	int		i;
	t_ps	*ptr;

	ptr = a;
	i = 0;
	x = (int *)malloc(sizeof(int) * len);
	while (ptr && i < len)
	{
		x[i++] = ptr->value;
		ptr = ptr->next;
	}
	bubble_sort(x, i);
	data->pivots = x[(len - 1) / 3];
	data->pivotb = x[(len - 1) / 3 * 2];
	free(x);
	return (i);
}

int	ft_pivot_for_45(t_ps *a, int len)
{
	int		*x;
	int		i;
	t_ps	*ptr;

	ptr = a;
	i = 0;
	x = (int *)malloc(sizeof(int) * len);
	while (ptr && i < len)
	{
		x[i++] = ptr->value;
		ptr = ptr->next;
	}
	bubble_sort(x, i);
	i = x[1];
	free(x);
	return (i);
}
