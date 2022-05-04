/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 12:12:33 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/25 15:48:28 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	ra(t_ps **a, int flag, t_ps **res)
{
	int		value;

	if (*a && (*a)->next)
	{
		value = (*a)->value;
		ft_lstdel_front_ps(a);
		ft_lstadd_back_ps(a, value, "");
		if (flag == 1)
			ft_lstadd_back_ps(res, 0, "ra");
	}
	return (1);
}

int	rb(t_ps **b, int flag, t_ps **res)
{
	int		value;

	if (*b && (*b)->next)
	{
		value = (*b)->value;
		ft_lstdel_front_ps(b);
		ft_lstadd_back_ps(b, value, "");
		if (flag == 1)
			ft_lstadd_back_ps(res, 0, "rb");
	}
	return (1);
}

int	rra(t_ps **a, int flag, t_ps **res)
{
	t_ps	*temp;
	int		value;

	temp = *a;
	if (temp && temp->next)
	{
		while (temp->next)
			temp = temp->next;
		value = temp->value;
		ft_lstdel_back_ps(a);
		ft_lstadd_front_ps(a, value, "");
		(*a)->next->prev = *a;
		if (flag == 1)
			ft_lstadd_back_ps(res, 0, "rra");
	}
	return (1);
}

int	rrb(t_ps **b, int flag, t_ps **res)
{
	t_ps	*temp;
	int		value;

	temp = *b;
	if (temp && temp->next)
	{
		while (temp->next)
			temp = temp->next;
		value = temp->value;
		ft_lstdel_back_ps(b);
		ft_lstadd_front_ps(b, value, "");
		(*b)->next->prev = *b;
		if (flag == 1)
			ft_lstadd_back_ps(res, 0, "rrb");
	}
	return (1);
}
