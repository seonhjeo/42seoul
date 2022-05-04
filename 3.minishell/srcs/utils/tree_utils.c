/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tree_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 16:49:21 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/05 15:43:46 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree	*make_node(int l_type, char *str)
{
	t_tree	*temp;

	temp = (t_tree *)malloc(sizeof(t_tree));
	if (!temp)
	{
		g_data.error_code = 12;
		return (NULL);
	}
	temp->root = NULL;
	temp->left = NULL;
	temp->right = NULL;
	temp->cmd_type = l_type;
	temp->done = 0;
	temp->str = str;
	return (temp);
}

int	add_root_left_node(t_tree **head,int l_type, char *str)
{
	t_tree	*new;

	new = make_node(l_type, str);
	if (!new)
		return (FUNC_FAIL);
	if (!*head)
		*head = new;
	else if (head && *head)
	{
		(*head)->root = new;
		new->left = *head;
		*head = new;
	}
	return (FUNC_SUC);
}


int	add_root_right_node(t_tree **head, int l_type, char *str)
{
	t_tree	*new;

	new = make_node(l_type, str);
	if (!new)
		return (FUNC_FAIL);
	if (!*head)
		*head = new;
	else if (head && *head)
	{
		(*head)->root = new;
		new->right = *head;
		*head = new;
	}
	return (FUNC_SUC);
}

int	add_child_left_node(t_tree **head, int l_type, char *str)
{
	t_tree	*new;

	new = make_node(l_type, str);
	if (!new)
		return (FUNC_FAIL);
	if (!*head)
		*head = new;
	else if (head && *head)
	{
		new->root = *head;
		(*head)->left = new;
	}
	return (FUNC_SUC);
}

int	add_child_right_node(t_tree **head, int l_type, char *str)
{
	t_tree	*new;

	new = make_node(l_type, str);
	if (!new)
		return (FUNC_FAIL);
	if (!*head)
		*head = new;
	else if (head && *head)
	{
		new->root = *head;
		(*head)->right = new;
	}
	return (FUNC_SUC);
}
