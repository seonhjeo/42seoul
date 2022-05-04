/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/25 10:35:22 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/25 15:46:28 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	sa(t_ps **a, int flag, t_ps **res)
{
	t_ps	*ptr;

	ptr = *a;
	if (ptr && ptr->next)
	{
		ft_swap(&ptr->value, &ptr->next->value);
		if (flag == 1)
			ft_lstadd_back_ps(res, 0, "sa");
		return (1);
	}
	return (0);
}

int	sb(t_ps **b, int flag, t_ps **res)
{
	t_ps	*ptr;

	ptr = *b;
	if (ptr && ptr->next)
	{
		ft_swap(&ptr->value, &ptr->next->value);
		if (flag == 1)
			ft_lstadd_back_ps(res, 0, "sb");
		return (1);
	}
	return (0);
}

int	pa(t_ps **a, t_ps **b, t_ps **res)
{
	int		value;

	if ((*b) && b)
	{
		value = (*b)->value;
		ft_lstadd_front_ps(a, value, "");
		ft_lstdel_front_ps(b);
		ft_lstadd_back_ps(res, 0, "pa");
		return (1);
	}
	return (0);
}

int	pb(t_ps **a, t_ps **b, t_ps **res)
{
	int		value;

	if ((*a) && a)
	{
		value = (*a)->value;
		ft_lstadd_front_ps(b, value, "");
		ft_lstdel_front_ps(a);
		ft_lstadd_back_ps(res, 0, "pb");
		return (1);
	}
	return (0);
}
