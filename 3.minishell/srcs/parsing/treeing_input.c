/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   treeing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/30 10:37:30 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/05 14:29:50 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	make_tree(t_token *token)
{
	t_token	*tk;
	int		trigger;
	t_tree	*buff;
	t_tree	*pipe;

	trigger = 0;
	buff = NULL;
	pipe = NULL;
	tk = token;
	add_pipe(&trigger, &buff, &pipe);
	while (tk)
	{
		if (trigger != L_PIPE && tk->l_type == L_PIPE)
			add_pipe(&trigger, &buff, &pipe);
		if (trigger == L_PIPE && tk->l_type == L_FPATH)
			add_cmd(tk, &trigger, &buff);
		if ((trigger == L_FPATH || trigger == L_REDIR_TK)
			&& tk->l_type == L_REDIR_TK)
			add_redir(tk, &trigger, &buff);
		if (trigger == L_PIPE && tk->l_type == L_REDIR_TK)
			add_redir_p(tk, &trigger, &buff);
		tk = tk->next;
	}
}

void	check_lexical_type(t_token *token)
{
	t_token	*temp;

	temp = token;
	while (temp)
	{
		if (temp->type == T_PIPE)
			temp->l_type = L_PIPE;
		else if (temp->type == T_REDIRECT)
			temp->l_type = L_REDIR_TK;
		else
		{
			if (!temp->prev)
				temp->l_type = L_FPATH;
			else if (temp->prev->l_type == L_PIPE)
				temp->l_type = L_FPATH;
			else if (temp->prev->l_type == L_REDIR_TK
				|| temp->prev->l_type == L_RFNAME)
				temp->l_type = L_RFNAME;
			else
				temp->l_type = L_ARGS;
		}
		temp = temp->next;
	}
}

void	treeing_input(t_token *token)
{
	t_token	*temp;

	g_data.tree = NULL;
	check_lexical_type(token);
	temp = token;
	make_tree(token);
}
