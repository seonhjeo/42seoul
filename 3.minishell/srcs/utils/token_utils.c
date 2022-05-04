/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seonhjeo <seonhjeo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/21 11:23:30 by seonhjeo          #+#    #+#             */
/*   Updated: 2022/01/03 11:28:34 by seonhjeo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	init_token_value(t_token *token, int type, char *str)
{
	token->prev = 0;
	token->next = 0;
	token->type = type;
	token->str = str;
	token->l_type = 0;
}

int	add_token_back(t_token **token, int type, char *str)
{
	t_token	*ptr;
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (FUNC_FAIL);
	init_token_value(new, type, str);
	if (!*token)
		*token = new;
	else if (token && *token)
	{
		ptr = *token;
		while (ptr->next)
			ptr = ptr->next;
		new->prev = ptr;
		ptr->next = new;
	}
	return (FUNC_SUC);
}

int	add_token_front(t_token **token, int type, char *str)
{
	t_token	*ptr;
	t_token	*new;

	new = (t_token *)malloc(sizeof(t_token));
	if (!new)
		return (FUNC_FAIL);
	init_token_value(new, type, str);
	if (!*token)
		*token = new;
	else if (token && *token)
	{
		ptr = *token;
		new->next = ptr;
		ptr->prev = new;
		*token = new;
	}
	return (FUNC_SUC);
}

void	del_token_back(t_token **token)
{
	t_token	*ptr;

	if (!token || !(*token))
		return ;
	else if (!(*token)->next)
	{
		free((*token)->str);
		free((*token));
		*token = 0;
	}
	else
	{
		ptr = *token;
		while (ptr->next)
			ptr = ptr->next;
		ptr->prev->next = 0;
		free(ptr->str);
		free(ptr);
	}
}

void	del_token_front(t_token **token)
{
	t_token	*ptr;

	if (!token || !(*token))
		return ;
	else if (!(*token)->next)
	{
		free((*token)->str);
		free((*token));
		*token = 0;
	}
	else
	{
		ptr = *token;
		ptr->next->prev = 0;
		*token = ptr->next;
		free(ptr->str);
		free(ptr);
	}
}
