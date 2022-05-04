/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:41:34 by hyenam            #+#    #+#             */
/*   Updated: 2021/12/21 17:01:06 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int add_env_node(t_env_list *list, char *data)
{
	t_env_node *node;

	node = (t_env_node *)malloc(sizeof(t_env_node));
	if (!node)
		return (ft_strerror_exit("Error: Allocating env_list error"));
	node->data = (char *)malloc(sizeof(char) * (ft_strlen(data) + 1));
	ft_strlcpy(node->data, data, ft_strlen(data) + 1);
	if (list->head == NULL && list->tail == NULL)
	{
		list->head = node;
		list->tail = node;
	}
	else
	{
		list->tail->next = node;
		list->tail = node;
		node->next = NULL;
	}
	list->len++;
	return (FUNC_SUC);
}

int search_env_node(t_env_list *list, char *data)
{
	t_env_node *node;
	char **temp;
	int pos;

	pos = 1;
	node = list->head;
	temp = ft_split(node->data, '=');
	while (ft_strncmp(temp[0], data, ft_strlen(data) + 1) != 0 && node->next != NULL)
	{
		node = node->next;
		temp = ft_split(node->data, '=');
		pos++;
	}
	if (ft_strncmp(node->data, data, ft_strlen(data)) != 0 && node == list->tail)
		pos = -1;
	free_str(temp);
	return (pos);
}

void delete_env_node(t_env_list *list, char *data)
{
	int pos;

	pos = search_env_node(list, data);
	if (pos > 0 && pos < g_data.env_list->len)
		delete_middle_env_node(list, pos);
	else if (pos != -1)
		delete_end_env_node(list, pos);
}

void delete_middle_env_node(t_env_list *list, int pos)
{
	t_env_node *node;
	t_env_node *temp;

	node = list->head;
	--pos;
	while (--pos)
		node = node->next;
	temp = node->next;
	node->next = node->next->next;
	free(temp);
	list->len--;
}

void delete_end_env_node(t_env_list *list, int pos)
{
	t_env_node *node;
	t_env_node *temp;

	node = list->head;
	if (!pos)
	{
		list->head = node->next;
		free(node);
	}
	else
	{
		while (node->next != list->tail)
			node = node->next;
		temp = list->tail;
		list->tail = node;
		node->next = NULL;
		free(temp);
	}
	list->len--;
}
