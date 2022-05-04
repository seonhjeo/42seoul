/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_under_three3.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 18:07:55 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:53:37 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_three_a(t_ps **temp, t_ps **res)
{
	int		n1;
	int		n2;
	int		n3;

	n1 = (*temp)->value;
	n2 = (*temp)->next->value;
	n3 = (*temp)->next->next->value;
	if (n3 > n1 && n1 > n2)
		sa(temp, 1, res);
	if (n1 > n2 && n2 > n3)
	{
		sa(temp, 1, res);
		rra(temp, 1, res);
	}
	if (n1 > n3 && n3 > n2)
		ra(temp, 1, res);
	if (n2 > n3 && n3 > n1)
	{
		sa(temp, 1, res);
		ra(temp, 1, res);
	}
	if (n2 > n1 && n1 > n3)
		rra(temp, 1, res);
	return ;
}

void	sort_three_b2(t_ps **a, t_ps **b, t_ps **res, t_numcheck *num)
{
	if (num->n1 < num->n3 && num->n3 < num->n2)
	{
		rb(b, 1, res);
		do_pa(a, b, res, 3);
	}
	if (num->n2 < num->n3 && num->n3 < num->n1)
	{
		pa(a, b, res);
		sort_two_b(b, res);
		do_pa(a, b, res, 2);
	}
	if (num->n2 < num->n1 && num->n1 < num->n3)
	{
		rrb(b, 1, res);
		do_pa(a, b, res, 3);
	}
	return ;
}

void	sort_three_b(t_ps **a, t_ps **b, t_ps **res)
{
	t_numcheck	num;

	num.n1 = (*b)->value;
	num.n2 = (*b)->next->value;
	num.n3 = (*b)->next->next->value;
	if (num.n3 < num.n1 && num.n1 < num.n2)
	{
		sb(b, 1, res);
		do_pa(a, b, res, 3);
	}
	if (num.n1 < num.n2 && num.n2 < num.n3)
	{
		sb(b, 1, res);
		rrb(b, 1, res);
		do_pa(a, b, res, 3);
	}
	return (sort_three_b2(a, b, res, &num));
}
