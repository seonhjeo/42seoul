/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipe.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 12:48:49 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 18:17:32 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void ft_pipe(t_tree *node)
{
	pid_t pid;
	int fd[2];
	int stdin_copy = dup(0);
	int stdout_copy = dup(1);

	if (node->cmd_type == L_PIPE && node->right)
	{
		pipe(fd);
		pid = fork();
		if (!pid)
		{
			g_data.head = node->left;
			dup2(fd[1], STDOUT);
			close(fd[1]);
			close(fd[0]);
			tree_traversal(node->left);
			exit(0);
		}
		g_data.head = node->right;
		dup2(fd[0], STDIN);
		close(fd[1]);
		waitpid(pid, NULL, 0);
		tree_traversal(node->right);
		close(fd[0]);
		dup2(stdin_copy, STDIN);
		dup2(stdout_copy, STDOUT);
		close(stdin_copy);
		close(stdout_copy);
	}
	else
	{
		g_data.head = g_data.tree;
		tree_traversal(node);
	}
}
