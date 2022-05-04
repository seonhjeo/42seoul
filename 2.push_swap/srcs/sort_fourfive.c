/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_fourfive.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:13:55 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:36:30 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_four_a(t_ps **a, t_ps **b, t_ps **res)
{
	t_data	data;

	if (is_sorted(a, 4, 1))
		return ;
	init_data(&data);
	data.pivotb = ft_pivot_for_45(*a, 4);
	data.i = 0;
	while (data.i < 4)
	{
		if ((*a)->value > data.pivotb)
			data.ranum += ra(a, 1, res);
		else
			data.pnum += pb(a, b, res);
		data.i++;
	}
	data.i = 0;
	if (get_list_length(a) > 4)
	{
		while (data.i < data.ranum)
			data.i += rra(a, 1, res);
	}
	a_to_b(data.ranum, a, b, res);
	b_to_a(data.pnum, a, b, res);
}

void	sort_four_b(t_ps **a, t_ps **b, t_ps **res)
{
	t_data	data;

	if (is_sorted(b, 4, 2))
		return (do_pa(a, b, res, 4));
	init_data(&data);
	data.pivotb = ft_pivot_for_45(*b, 4);
	data.i = 0;
	while (data.i < 4)
	{
		if ((*b)->value <= data.pivotb)
			data.rbnum += rb(b, 1, res);
		else
			data.pnum += pa(a, b, res);
		data.i++;
	}
	data.i = 0;
	if (get_list_length(b) > 4)
	{
		while (data.i < data.rbnum)
			data.i += rrb(b, 1, res);
	}
	sort_two_a(a, res);
	sort_two_b(b, res);
	do_pa(a, b, res, 2);
}

void	sort_five_a(t_ps **a, t_ps **b, t_ps **res)
{
	t_data	data;

	if (is_sorted(a, 5, 1))
		return ;
	init_data(&data);
	data.pivotb = ft_pivot_for_45(*a, 5);
	data.i = 0;
	while (data.i < 5)
	{
		if ((*a)->value > data.pivotb)
			data.ranum += ra(a, 1, res);
		else
			data.pnum += pb(a, b, res);
		data.i++;
	}
	data.i = 0;
	if (get_list_length(a) > 5)
	{
		while (data.i < data.ranum)
			data.i += rra(a, 1, res);
	}
	a_to_b(data.ranum, a, b, res);
	b_to_a(data.pnum, a, b, res);
}

void	sort_five_b(t_ps **a, t_ps **b, t_ps **res)
{
	t_data	data;

	if (is_sorted(b, 5, 2))
		return (do_pa(a, b, res, 5));
	init_data(&data);
	data.pivotb = ft_pivot_for_45(*b, 5);
	data.i = 0;
	while (data.i < 5)
	{
		if ((*b)->value <= data.pivotb)
			data.rbnum += rb(b, 1, res);
		else
			data.pnum += pa(a, b, res);
		data.i++;
	}
	data.i = 0;
	if (get_list_length(b) > 5)
	{
		while (data.i < data.rbnum)
			data.i += rrb(b, 1, res);
	}
	a_to_b(data.pnum, a, b, res);
	b_to_a(data.rbnum, a, b, res);
}
