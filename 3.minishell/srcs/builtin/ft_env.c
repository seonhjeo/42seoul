/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 13:21:21 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 17:22:53 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void get_home_path(void)
{
	char *data;

	data = get_env_data("HOME");
	if (!data)
		return;
	g_data.env_list->home_path = ft_strdup(data);
	free(data);
}

int get_all_env(char **envp)
{
	int len;
	int i;

	len = 0;
	i = -1;
	while (envp[++i])
		len++;
	g_data.env_list = (t_env_list *)malloc(sizeof(t_env_list));
	if (!g_data.env_list)
		return (0);
	g_data.env_list->head = NULL;
	g_data.env_list->tail = NULL;
	g_data.env_list->home_path = NULL;
	g_data.env_list->len = 0;
	i = -1;
	while (envp[++i])
		add_env_node(g_data.env_list, envp[i]);
	get_home_path();
	return (FUNC_SUC);
}

void env_error(t_tree *node)
{
	char **temp;

	temp = ft_split(node->str, ' ');
	ft_builtin_err("env", temp[1], 2);
	free_str(temp);
	g_data.exit_code = 127;
}

void ft_env(t_tree *n, int option)
{
	t_env_node *node;
	int i;

	if (option == 0 && ft_strlen(n->str) > 3)
	{
		env_error(n);
		return ;
	}
	i = g_data.env_list->len;
	node = g_data.env_list->head;
	while (i)
	{
		if (option)
			ft_putstr_fd("declare -x ", STDOUT);
		ft_putstr_fd(node->data, STDOUT);
		ft_putstr_fd("\n", STDOUT);
		node = node->next;
		i--;
	}
	g_data.exit_code = 0;
}