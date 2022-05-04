/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/24 09:33:04 by seonhjeo          #+#    #+#             */
/*   Updated: 2021/10/26 12:51:04 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	ft_swap(int *a, int *b)
{
	int		temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

int	ft_lstadd_back_ps(t_ps **lst, int value, char *command)
{
	t_ps	*ptr;
	t_ps	*new;

	new = (t_ps *)malloc(sizeof(t_ps));
	if (!new)
		return (ERROR);
	new->prev = 0;
	new->value = value;
	new->command = command;
	new->next = 0;
	if (!*lst)
		*lst = new;
	else if (lst && *lst)
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		new->prev = ptr;
		ptr->next = new;
	}
	return (SUCCESS);
}

int	ft_lstadd_front_ps(t_ps **lst, int value, char *command)
{
	t_ps	*ptr;
	t_ps	*new;

	new = (t_ps *)malloc(sizeof(t_ps));
	if (!new)
		return (ERROR);
	new->prev = 0;
	new->value = value;
	new->command = command;
	new->next = 0;
	if (!*lst)
		*lst = new;
	else if (lst && *lst)
	{
		ptr = *lst;
		new->next = ptr;
		ptr->prev = new;
		*lst = new;
	}
	return (SUCCESS);
}

void	ft_lstdel_back_ps(t_ps **lst)
{
	t_ps	*ptr;

	if (!lst || !(*lst))
		return ;
	else if (!(*lst)->next)
	{
		free((*lst));
		*lst = 0;
	}
	else
	{
		ptr = *lst;
		while (ptr->next)
			ptr = ptr->next;
		ptr->prev->next = 0;
		free(ptr);
	}
}

void	ft_lstdel_front_ps(t_ps **lst)
{
	t_ps	*ptr;

	if (!lst || !(*lst))
		return ;
	else if (!(*lst)->next)
	{
		free((*lst));
		*lst = 0;
	}
	else
	{
		ptr = *lst;
		ptr->next->prev = 0;
		*lst = ptr->next;
		free(ptr);
	}
}
