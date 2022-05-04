/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_documents.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hyenam <hyenam@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 15:31:37 by hyenam            #+#    #+#             */
/*   Updated: 2022/01/07 18:34:02 by hyenam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_tree *make_temp_node()
{
	t_tree *temp;
	t_tree *left;
	t_tree *right;
	char *str;
	char *temp2;

	str = ft_strjoin("", g_data.next_cmd->left->str);
	temp2 = ft_strjoin(str, " ");
	str = ft_strjoin(temp2, TEMPFILE);
	temp = make_node(L_SIMPLE_CMD, "");
	left = make_node(L_FPATH, g_data.next_cmd->left->str);
	right = make_node(L_ARGV, str);
	temp->left = left;
	temp->right = right;
	return (temp);
}

void write_file(t_tree *node)
{
	char *input;
	int flag;
	int fd;

	fd = open(TEMPFILE, O_WRONLY | O_CREAT | O_TRUNC, 0777);
	flag = 1;
	while (flag)
	{
		input = readline("> ");
		if (ft_strlen(input) == ft_strlen(node->str) &&
			ft_strncmp(input, node->str, ft_strlen(node->str)) == 0)
			flag = 0;
		else
		{
			write(fd, input, ft_strlen(input));
			write(fd, "\n", 1);
			flag = 1;
		}
		free(input);
	}
	close(fd);
}

int here_documents(t_tree *node)
{
	int fd;

	write_file(node->right);
	fd = open(node->str, O_RDONLY);
	dup2(fd, STDIN);
	if (!exe_builtin(g_data.next_cmd))
		if (!ft_cmd(make_temp_node()))
		{
			unlink(TEMPFILE);
			close(fd);
			return (127);
		}
	unlink(TEMPFILE);
	close(fd);
	return (0);
}
