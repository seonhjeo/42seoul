/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 11:47:05 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/08 09:17:42 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_tree(t_tree *tree)
{
	if (tree)
	{
		if (tree->left)
			free_tree(tree->left);
		if (tree->right)
			free_tree(tree->right);
		free(tree->str);
		tree->str = NULL;
		free(tree);
		tree = NULL;
	}
}

void	check_tree(t_tree *tree)
{
	printf("[%d], [%s]\n", tree->cmd_type, tree->str);
	if (tree->left)
		check_tree(tree->left);
	if (tree->right)
		check_tree(tree->right);
}

int	main(int argc, char **argv, char **envp)
{
	char *input;
	int res;

	(void)argv;
	set_signal();
	if (!init_data(envp))
		return (0);
	if (!init_param(argv))
		return (0);
	res = argc;
	while (res)
	{
		g_data.error_code = -1;
		res = get_command(&input);
		if (g_data.error_code == CTRL_D)
			break ;
		// check_tree(g_data.tree);
		if (g_data.error_code == -1)
			ft_pipe(g_data.tree);
		free_tree(g_data.tree);
	}
	return (0);
}
