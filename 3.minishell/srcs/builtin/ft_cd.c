/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 14:25:48 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 16:16:28 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void edit_path_env(char *old_path)
{
	char new_path[BUFFER_SIZE];

	getcwd(new_path, BUFFER_SIZE);
	change_node_data("PWD", new_path);
	change_node_data("OLDPWD", old_path);
}

void ft_cd(t_tree *node)
{
	char **new_path;
	char old_path[BUFFER_SIZE];

	if (g_data.delete_home)
	{
		ft_custom_err("cd", "HOME not set");
		g_data.delete_home = 0;
		return;
	}
	getcwd(old_path, BUFFER_SIZE);
	new_path = ft_split(node->str, ' ');
	if (!new_path[1] || new_path[1][0] == '~')
		chdir(g_data.env_list->home_path);
	else if (chdir(new_path[1]) != 0)
	{
		ft_builtin_err("cd", new_path[1], 2);
		return;
	}
	edit_path_env(old_path);
	g_data.exit_code = 0;
	free_str(new_path);
}
