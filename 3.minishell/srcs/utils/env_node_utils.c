/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_node_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 17:53:44 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 16:11:14 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char *get_env_data(char *name)
{
	t_env_node *node;
	char **temp;
	char *res;
	int pos;

	node = g_data.env_list->head;
	if (name[0] == '?')
	{
		res = ft_itoa(g_data.exit_code);
		return (res);
	}
	pos = search_env_node(g_data.env_list, name);
	if (!ft_strncmp(name, "HOME", ft_strlen(name)) && pos == -1)
		g_data.delete_home = 1;
	else
		g_data.delete_home = 0;
	if (pos == -1)
		return(0);
	while (--pos)
		node = node->next;
	temp = ft_split(node->data, '=');
	res = ft_strdup(temp[1]);
	free_str(temp);
	return (res);
}

void change_node_data(char *name, char *data)
{
	t_env_node *node;
	char **temp;
	int pos;

	node = g_data.env_list->head;
	pos = search_env_node(g_data.env_list, name);
	while (--pos)
		node = node->next;
	temp = ft_split(node->data, '=');
	ft_strlcat(temp[0], "=", ft_strlen(temp[0]) + 2);
	ft_strlcat(temp[0], data, ft_strlen(data) + ft_strlen(temp[0]) + 1);
	ft_strlcpy(node->data, temp[0], ft_strlen(temp[0]) + 1);
	free_str(temp);
}
