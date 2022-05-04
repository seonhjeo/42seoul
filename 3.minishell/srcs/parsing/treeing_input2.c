/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeing_input2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/04 17:13:03 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/06 15:36:50 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	add_pipe(int *trigger, t_tree **buff, t_tree **pipe)
{
	t_tree	*temp;

	temp = make_node(L_PIPE, NULL);
	add_child_left_node(&temp, L_CMD, NULL);
	if (*pipe == NULL)
		g_data.tree = temp;
	else
		(*pipe)->right = temp;
	*trigger = L_PIPE;
	*buff = temp->left;
	*pipe = temp;
}

void	add_cmd(t_token *tk, int *trigger, t_tree **buff)
{
	t_tree	*temp;
	char	*args;
	t_token	*ttem;

	ttem = tk->next;
	args = ft_strdup(tk->str);
	while (ttem && ttem->l_type == L_ARGS)
	{
		args = ft_strjoin_token(args, " ");
		args = ft_strjoin_token(args, ttem->str);
		ttem = ttem->next;
	}
	temp = *buff;
	add_child_left_node(&temp, L_REDIR, NULL);
	add_child_right_node(&temp, L_SIMPLE_CMD, NULL);
	*trigger = L_FPATH;
	*buff = temp->left;
	temp = temp->right;
	add_child_left_node(&temp, L_FPATH, tk->str);
	add_child_right_node(&temp, L_ARGV, args);
}

void	add_redir(t_token *tk, int *trigger, t_tree **buff)
{
	t_tree	*temp;
	char	*args;
	t_token	*ttem;

	ttem = tk->next;
	args = ft_strdup("");
	while (ttem && ttem->l_type == L_RFNAME)
	{
		args = ft_strjoin_token(args, ttem->str);
		if (ttem->next)
			args = ft_strjoin_token(args, " ");
		ttem = ttem->next;
	}
	temp = *buff;
	add_child_left_node(&temp, L_IO_REDIR, NULL);
	add_child_right_node(&temp, L_REDIR, NULL);
	*trigger = L_REDIR_TK;
	*buff = temp->right;
	temp = temp->left;
	add_child_left_node(&temp, L_REDIR_TK, tk->str);
	add_child_right_node(&temp, L_RFNAME, args);
}

void	add_redir_p(t_token *tk, int *trigger, t_tree **buff)
{
	t_tree	*temp;
	char	*args;
	t_token	*ttem;

	ttem = tk->next;
	args = ft_strdup("");
	while (ttem && ttem->l_type == L_RFNAME)
	{
		args = ft_strjoin_token(args, ttem->str);
		args = ft_strjoin_token(args, " ");
		ttem = ttem->next;
	}
	temp = *buff;
	add_child_left_node(&temp, L_REDIR, NULL);
	add_child_right_node(&temp, L_SIMPLE_CMD, NULL);
	temp = temp->left;
	add_child_left_node(&temp, L_IO_REDIR, NULL);
	add_child_right_node(&temp, L_REDIR, NULL);
	*trigger = L_REDIR_TK;
	*buff = temp->right;
	temp = temp->left;
	add_child_left_node(&temp, L_REDIR_TK, tk->str);
	add_child_right_node(&temp, L_RFNAME, args);
}
