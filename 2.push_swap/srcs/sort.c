/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 14:55:28 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:53:15 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	init_data(t_data *data)
{
	data->i = 0;
	data->pivotb = 0;
	data->pivots = 0;
	data->pnum = 0;
	data->ranum = 0;
	data->rbnum = 0;
}

int	get_pivot(t_ps **list, int len)
{
	t_ps	*temp;
	int		num;
	int		sum;

	temp = (*list);
	num = 0;
	sum = 0;
	while (num < len)
	{
		num++;
		sum += temp->value;
		temp = temp->next;
	}
	return (sum / num);
}

int	is_sorted(t_ps **list, int len, int flag)
{
	t_ps	*temp;
	int		i;

	temp = (*list);
	i = 0;
	while (i < len)
	{
		if (temp->next != 0)
		{
			if (flag == 1)
			{
				if (temp->value > temp->next->value)
					return (0);
			}
			if (flag == 2)
			{
				if (temp->value < temp->next->value)
					return (0);
			}
		}
		temp = temp->next;
		i++;
	}
	return (1);
}

void	a_to_b(int len, t_ps **a, t_ps **b, t_ps **res)
{
	t_data	data;

	if (is_sorted(a, len, 1))
		return ;
	if (len <= 3)
		return (sort_under_three_a(len, a, b, res));
	data.pivotb = get_pivot(a, len);
	data.ranum = 0;
	data.pnum = 0;
	data.i = 0;
	while (data.i < len)
	{
		if ((*a)->value > data.pivotb)
			data.ranum += ra(a, 1, res);
		else
			data.pnum += pb(a, b, res);
		data.i++;
	}
	data.i = 0;
	while (data.i < data.ranum)
		data.i += rra(a, 1, res);
	a_to_b(data.ranum, a, b, res);
	b_to_a(data.pnum, a, b, res);
}

void	b_to_a(int len, t_ps **a, t_ps **b, t_ps **res)
{
	t_data	data;

	if (is_sorted(b, len, 2))
		return (do_pa(a, b, res, len));
	if (len <= 3)
		return (sort_under_three_b(len, a, b, res));
	data.pivotb = get_pivot(b, len);
	data.rbnum = 0;
	data.pnum = 0;
	data.i = 0;
	while (data.i < len)
	{
		if ((*b)->value <= data.pivotb)
			data.rbnum += rb(b, 1, res);
		else
			data.pnum += pa(a, b, res);
		data.i++;
	}
	data.i = 0;
	while (data.i < data.rbnum)
		data.i += rrb(b, 1, res);
	a_to_b(data.pnum, a, b, res);
	b_to_a(data.rbnum, a, b, res);
}
